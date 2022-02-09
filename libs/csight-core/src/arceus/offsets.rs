use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerSingleton = 0x4269000,
    BattleSingleton = 0x4268f00,
    SpawnSingleton = 0x4268ee0,
}
