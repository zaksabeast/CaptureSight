#[macro_export]
macro_rules! boxed {
    ($logic:expr) => {
        alloc::boxed::Box::into_raw(alloc::boxed::Box::new($logic))
    };
}

#[macro_export]
macro_rules! open_box {
    ($ptr:expr) => {{
        assert!(!$ptr.is_null());
        &*$ptr
    }};
}

#[macro_export]
macro_rules! free {
    ($ptr:ident) => {
        if $ptr.is_null() {
            return;
        }

        drop(alloc::boxed::Box::from_raw($ptr));
    };
}

#[macro_export]
macro_rules! run_method {
    ($ptr:ident, $method:ident) => {{
        crate::utils::open_box!($ptr).$method()
    }};
}

#[macro_export]
macro_rules! run_display_method {
    ($ptr:ident, $method:ident, $dst:ident, $dst_length:ident) => {
        let value = crate::utils::run_method!($ptr, $method);
        crate::c_str::copy_display_as_c_str(value, $dst, $dst_length);
    };
}

pub use boxed;
pub use free;
pub use open_box;
pub use run_display_method;
pub use run_method;
