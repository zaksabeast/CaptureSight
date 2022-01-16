mod c_api {
    use crate::{
        bdsp::{offsets::Offset, read::read_random_group_state_reader},
        dmntcht::DmntReader,
        rng::{LcrngTracker, XorshiftTracker},
    };
    use alloc::boxed::Box;

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_get_main_rng_tracker() -> *mut XorshiftTracker {
        let reader = DmntReader::new_from_main_nso(Offset::MainRng).follow(0);
        Box::into_raw(Box::new(XorshiftTracker::new_from_reader(reader)))
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_get_random_group_rng_tracker(index: usize) -> *mut LcrngTracker {
        let offset = (index * 0x38) + 0x40;
        let reader = read_random_group_state_reader().add(offset as u64);
        Box::into_raw(Box::new(LcrngTracker::new_from_reader(reader)))
    }
}
