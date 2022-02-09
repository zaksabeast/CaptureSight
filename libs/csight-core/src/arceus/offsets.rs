use num_enum::IntoPrimitive;

#[derive(Clone, Copy, Debug, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Offset {
    PlayerSingleton = 0x426f000,
    BattleSingleton = 0x426ef00,
    SpawnSingleton = 0x426eee0,
}
