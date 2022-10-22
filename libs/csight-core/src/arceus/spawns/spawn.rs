#[cfg(test)]
use no_std_io::Writer;

use no_std_io::{EndianRead, EndianWrite, Reader};

#[derive(Debug, Clone, Copy, PartialEq, EndianWrite, EndianRead)]
pub struct Spawn {
    data: [u8; Self::DATA_SIZE],
}

impl Spawn {
    pub const DATA_SIZE: usize = 0x38;
    const IS_ACTIVE_OFFSET: usize = 0xb;
    const SEED_OFFSET: usize = 0x20;

    pub fn get_is_active(&self) -> bool {
        self.default_read::<u8>(Self::IS_ACTIVE_OFFSET) & 1 == 0
    }

    pub fn get_seed(&self) -> u64 {
        self.default_read_le(Self::SEED_OFFSET)
    }

    #[cfg(test)]
    pub fn set_is_active(&mut self, is_active: bool) {
        // During tests we'll panic if data isn't set up correctly
        let flag = (is_active as u8) ^ 1;
        self.write(Self::IS_ACTIVE_OFFSET, &flag).unwrap();
    }
}

impl Default for Spawn {
    fn default() -> Self {
        Self {
            data: [0; Self::DATA_SIZE],
        }
    }
}

impl Reader for Spawn {
    fn get_slice(&self) -> &[u8] {
        &self.data
    }
}

#[cfg(test)]
impl Writer for Spawn {
    fn get_mut_slice(&mut self) -> &mut [u8] {
        &mut self.data
    }
}

#[cfg(test)]
mod test {
    use super::*;

    const ACTIVE_SPAWN: Spawn = Spawn {
        data: [
            0x15, 0x79, 0x47, 0x42, 0x93, 0x37, 0x40, 0x42, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01,
            0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0xa7, 0x57, 0xdb, 0xe0, 0x86, 0xe9, 0x9f, 0xb2, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        ],
    };

    const INACTIVE_SPAWN: Spawn = Spawn {
        data: [
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
            0x00, 0x00, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        ],
    };

    mod get_seed {
        use super::*;

        #[test]
        fn should_get_seed() {
            assert_eq!(ACTIVE_SPAWN.get_seed(), 0xb29fe986e0db57a7);
            assert_eq!(INACTIVE_SPAWN.get_seed(), 0);
        }
    }

    mod get_is_active {
        use super::*;

        #[test]
        fn should_read_active() {
            assert_eq!(ACTIVE_SPAWN.get_is_active(), true);
        }

        #[test]
        fn should_read_inactive() {
            assert_eq!(INACTIVE_SPAWN.get_is_active(), false);
        }
    }
}
