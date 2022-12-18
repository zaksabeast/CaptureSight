use core::fmt::Display;

/// Copies rust text to a c string, including the null terminator.
/// No copy will be performed if the src length or dst_length 0.
///
/// # Safety
///
/// The caller must follow all safety rules from [pointer::copy_from_nonoverlapping]
/// and [pointer::write].
pub unsafe fn copy_as_c_str(src: &str, dst: *mut core::ffi::c_char, dst_length: usize) {
    let dst = dst as *mut u8;
    let src_bytes = src.as_bytes();
    let copy_size = core::cmp::min(dst_length - 1, src_bytes.len());

    if copy_size == 0 {
        return;
    }

    dst.copy_from_nonoverlapping(src_bytes.as_ptr(), copy_size);
    // Null terminator
    dst.add(copy_size).write(0);
}

/// Same as [copy_as_c_str], but takes a source that can be formatted for display.
///
/// # Safety
/// The same rules as [copy_as_c_str] applies.
pub unsafe fn copy_display_as_c_str<T: Display>(
    src: T,
    dst: *mut core::ffi::c_char,
    dst_length: usize,
) {
    let formatted = alloc::format!("{}", src);
    copy_as_c_str(&formatted, dst, dst_length);
}
