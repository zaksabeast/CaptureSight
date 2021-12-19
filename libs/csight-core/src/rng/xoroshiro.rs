use super::Rng;

type XoroshiroState = [u64; 2];

#[derive(Clone, Copy, PartialEq, Debug)]
pub struct Xoroshiro {
    state: XoroshiroState,
}

impl Rng for Xoroshiro {
    type State = XoroshiroState;

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
        self.next_u64() as u32
    }
}

impl Xoroshiro {
    pub fn new(seed: u64) -> Self {
        Self {
            state: [seed, 0x82A2B175229D6A5B],
        }
    }

    pub fn next_u64(&mut self) -> u64 {
        let result = self.state[0].wrapping_add(self.state[1]);

        self.state[1] ^= self.state[0];
        self.state[0] = self.state[0].rotate_left(24) ^ self.state[1] ^ (self.state[1] << 16);
        self.state[1] = self.state[1].rotate_left(37);

        result
    }
}

#[cfg(test)]
mod test {
    use super::*;
    use alloc::vec;

    #[test]
    fn should_generate_u64s() {
        let mut rng = Xoroshiro::new(0x1122334455667788);
        let expected_results = vec![
            0x93c4e4b97803e1e3,
            0x55484e305249860e,
            0x83d9bcae5c97d74f,
            0x8476e8b6137d6fb8,
            0xc12bc824ffa7d32e,
            0x1099312a9cafe83c,
            0xf87ffd516703b2a8,
            0xc53ce8f6fa44b86,
            0x7ca6285d953f1fdd,
            0x50d49c298d78970,
            0xf6d1801703a1bec0,
            0xb238e78b4f0daf2c,
            0xa574eb709549db32,
            0x5f9b1eaa8218596a,
            0x127bac944a3af5f4,
            0x2a262daf54cdcfab,
            0xb3593531b4334a14,
            0x96c928e9ec1cd2d4,
            0x8f3acc5cb0050283,
            0x3c51743b7d4a66d,
            0x2035fcf124ddc7e0,
            0x5fc7683efde0660e,
            0xce91efc07c493e8a,
            0x9cf8eadbf8b312e,
            0x20273e38e74738e5,
            0xd43c3f8edea66c01,
            0x1a68eb7f8abf9ba8,
            0x134589b419a374e1,
            0x12f7e745f9abdc67,
            0x83caf90180373fa0,
            0xaca070eb88c006df,
            0x40ee1eeb640118a2,
            0xa5d77283a0072885,
            0x10cab83b95843c28,
            0xe7e2e78a0b232c61,
            0xf895c6aa797c9b52,
            0xb136aff432a26d20,
            0xff67986fce54b70c,
            0x6d18251a5bea4692,
            0x8689a0f60a2ab6d5,
            0x2981615619abb11f,
            0xd3b9df4f17c6db00,
            0x15120036852cb7bb,
            0x8e2d6adc0c2e4fee,
            0x315712c853451e21,
            0xf9d480c455eaa7a7,
            0x400dfa3000d02d42,
            0x81747dde8fc687b6,
            0x8c09a33a7a91aa52,
            0x2c4631678bc5d5be,
            0xd6128958eb7b943c,
            0x4358154ec95f7731,
            0xe793a833f25632e6,
            0x4f84c6bfc285df95,
            0x7a3e1f03b10d27bc,
            0x942491f663e10111,
            0x2a5d4416e41b186,
            0xb393449246e2d6c0,
            0x2b26ac29fbab904a,
            0x4db820ca30c3b7dd,
            0x6f875559cce74acf,
            0x549013629e372bfe,
            0xb7115181c6b7632e,
            0x60340682c744d8af,
            0x478479b30ebb1c92,
            0x558633def22cee62,
            0x26763963e62f246f,
            0x74ae242e4d95b63d,
            0x70146633cd8ceba8,
            0x928cbaf6fbae91e9,
            0xc8799f504feb234e,
            0x5aaa1a2ee74dd797,
            0xe374488550b5889d,
            0x1b26f7d1031b2386,
            0xcd7a0e036188d201,
            0xa720ffcefcb66795,
            0xa942df309aaf2e70,
            0x6d4a5ea88142269e,
            0xbf291e247bcc4ab8,
            0xaf68274ab0d3aaa4,
            0xf23b22007f8a106a,
            0x1308f08c245a1ac3,
            0x591cc9df482a0057,
            0x976973a62fc9435b,
            0x55df47cd992f5fce,
            0x525a2f24e06a693b,
            0x9c505b57f5578719,
            0xff3e6157d6ffb524,
            0x65d650ec5e117c88,
            0xf64b8b4fd1957f5b,
            0x34c0c011fcd24cb2,
            0xbcb20ed74a3335ea,
            0x570cf297bcbc441c,
            0x3e4a4847d9650a13,
            0xeea953e73cc3f1b,
            0xaec04ebcab60bec5,
            0xf5d2eed87d74002,
            0x879c939f80810645,
            0xfa58fffa71b0651d,
            0x79128863d624f7ba,
        ];

        for rand in expected_results {
            assert_eq!(rng.next_u64(), rand);
        }
    }

