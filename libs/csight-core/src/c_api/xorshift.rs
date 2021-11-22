use crate::rng::Rng;
use crate::rng::Xorshift;
use alloc::boxed::Box;

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn get_xorshift(s0: u32, s1: u32, s2: u32, s3: u32) -> *mut Xorshift {
    Box::into_raw(Box::new(Xorshift::from_state([s0, s1, s2, s3])))
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn free_xorshift(ptr: *mut Xorshift) {
    if ptr.is_null() {
        return;
    }

    Box::from_raw(ptr);
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn xorshift_advance_to_state(
    ptr: *mut Xorshift,
    s0: u32,
    s1: u32,
    s2: u32,
    s3: u32,
) -> u64 {
    assert!(!ptr.is_null());
    let rng = &mut *ptr;
    rng.advance_to_state([s0, s1, s2, s3]).unwrap_or_default()
}
