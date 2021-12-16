#pragma once

enum SupportedGame {
  Sword = 0x0100ABF008968000,
  Shield = 0x01008DB008C2C000,
  BrilliantDiamond = 0x0100000011D90000,
  ShiningPearl = 0x010018E011D92000,
};

namespace swsh {
  enum Pk8Offset {
    Wild = 0x8fea3648,
    WildLegend = 0x886bc058,
    Trade = 0xaf286078,
    Raid = 0x886c1ec8,
    Party = 0x450c68b0,
  };

  enum DenOffset {
    Vanilla = 0x450c8a70,
    IslandOfArmor = 0x450c94d8,
    CrownTundra = 0x450c9f40,
  };

  enum RngOffset {
    Main = 0x4c2aac18,
  };

  enum MyStatus8Offset {
    SidTid = 0xa0,
  };

  enum BlockOffset {
    MyStatus8 = 0x45068f18,
  };
}

namespace bdsp {
  enum Offsets {
    PlayerPrefsProviderInstance = 0x4e60170,
    FieldManager = 0x4e2a728,
    UnionRoomManager = 0x4e376e8,
  };

  enum RngOffset {
    MainPtr = 0x4f8ccd0,
  };
}
