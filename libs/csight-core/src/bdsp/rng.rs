mod c_api {
    use crate::{
        bdsp::{offsets, read::read_random_group_state_reader},
        dmntcht::DmntReader,
        rng::{LcrngTracker, XorshiftTracker},
    };

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_get_main_rng_tracker() -> *mut XorshiftTracker {
        let reader = DmntReader::new_from_main_nso(offsets::get_main_rng()).follow(0);
        crate::utils::boxed!(XorshiftTracker::new_from_reader(reader))
    }

    #[no_mangle]
    pub unsafe extern "C" fn bdsp_get_random_group_rng_tracker(index: usize) -> *mut LcrngTracker {
        let offset = (index * 0x38) + 0x40;
        let reader = read_random_group_state_reader().add(offset as u64);
        crate::utils::boxed!(LcrngTracker::new_from_reader(reader))
    }
}
