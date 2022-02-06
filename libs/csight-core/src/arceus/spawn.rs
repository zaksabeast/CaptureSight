use no_std_io::Reader;
use safe_transmute::TriviallyTransmutable;

#[derive(Debug, Clone, Copy)]
pub struct Spawn {
    data: [u8; Self::DATA_SIZE],
}

impl Spawn {
    pub const DATA_SIZE: usize = 0x38;

    pub fn get_seed(&self) -> u64 {
        self.default_read(0x20)
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

unsafe impl TriviallyTransmutable for Spawn {}
