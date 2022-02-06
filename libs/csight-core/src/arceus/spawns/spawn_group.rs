use super::spawn_pair::SpawnPair;
use no_std_io::Reader;
use safe_transmute::TriviallyTransmutable;

#[derive(Debug, Clone, Copy)]
pub struct SpawnGroup {
    data: [u8; Self::DATA_SIZE],
}

impl SpawnGroup {
    pub const DATA_SIZE: usize = 0x440;

    fn get_spawn_pair(&self, index: usize) -> SpawnPair {
        if index > 7 {
            return SpawnPair::default();
        }

        self.default_read(index * SpawnPair::DATA_SIZE)
    }

    pub fn get_spawn_pair_seeds(&self, index: usize) -> (u64, u64) {
        let pair = self.get_spawn_pair(index);
        (
            pair.get_spawner_0().get_seed(),
            pair.get_spawner_1().get_seed(),
        )
    }

    pub fn get_seed(&self) -> u64 {
        self.default_read(0x408)
    }
}

impl Default for SpawnGroup {
    fn default() -> Self {
        Self {
            data: [0; Self::DATA_SIZE],
        }
    }
}

impl Reader for SpawnGroup {
    fn get_slice(&self) -> &[u8] {
        &self.data
    }
}

unsafe impl TriviallyTransmutable for SpawnGroup {}

mod c_api {
    use super::*;
    use alloc::boxed::Box;

    #[no_mangle]
    pub unsafe extern "C" fn free_spawn_group(ptr: *mut SpawnGroup) {
        if ptr.is_null() {
            return;
        }

        Box::from_raw(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn spawn_group_get_seed(ptr: *mut SpawnGroup) -> u64 {
        assert!(!ptr.is_null());
        let spawn_group = &*ptr;
        spawn_group.get_seed()
    }

    #[no_mangle]
    pub unsafe extern "C" fn spawn_group_get_spawn_pair_seeds(
        ptr: *mut SpawnGroup,
        seed0: *mut u64,
        seed1: *mut u64,
        index: usize,
    ) {
        assert!(!ptr.is_null());
        let spawn_group = &*ptr;
        let (read_seed0, read_seed1) = spawn_group.get_spawn_pair_seeds(index);
        *seed0 = read_seed0;
        *seed1 = read_seed1;
    }
}
