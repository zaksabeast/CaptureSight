use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerPrefsProviderInstance = 0x4e853f0,
    FieldManager = 0x4e4f730,
    MainRng = 0x4fb2050,
    UnionRoomManager = 0x4e5c790,
}
