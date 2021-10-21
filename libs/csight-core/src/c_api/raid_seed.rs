use crate::swsh::raid_seed;
use pkm_rs::Pk8;

/// # Safety
/// The caller needs to ensure the data is valid.
#[no_mangle]
pub unsafe extern "C" fn find_pk8_raid_seed(out: *mut u64, ptr: *mut Pk8) -> bool {
    assert!(!ptr.is_null());
    let pk8 = &*ptr;
    let seed = raid_seed::find_pk8_raid_seed(pk8);

    match seed {
        Some(seed) => {
            *out = seed;
            true
        }
        None => false,
    }
}
