mod c_api {
    use pkm_rs::{types, Pk8, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pk8(ptr: *mut Pk8) {
        crate::utils::free!(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_encryption_constant(ptr: *mut Pk8) -> u32 {
        crate::utils::run_method!(ptr, encryption_constant)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_species_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, species, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_tid(ptr: *mut Pk8) -> u16 {
        crate::utils::run_method!(ptr, tid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_sid(ptr: *mut Pk8) -> u16 {
        crate::utils::run_method!(ptr, sid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ability_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, ability, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ability_number(ptr: *mut Pk8) -> u8 {
        crate::utils::run_method!(ptr, ability_number) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_pid(ptr: *mut Pk8) -> u32 {
        crate::utils::run_method!(ptr, pid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_nature_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_minted_nature_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, minted_nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_gender(ptr: *mut Pk8) -> u8 {
        let pkm = crate::utils::open_box!(ptr);

        let gender = if pkm.is_valid() {
            pkm.gender()
        } else {
            types::Gender::Unknown
        };

        gender as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_evs(ptr: *mut Pk8) -> types::Stats {
        crate::utils::run_method!(ptr, evs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ivs(ptr: *mut Pk8) -> types::Stats {
        crate::utils::run_method!(ptr, ivs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move1_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move1, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move2_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move2, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move3_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move3, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move4_string(
        ptr: *mut Pk8,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move4, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_language(ptr: *mut Pk8) -> u8 {
        crate::utils::run_method!(ptr, language) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_is_shiny(ptr: *mut Pk8) -> bool {
        crate::utils::run_method!(ptr, is_shiny)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_is_egg(ptr: *mut Pk8) -> bool {
        crate::utils::run_method!(ptr, is_egg)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_current_friendship(ptr: *mut Pk8) -> u8 {
        crate::utils::run_method!(ptr, current_friendship)
    }
}
