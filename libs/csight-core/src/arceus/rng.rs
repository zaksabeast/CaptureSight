use super::read::get_player_singleton;

mod c_api {
    use super::*;
    use crate::rng::XoroshiroTracker;
    use alloc::boxed::Box;

    #[no_mangle]
    pub unsafe extern "C" fn arceus_get_main_rng_tracker() -> *mut XoroshiroTracker {
        let reader = get_player_singleton().follow(0xd8);
        Box::into_raw(Box::new(XoroshiroTracker::new_from_reader(reader)))
    }
}
