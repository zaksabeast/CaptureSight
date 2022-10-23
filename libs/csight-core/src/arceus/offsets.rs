use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerSingleton = 0x42a7000,
    BattleSingleton = 0x42a6f00,
    SpawnSingleton = 0x42a6ee0,
}
