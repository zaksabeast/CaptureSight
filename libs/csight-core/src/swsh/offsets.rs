use num_enum::IntoPrimitive;

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum Pk8Offset {
    Wild = 0x8fea3648,
    WildLegend = 0x886bc058,
    Trade = 0xaf286078,
    Raid = 0x886c1ec8,
    Party = 0x450c68b0,
}

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum DenOffset {
    Vanilla = 0x450c8a70,
    IslandOfArmor = 0x450c94d8,
    CrownTundra = 0x450c9f40,
}

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum RngOffset {
    Main = 0x4c2aac18,
}

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum MyStatus8Offset {
    SidTid = 0xa0,
}

#[derive(Debug, Clone, Copy, Eq, PartialEq, IntoPrimitive)]
#[repr(u64)]
pub enum BlockOffset {
    MyStatus8 = 0x45068f18,
}
