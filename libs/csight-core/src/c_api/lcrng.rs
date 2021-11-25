use crate::rng::Lcrng;
use crate::rng::Rng;
use alloc::boxed::Box;

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn get_lcrng(seed: u64) -> *mut Lcrng {
    Box::into_raw(Box::new(Lcrng::from_state([seed])))
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn free_lcrng(ptr: *mut Lcrng) {
    if ptr.is_null() {
        return;
    }

    Box::from_raw(ptr);
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn lcrng_advance_to_state(ptr: *mut Lcrng, seed: u64) -> u64 {
    assert!(!ptr.is_null());
    let rng = &mut *ptr;
    rng.advance_to_state([seed]).unwrap_or_default()
}
