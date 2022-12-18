mod c_api {
    use crate::{rng::XoroshiroTracker, swsh::offsets::RngOffset};

    #[no_mangle]
    pub unsafe extern "C" fn swsh_get_main_rng_tracker() -> *mut XoroshiroTracker {
        crate::utils::boxed!(XoroshiroTracker::new_from_heap(RngOffset::Main))
    }
}