    #[test]
    fn should_generate_u32s() {
        let mut rng = Xoroshiro::new(0x1122334455667788);
        let expected_results = vec![
            0x7803e1e3, 0x5249860e, 0x5c97d74f, 0x137d6fb8, 0xffa7d32e, 0x9cafe83c, 0x6703b2a8,
            0x6fa44b86, 0x953f1fdd, 0x98d78970, 0x3a1bec0, 0x4f0daf2c, 0x9549db32, 0x8218596a,
            0x4a3af5f4, 0x54cdcfab, 0xb4334a14, 0xec1cd2d4, 0xb0050283, 0xb7d4a66d, 0x24ddc7e0,
            0xfde0660e, 0x7c493e8a, 0xbf8b312e, 0xe74738e5, 0xdea66c01, 0x8abf9ba8, 0x19a374e1,
            0xf9abdc67, 0x80373fa0, 0x88c006df, 0x640118a2, 0xa0072885, 0x95843c28, 0xb232c61,
            0x797c9b52, 0x32a26d20, 0xce54b70c, 0x5bea4692, 0xa2ab6d5, 0x19abb11f, 0x17c6db00,
            0x852cb7bb, 0xc2e4fee, 0x53451e21, 0x55eaa7a7, 0xd02d42, 0x8fc687b6, 0x7a91aa52,
            0x8bc5d5be, 0xeb7b943c, 0xc95f7731, 0xf25632e6, 0xc285df95, 0xb10d27bc, 0x63e10111,
            0x6e41b186, 0x46e2d6c0, 0xfbab904a, 0x30c3b7dd, 0xcce74acf, 0x9e372bfe, 0xc6b7632e,
            0xc744d8af, 0xebb1c92, 0xf22cee62, 0xe62f246f, 0x4d95b63d, 0xcd8ceba8, 0xfbae91e9,
            0x4feb234e, 0xe74dd797, 0x50b5889d, 0x31b2386, 0x6188d201, 0xfcb66795, 0x9aaf2e70,
            0x8142269e, 0x7bcc4ab8, 0xb0d3aaa4, 0x7f8a106a, 0x245a1ac3, 0x482a0057, 0x2fc9435b,
            0x992f5fce, 0xe06a693b, 0xf5578719, 0xd6ffb524, 0x5e117c88, 0xd1957f5b, 0xfcd24cb2,
            0x4a3335ea, 0xbcbc441c, 0xd9650a13, 0x73cc3f1b, 0xab60bec5, 0x87d74002, 0x80810645,
            0x71b0651d, 0xd624f7ba,
        ];

        for rand in expected_results {
            assert_eq!(rng.next(), rand);
        }
    }
}
