use super::c_str;
use core::convert::TryFrom;
use pkm_rs::types;

/// # Safety
/// The caller needs to ensure the pointer is not null.
#[no_mangle]
pub unsafe extern "C" fn get_species_string(species_num: u16, dst: *mut u8, dst_length: usize) {
    let species = types::Species::try_from(species_num).unwrap_or(types::Species::None);
    c_str::copy_display_as_c_str(species, dst, dst_length);
}
