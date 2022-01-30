use no_std_io::Reader;
use safe_transmute::TriviallyTransmutable;

#[derive(Debug, Clone, Copy)]
pub struct Spawn {
    data: [u8; Self::DATA_SIZE],
}

impl Spawn {
    pub const DATA_SIZE: usize = 0x80;

    pub fn get_hash(&self) -> u64 {
        self.default_read(0)
    }

    pub fn get_seed(&self) -> u64 {
        self.default_read(0x20)
    }

    pub fn get_is_active(&self) -> bool {
        self.get_seed() != 0
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

mod c_api {
    use super::*;
    use alloc::boxed::Box;

    #[no_mangle]
    pub unsafe extern "C" fn free_spawn(ptr: *mut Spawn) {
        if ptr.is_null() {
            return;
        }

        Box::from_raw(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn spawn_get_hash(ptr: *mut Spawn) -> u64 {
        assert!(!ptr.is_null());
        let spawn = &*ptr;
        spawn.get_hash()
    }

    #[no_mangle]
    pub unsafe extern "C" fn spawn_get_seed(ptr: *mut Spawn) -> u64 {
        assert!(!ptr.is_null());
        let spawn = &*ptr;
        spawn.get_seed()
    }

    #[no_mangle]
    pub unsafe extern "C" fn spawn_get_is_active(ptr: *mut Spawn) -> bool {
        assert!(!ptr.is_null());
        let spawn = &*ptr;
        spawn.get_is_active()
    }
}
