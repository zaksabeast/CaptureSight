#![no_std]
#![feature(alloc_error_handler)]

extern crate alloc;

mod arceus;
mod bdsp;
mod c_str;
mod dmntcht;
mod heap_allocator;
mod pkm;
mod rng;
mod sv;
mod swsh;
mod titles;
mod trainer_info;
mod utils;

#[cfg(not(test))]
use core::panic::PanicInfo;

#[cfg(not(test))]
#[doc(hidden)]
#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    loop {}
}

mod c_api {
    use crate::heap_allocator;

    /// Initializes the library
    /// # Safety
    /// The caller must guarantee this is called at least once, but only once.
    #[no_mangle]
    pub unsafe extern "C" fn init() {
        heap_allocator::init_heap();
    }
}
