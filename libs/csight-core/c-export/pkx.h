#pragma once

#include <switch.h>

#ifdef __cplusplus

#include <optional>
#include <string>

namespace csight {
  extern "C" {
#endif

  struct Stats {
    u8 hp;
    u8 atk;
    u8 def;
    u8 spa;
    u8 spd;
    u8 spe;
  } stats;

#ifdef __cplusplus

  class Pkx {
   public:
    virtual u32 EncryptionConstant() = 0;
    virtual std::string SpeciesString() = 0;
    virtual u16 Tid() = 0;
    virtual u16 Sid() = 0;
    virtual std::string AbilityString() = 0;
    virtual u8 AbilityNumber() = 0;
    virtual u32 Pid() = 0;
    virtual std::string NatureString() = 0;
    virtual std::string MintedNatureString() = 0;
    virtual u8 Gender() = 0;
    virtual Stats Evs() = 0;
    virtual Stats Ivs() = 0;
    virtual std::string Move1String() = 0;
    virtual std::string Move2String() = 0;
    virtual std::string Move3String() = 0;
    virtual std::string Move4String() = 0;
    virtual u8 CurrentFriendship() = 0;
    virtual u8 Language() = 0;
    virtual bool IsShiny() = 0;
    virtual bool IsEgg() = 0;
    virtual std::optional<u64> FindRaidSeed() = 0;
  };
  }
};
#endif
