use crate::rng::Xoroshiro;
use alloc::boxed::Box;

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn get_xoroshiro(s0: u64, s1: u64) -> *mut Xoroshiro {
    Box::into_raw(Box::new(Xoroshiro::from_state(s0, s1)))
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn free_xoroshiro(ptr: *mut Xoroshiro) {
    if ptr.is_null() {
        return;
    }

    Box::from_raw(ptr);
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn xoroshiro_advance_to_state(ptr: *mut Xoroshiro, s0: u64, s1: u64) -> u64 {
    assert!(!ptr.is_null());
    let rng = &mut *ptr;
    rng.advance_to_state([s0, s1]).unwrap_or_default()
}
