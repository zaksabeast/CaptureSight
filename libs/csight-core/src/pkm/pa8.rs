mod c_api {
    use crate::c_str;
    use alloc::boxed::Box;
    use pkm_rs::{types, Pa8, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pa8(ptr: *mut Pa8) {
        if ptr.is_null() {
            return;
        }

        drop(Box::from_raw(ptr));
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_encryption_constant(ptr: *mut Pa8) -> u32 {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.encryption_constant()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_species_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.species();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_tid(ptr: *mut Pa8) -> u16 {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.tid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_sid(ptr: *mut Pa8) -> u16 {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.sid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ability_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.ability();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ability_number(ptr: *mut Pa8) -> types::AbilityNumber {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.ability_number()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_pid(ptr: *mut Pa8) -> u32 {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.pid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_nature_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_minted_nature_string(
        ptr: *mut Pa8,
        dst: *mut u8,
        dst_length: usize,
    ) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.minted_nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_gender(ptr: *mut Pa8) -> types::Gender {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        if pa8.is_valid() {
            pa8.gender()
        } else {
            types::Gender::Unknown
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_evs(ptr: *mut Pa8) -> types::Stats {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.evs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_ivs(ptr: *mut Pa8) -> types::Stats {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.ivs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move1_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.move1();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move2_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.move2();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move3_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.move3();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_move4_string(ptr: *mut Pa8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;

        let value = pa8.move4();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_language(ptr: *mut Pa8) -> types::Language {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.language()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_is_shiny(ptr: *mut Pa8) -> bool {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.is_shiny()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_is_egg(ptr: *mut Pa8) -> bool {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.is_egg()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pa8_current_friendship(ptr: *mut Pa8) -> u8 {
        assert!(!ptr.is_null());
        let pa8 = &*ptr;
        pa8.current_friendship()
    }
}
