use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerPrefsProviderInstance = 0x4e61dd0,
    FieldManager = 0x4e2c6f0,
    MainRng = 0x4f8e750,
    UnionRoomManager = 0x4e395b0,
}
