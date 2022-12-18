mod c_api {
    use pkm_rs::{types, Pk9, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pk9(ptr: *mut Pk9) {
        crate::utils::free!(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_encryption_constant(ptr: *mut Pk9) -> u32 {
        crate::utils::run_method!(ptr, encryption_constant)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_species_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, species, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_tid(ptr: *mut Pk9) -> u16 {
        crate::utils::run_method!(ptr, tid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_sid(ptr: *mut Pk9) -> u16 {
        crate::utils::run_method!(ptr, sid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ability_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, ability, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ability_number(ptr: *mut Pk9) -> u8 {
        crate::utils::run_method!(ptr, ability_number) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_pid(ptr: *mut Pk9) -> u32 {
        crate::utils::run_method!(ptr, pid)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_nature_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_minted_nature_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, minted_nature, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_gender(ptr: *mut Pk9) -> u8 {
        let pkm = crate::utils::open_box!(ptr);

        let gender = if pkm.is_valid() {
            pkm.gender()
        } else {
            types::Gender::Unknown
        };

        gender as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_evs(ptr: *mut Pk9) -> types::Stats {
        crate::utils::run_method!(ptr, evs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ivs(ptr: *mut Pk9) -> types::Stats {
        crate::utils::run_method!(ptr, ivs)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move1_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move1, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move2_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move2, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move3_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move3, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move4_string(
        ptr: *mut Pk9,
        dst: *mut core::ffi::c_char,
        dst_length: usize,
    ) {
        crate::utils::run_display_method!(ptr, move4, dst, dst_length);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_language(ptr: *mut Pk9) -> u8 {
        crate::utils::run_method!(ptr, language) as u8
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_is_shiny(ptr: *mut Pk9) -> bool {
        crate::utils::run_method!(ptr, is_shiny)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_is_egg(ptr: *mut Pk9) -> bool {
        crate::utils::run_method!(ptr, is_egg)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_current_friendship(ptr: *mut Pk9) -> u8 {
        crate::utils::run_method!(ptr, current_friendship)
    }
}
