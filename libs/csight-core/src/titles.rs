use num_enum::{IntoPrimitive, TryFromPrimitive};

#[derive(Clone, Copy, Debug, Eq, PartialEq, IntoPrimitive, TryFromPrimitive)]
#[repr(u64)]
pub enum SupportedGame {
    Sword = 0x0100ABF008968000,
    Shield = 0x01008DB008C2C000,
    BrilliantDiamond = 0x0100000011D90000,
    ShiningPearl = 0x010018E011D92000,
    Arceus = 0x01001F5010DFA000,
    Scarlet = 0x0100A3D008C5C000,
    Violet = 0x01008F6008C5E000,
}

impl PartialEq<SupportedGame> for u64 {
    fn eq(&self, other: &SupportedGame) -> bool {
        *self == *other as u64
    }
}

impl PartialEq<u64> for SupportedGame {
    fn eq(&self, other: &u64) -> bool {
        *self as u64 == *other
    }
}
