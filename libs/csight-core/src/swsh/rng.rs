mod c_api {
    use crate::{rng::XoroshiroTracker, swsh::offsets::RngOffset};
    use alloc::boxed::Box;

    #[no_mangle]
    pub unsafe extern "C" fn swsh_get_main_rng_tracker() -> *mut XoroshiroTracker {
        Box::into_raw(Box::new(XoroshiroTracker::new_from_heap(RngOffset::Main)))
    }
}
