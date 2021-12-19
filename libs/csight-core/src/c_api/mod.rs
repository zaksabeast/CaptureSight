pub mod c_str;
pub mod den;
pub mod lcrng;
pub mod pk8;
pub mod pkx;
pub mod raid_seed;
pub mod xoroshiro;
pub mod xorshift;

use crate::heap_allocator;

/// Initializes the library
/// # Safety
/// The caller must guarantee this is called at least once, but only once.
#[no_mangle]
pub unsafe extern "C" fn init() {
    heap_allocator::init_heap();
}
