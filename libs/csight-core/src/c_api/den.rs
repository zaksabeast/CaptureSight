use super::c_str;
use crate::{
    swsh::{Den, ShinyType},
    titles::SupportedGame,
};
use alloc::{boxed::Box, string::ToString};
use core::{convert::TryInto, slice};

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn get_sword_den(bytes: *mut u8, index: usize) -> *mut Den {
    let bytes_copy = slice::from_raw_parts(bytes, Den::SIZE).to_vec();
    Box::into_raw(Box::new(Den::new(
        bytes_copy.try_into().unwrap(),
        index,
        SupportedGame::Sword,
    )))
}

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn get_shield_den(bytes: *mut u8, index: usize) -> *mut Den {
    let bytes_copy = slice::from_raw_parts(bytes, Den::SIZE).to_vec();
    Box::into_raw(Box::new(Den::new(
        bytes_copy.try_into().unwrap(),
        index,
        SupportedGame::Shield,
    )))
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn free_den(ptr: *mut Den) {
    if ptr.is_null() {
        return;
    }

    Box::from_raw(ptr);
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn den_shiny_details_string(ptr: *mut Den, dst: *mut u8, dst_length: usize) {
    assert!(!ptr.is_null());
    let den = &*ptr;

    let shiny_details = den.shiny_details(10000);

    let shiny_text = match (shiny_details.shiny_type, shiny_details.advances) {
        (ShinyType::Star, Some(advances)) => alloc::format!("★ in {}", advances),
        (ShinyType::Square, Some(advances)) => alloc::format!("■ in {}", advances),
        (_, _) => "No nearby shiny".to_string(),
    };

    c_str::copy_as_c_str(&shiny_text, dst, dst_length)
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn den_species_string(ptr: *mut Den, dst: *mut u8, dst_length: usize) {
    assert!(!ptr.is_null());
    let den = &*ptr;

    if den.is_event() {
        c_str::copy_as_c_str("Event", dst, dst_length)
    } else {
        let value = den.encounter().species;
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn den_is_event(ptr: *mut Den) -> bool {
    assert!(!ptr.is_null());
    let den = &*ptr;
    den.is_event()
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn den_is_active(ptr: *mut Den) -> bool {
    assert!(!ptr.is_null());
    let den = &*ptr;
    den.is_active()
}

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn den_seed(ptr: *mut Den) -> u64 {
    assert!(!ptr.is_null());
    let den = &*ptr;
    den.seed()
}
