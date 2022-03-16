use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerPrefsProviderInstance = 0x4c90330,
    FieldManager = 0x4c5a638,
    MainRng = 0x4fd43d0,
    UnionRoomManager = 0x4c67750,
}
