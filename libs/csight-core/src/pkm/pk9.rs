mod c_api {
    use crate::c_str;
    use alloc::boxed::Box;
    use pkm_rs::{types, Pk9, Pkx};

    #[no_mangle]
    pub unsafe extern "C" fn free_pk9(ptr: *mut Pk9) {
        if ptr.is_null() {
            return;
        }

        Box::from_raw(ptr);
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_encryption_constant(ptr: *mut Pk9) -> u32 {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.encryption_constant()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_species_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.species();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_tid(ptr: *mut Pk9) -> u16 {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.tid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_sid(ptr: *mut Pk9) -> u16 {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.sid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ability_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.ability();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ability_number(ptr: *mut Pk9) -> types::AbilityNumber {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.ability_number()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_pid(ptr: *mut Pk9) -> u32 {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.pid()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_nature_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_minted_nature_string(
        ptr: *mut Pk9,
        dst: *mut u8,
        dst_length: usize,
    ) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.minted_nature();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_gender(ptr: *mut Pk9) -> types::Gender {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        if pk9.is_valid() {
            pk9.gender()
        } else {
            types::Gender::Unknown
        }
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_evs(ptr: *mut Pk9) -> types::Stats {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.evs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_ivs(ptr: *mut Pk9) -> types::Stats {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.ivs()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move1_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.move1();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move2_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.move2();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move3_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.move3();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_move4_string(ptr: *mut Pk9, dst: *mut u8, dst_length: usize) {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;

        let value = pk9.move4();
        c_str::copy_display_as_c_str(value, dst, dst_length)
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_language(ptr: *mut Pk9) -> types::Language {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.language()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_is_shiny(ptr: *mut Pk9) -> bool {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.is_shiny()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_is_egg(ptr: *mut Pk9) -> bool {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.is_egg()
    }

    #[no_mangle]
    pub unsafe extern "C" fn pk9_current_friendship(ptr: *mut Pk9) -> u8 {
        assert!(!ptr.is_null());
        let pk9 = &*ptr;
        pk9.current_friendship()
    }
}
