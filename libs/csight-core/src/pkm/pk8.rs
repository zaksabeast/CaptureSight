mod c_api {
    use crate::c_str;
    use alloc::boxed::Box;
    use pkm_rs::{types, Pk8, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pk8(ptr: *mut Pk8) {
        if ptr.is_null() {
            return;
        }

        Box::from_raw(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_encryption_constant(ptr: *mut Pk8) -> u32 {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.encryption_constant()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_species_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.species();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_tid(ptr: *mut Pk8) -> u16 {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.tid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_sid(ptr: *mut Pk8) -> u16 {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.sid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ability_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.ability();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ability_number(ptr: *mut Pk8) -> types::AbilityNumber {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.ability_number()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_pid(ptr: *mut Pk8) -> u32 {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.pid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_nature_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_minted_nature_string(
        ptr: *mut Pk8,
        dst: *mut u8,
        dst_length: usize,
    ) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.minted_nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_gender(ptr: *mut Pk8) -> types::Gender {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        if pk8.is_valid() {
            pk8.gender()
        } else {
            types::Gender::Unknown
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_evs(ptr: *mut Pk8) -> types::Stats {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.evs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_ivs(ptr: *mut Pk8) -> types::Stats {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.ivs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move1_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.move1();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move2_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.move2();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move3_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.move3();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_move4_string(ptr: *mut Pk8, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;

        let value = pk8.move4();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_language(ptr: *mut Pk8) -> types::Language {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.language()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_is_shiny(ptr: *mut Pk8) -> bool {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.is_shiny()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_is_egg(ptr: *mut Pk8) -> bool {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.is_egg()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk8_current_friendship(ptr: *mut Pk8) -> u8 {
        assert!(!ptr.is_null());
        let pk8 = &*ptr;
        pk8.current_friendship()
    }
}
