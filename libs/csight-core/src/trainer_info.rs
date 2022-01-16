use safe_transmute::TriviallyTransmutable;

#[derive(Clone, Copy, Default)]
#[repr(C)]
pub struct TrainerInfo {
    tid: u16,
    sid: u16,
}

unsafe impl TriviallyTransmutable for TrainerInfo {}
