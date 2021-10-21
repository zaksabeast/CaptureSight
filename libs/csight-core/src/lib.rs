#![no_std]
#![feature(alloc_error_handler)]

extern crate alloc;

pub mod c_api;
mod heap_allocator;
mod rng;
mod swsh;
mod titles;

#[cfg(not(test))]
use core::panic::PanicInfo;

#[cfg(not(test))]
#[doc(hidden)]
#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    loop {}
}
