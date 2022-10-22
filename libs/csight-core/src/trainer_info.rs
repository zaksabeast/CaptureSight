use no_std_io::EndianRead;

#[derive(Clone, Copy, Default, EndianRead)]
#[repr(C)]
pub struct TrainerInfo {
    tid: u16,
    sid: u16,
}
