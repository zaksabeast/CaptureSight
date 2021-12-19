use super::Rng;

pub type XorshiftState = [u32; 4];

#[derive(Clone, Copy, Debug)]
pub struct Xorshift {
    state: XorshiftState,
}

impl Rng for Xorshift {
    type State = XorshiftState;

    fn from_state(state: Self::State) -> Self {
        Self { state }
    }

    fn set_state(&mut self, state: Self::State) {
        self.state = state;
    }

    fn get_state(&self) -> Self::State {
        self.state
    }

    fn next(&mut self) -> u32 {
        let s0 = self.state[0];
        self.state[0] = self.state[1];
        self.state[1] = self.state[2];
        self.state[2] = self.state[3];

        let tmp = s0 ^ s0 << 11;
        let tmp = tmp ^ tmp >> 8 ^ self.state[2] ^ self.state[2] >> 19;

        self.state[3] = tmp;

        (tmp % 0xffffffff).wrapping_add(0x80000000)
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use alloc::vec;

    #[test]
    fn should_generate_u32s() {
        let mut rng = Xorshift::from_state([0xaabbccdd, 0xaabbccdd, 0x11223344, 0x11223344]);
        let expected_results = vec![
            0xe58bc899, 0x91223dd1, 0x919a94a2, 0x91223dc6, 0xaad6f07b, 0xaa1a8c45, 0x6fe03220,
            0x6f2cee17, 0xf2e48ea1, 0x0c625c1c, 0xe2fd0e82, 0x6a29089c, 0x3cee02fe, 0xa2f22bc3,
            0x28f1b801, 0x8a3e286b, 0x460b2220, 0xf514a511, 0xd0002a02, 0x2b862d19, 0xb403006b,
            0x64ef17d7, 0x35ee6172, 0xaf9a7c33, 0x83b621f3, 0x1f7bdffd, 0xd958d891, 0x25df4c6d,
            0x97d4589c, 0xd611e9ac, 0x49122faf, 0x16f1aec4, 0xa354143e, 0x7ad1c571, 0x22e6e2d3,
            0x397affc5, 0xba0cf930, 0xce82494d, 0x5be7ca34, 0x350d825a, 0x689528b2, 0x3401dccc,
            0xd1521612, 0x08945130, 0x49052828, 0xf3586a78, 0x327b0087, 0x184cda29, 0xf8e8e560,
            0x48534baf, 0x2246151a, 0xdc250ee9, 0xe3d923e8, 0xb185120f, 0x23f93fe0, 0x57df3f30,
            0xfdb38040, 0xe4bff093, 0x8ed3c5db, 0xa0db5d8e, 0x418b6855, 0xda2b239f, 0x4a46c81c,
            0xb08bcbf7, 0x2ad8c473, 0x29ec3d6c, 0xd5160665, 0xbbacab43, 0xd73b0b19, 0x1ff45bcf,
            0xfa34437a, 0xa49c09cc, 0x2b70ad85, 0x1667b107, 0xce901f22, 0x0a86ad55, 0x24b42505,
            0x8ff0571d, 0x415730ce, 0xfe04c1b4, 0xfb9d5f7c, 0x7658a7ad, 0x0ef128e8, 0x56a051e3,
            0xc75792f4, 0xf401307c, 0xf3b0e07c, 0x274b88a0, 0xdc706e8f, 0xa18f37ad, 0x55c880e0,
            0xae3d1c71, 0x71e60b2f, 0x298c78e1, 0xb8d222b0, 0x7eca6f4f, 0xbfb4bcca, 0x753580ad,
            0xdc5bfb19, 0x714657ca,
        ];

        for rand in expected_results {
            assert_eq!(rng.next(), rand);
        }
    }
}
