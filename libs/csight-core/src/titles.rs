use num_enum::TryFromPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, TryFromPrimitive)]
#[repr(u64)]
pub enum SupportedGame {
    Sword = 0x0100ABF008968000,
    Shield = 0x01008DB008C2C000,
}
