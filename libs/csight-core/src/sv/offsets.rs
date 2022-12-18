use num_enum::IntoPrimitive;

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offsets {
    MainSingleton = 0x42d0638,
    Party = 0x42da880,
}
