mod c_api {
    use crate::c_str;
    use core::convert::TryFrom;
    use pkm_rs::types;

    #[no_mangle]
    pub unsafe extern "C" fn get_species_string(
        species_num: u16,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        let species = types::Species::try_from(species_num).unwrap_or(types::Species::None);
        c_str::copy_display_as_c_str(species, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn get_small_gender_string(
        gender_num: u8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        let gender = types::Gender::try_from(gender_num).unwrap_or(types::Gender::Unknown);
        let gender_str = match gender {
            types::Gender::Male => "(M)",
            types::Gender::Female => "(F)",
            _ => "\0",
        };
        c_str::copy_display_as_c_str(gender_str, dst, dst_length);
    }
}
