use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerPrefsProviderInstance = 0x4E61DD0,
    FieldManager = 0x4E2C6F0,
    MainRng = 0x4F8E750,
    UnionRoomManager = 0x4E395B0,
}
