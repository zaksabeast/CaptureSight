use super::read::get_player_singleton;

mod c_api {
    use super::*;
    use crate::rng::XoroshiroTracker;

    #[no_mangle]
    pub unsafe extern "C" fn arceus_get_main_rng_tracker() -> *mut XoroshiroTracker {
        let reader = get_player_singleton().follow(0xd8);
        crate::utils::boxed!(XoroshiroTracker::new_from_reader(reader))
    }
}
