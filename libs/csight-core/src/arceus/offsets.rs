use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerSingleton = 0x4268000,
    BattleSingleton = 0x4267f00,
    SpawnSingleton = 0x4267ee0,
}
