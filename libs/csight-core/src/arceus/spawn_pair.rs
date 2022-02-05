use super::spawn::Spawn;
use no_std_io::Reader;
use safe_transmute::TriviallyTransmutable;

#[derive(Debug, Clone, Copy)]
pub struct SpawnPair {
    data: [u8; Self::DATA_SIZE],
}

impl SpawnPair {
    pub const DATA_SIZE: usize = 0x80;

    pub fn get_spawner_0(&self) -> Spawn {
        self.default_read(0)
    }

    pub fn get_spawner_1(&self) -> Spawn {
        self.default_read(Spawn::DATA_SIZE)
    }
}

impl Default for SpawnPair {
    fn default() -> Self {
        Self {
            data: [0; Self::DATA_SIZE],
        }
    }
}

impl Reader for SpawnPair {
    fn get_slice(&self) -> &[u8] {
        &self.data
    }
}

unsafe impl TriviallyTransmutable for SpawnPair {}
