fn main() {
    #[cfg(target_os = "horizon")]
    println!("cargo:rustc-flags=-l dmntcht -L ../dmntcht/lib");
}
