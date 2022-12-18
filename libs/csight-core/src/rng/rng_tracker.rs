use crate::{
    dmntcht::DmntReader,
    rng::{Lcrng, Rng, RngState, Xoroshiro, Xorshift},
};
use core::ffi::c_void;

pub struct RngTracker<GameRng: Rng> {
    state_reader: DmntReader,
    rng: GameRng,
}

impl<GameRng: Rng> RngTracker<GameRng> {
    fn read_state_from_reader(state_reader: &DmntReader) -> GameRng::State {
        state_reader.read_offset(0)
    }

    pub fn new_from_heap<T: Into<u64>>(heap_offset: T) -> Self {
        let state_reader = DmntReader::new_from_heap(heap_offset.into());
        Self::new_from_reader(state_reader)
    }

    pub fn new_from_reader(state_reader: DmntReader) -> Self {
        let state = Self::read_state_from_reader(&state_reader);

        Self {
            state_reader,
            rng: GameRng::from_state(state),
        }
    }

    pub fn read_state(&self) -> GameRng::State {
        Self::read_state_from_reader(&self.state_reader)
    }

    pub fn get_advances(&mut self) -> Option<u64> {
        self.rng.advance_to_state(self.read_state())
    }

    pub fn get_state_count() -> usize {
        GameRng::State::STATE_COUNT
    }

    pub fn get_state_item_size() -> usize {
        GameRng::State::get_state_item_size()
    }
}

pub type XoroshiroTracker = RngTracker<Xoroshiro>;
pub type XorshiftTracker = RngTracker<Xorshift>;
pub type LcrngTracker = RngTracker<Lcrng>;

mod c_api {
    use super::*;

    // This is used by c, but rust doesn't know it's actually in use
    #[allow(dead_code)]
    #[repr(C)]
    pub enum RngType {
        Xoroshiro = 0,
        Xorshift = 1,
        Lcrng = 2,
    }

    #[no_mangle]
    pub unsafe extern "C" fn free_rng_tracker(ptr: *mut c_void, rng_type: RngType) {
        match rng_type {
            RngType::Xoroshiro => {
                let ptr = ptr as *mut _ as *mut XoroshiroTracker;
                crate::utils::free!(ptr);
            }
            RngType::Xorshift => {
                let ptr = ptr as *mut _ as *mut XorshiftTracker;
                crate::utils::free!(ptr);
            }
            RngType::Lcrng => {
                let ptr = ptr as *mut _ as *mut LcrngTracker;
                crate::utils::free!(ptr);
            }
        };
    }

    #[no_mangle]
    pub unsafe extern "C" fn get_rng_tracker_advances(ptr: *mut c_void, rng_type: RngType) -> u64 {
        assert!(!ptr.is_null());

        match rng_type {
            RngType::Xoroshiro => {
                let rng = &mut *(ptr as *mut _ as *mut XoroshiroTracker);
                rng.get_advances().unwrap_or_default()
            }
            RngType::Xorshift => {
                let rng = &mut *(ptr as *mut _ as *mut XorshiftTracker);
                rng.get_advances().unwrap_or_default()
            }
            RngType::Lcrng => {
                let rng = &mut *(ptr as *mut _ as *mut LcrngTracker);
                rng.get_advances().unwrap_or_default()
            }
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn read_rng_tracker_state(
        out: *mut u64,
        out_count: *mut usize,
        max_out: usize,
        ptr: *mut c_void,
        rng_type: RngType,
    ) {
        assert!(!ptr.is_null());
        assert!(!out.is_null());
        assert!(!out_count.is_null());

        let state = match rng_type {
            RngType::Xoroshiro => {
                let rng = &mut *(ptr as *mut _ as *mut XoroshiroTracker);
                rng.read_state().get_inner()
            }
            RngType::Xorshift => {
                let rng = &mut *(ptr as *mut _ as *mut XorshiftTracker);
                rng.read_state().get_inner()
            }
            RngType::Lcrng => {
                let rng = &mut *(ptr as *mut _ as *mut LcrngTracker);
                rng.read_state().get_inner()
            }
        };

        let mut count = 0;

        for (index, piece) in state.iter().enumerate().take(max_out) {
            *out.add(index) = *piece;
            count += 1;
        }

        *out_count = count;
    }

    #[no_mangle]
    pub extern "C" fn get_rng_tracker_state_count(rng_type: RngType) -> usize {
        match rng_type {
            RngType::Xoroshiro => XoroshiroTracker::get_state_count(),
            RngType::Xorshift => XorshiftTracker::get_state_count(),
            RngType::Lcrng => LcrngTracker::get_state_count(),
        }
    }

    #[no_mangle]
    pub extern "C" fn get_rng_tracker_state_item_size(rng_type: RngType) -> usize {
        match rng_type {
            RngType::Xoroshiro => XoroshiroTracker::get_state_item_size(),
            RngType::Xorshift => XorshiftTracker::get_state_item_size(),
            RngType::Lcrng => LcrngTracker::get_state_item_size(),
        }
    }
}
