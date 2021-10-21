#[cfg(target_os = "horizon")]
use core::alloc::Layout;
#[cfg(target_os = "horizon")]
use linked_list_allocator::LockedHeap;

#[cfg(target_os = "horizon")]
#[alloc_error_handler]
fn handle_out_of_memory(_layout: Layout) -> ! {
    panic!()
}

#[cfg(target_os = "horizon")]
const FAKE_HEAP_SIZE: usize = 0x10000;

#[cfg(target_os = "horizon")]
#[repr(align(0x1000))]
struct AlignedFakeHeapContainer([u8; FAKE_HEAP_SIZE]);

#[cfg(target_os = "horizon")]
static mut FAKE_HEAP: AlignedFakeHeapContainer = AlignedFakeHeapContainer([0; FAKE_HEAP_SIZE]);

#[cfg(target_os = "horizon")]
#[global_allocator]
static ALLOCATOR: LockedHeap = LockedHeap::empty();

/// This is unsafe because we should only use the function one time.
#[cfg(target_os = "horizon")]
pub unsafe fn init_heap() {
    // This is safe since we guarantee the fake heap will
    // only be used here and is a valid pointer.
    let fake_heap_ptr = FAKE_HEAP.0.as_mut_ptr();
    ALLOCATOR.lock().init(
        fake_heap_ptr as usize,
        fake_heap_ptr.add(FAKE_HEAP_SIZE) as usize,
    )
}

#[cfg(not(target_os = "horizon"))]
pub unsafe fn init_heap() {}
