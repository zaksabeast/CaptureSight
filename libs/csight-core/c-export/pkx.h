#pragma once

#include "generated.h"
#include <optional>
#include <string>
#include <switch.h>

#define gen_pkx_bindings(CppType, PkmName, stored_size)                       \
  class CppType : public Pkx {                                                \
   public:                                                                    \
    static const size_t StoredSize = stored_size;                             \
                                                                              \
    CppType(PkmName##_t *pkm) : m_pkm(pkm) { }                                \
    ~CppType() { free_##PkmName(m_pkm); }                                     \
                                                                              \
    u32 EncryptionConstant() { return PkmName##_encryption_constant(m_pkm); } \
                                                                              \
    std::string SpeciesString() {                                             \
      char text[13];                                                          \
      PkmName##_species_string(m_pkm, text, 13);                              \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    u16 Tid() { return PkmName##_tid(m_pkm); }                                \
                                                                              \
    u16 Sid() { return PkmName##_sid(m_pkm); }                                \
                                                                              \
    std::string AbilityString() {                                             \
      char text[17];                                                          \
      PkmName##_ability_string(m_pkm, text, 17);                              \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    u8 AbilityNumber() { return PkmName##_ability_number(m_pkm); }            \
                                                                              \
    u32 Pid() { return PkmName##_pid(m_pkm); }                                \
                                                                              \
    std::string NatureString() {                                              \
      char text[8];                                                           \
      PkmName##_nature_string(m_pkm, text, 8);                                \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    std::string MintedNatureString() {                                        \
      char text[8];                                                           \
      PkmName##_minted_nature_string(m_pkm, text, 8);                         \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    u8 Gender() { return PkmName##_gender(m_pkm); }                           \
                                                                              \
    Stats Evs() { return PkmName##_evs(m_pkm); }                              \
                                                                              \
    Stats Ivs() { return PkmName##_ivs(m_pkm); }                              \
                                                                              \
    std::string Move1String() {                                               \
      char text[28];                                                          \
      PkmName##_move1_string(m_pkm, text, 28);                                \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    std::string Move2String() {                                               \
      char text[28];                                                          \
      PkmName##_move2_string(m_pkm, text, 28);                                \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    std::string Move3String() {                                               \
      char text[28];                                                          \
      PkmName##_move3_string(m_pkm, text, 28);                                \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    std::string Move4String() {                                               \
      char text[28];                                                          \
      PkmName##_move4_string(m_pkm, text, 28);                                \
      return std::string(text);                                               \
    }                                                                         \
                                                                              \
    u8 CurrentFriendship() { return PkmName##_current_friendship(m_pkm); }    \
                                                                              \
    u8 Language() { return PkmName##_language(m_pkm); }                       \
                                                                              \
    bool IsShiny() { return PkmName##_is_shiny(m_pkm); }                      \
                                                                              \
    bool IsEgg() { return PkmName##_is_egg(m_pkm); }                          \
                                                                              \
    std::optional<u64> FindRaidSeed() {                                       \
      u64 seed = 0;                                                           \
      bool is_found = find_##PkmName##_raid_seed(&seed, m_pkm);               \
                                                                              \
      if (is_found) {                                                         \
        return std::optional<u64>(seed);                                      \
      }                                                                       \
                                                                              \
      return std::nullopt;                                                    \
    }                                                                         \
                                                                              \
   private:                                                                   \
    PkmName##_t *m_pkm;                                                       \
  };

namespace csight {
  class Pkx {
   public:
    static std::string SpeciesString(u16 species) {
      char text[13];
      get_species_string(species, text, 13);
      return std::string(text);
    }

    static std::string SmallGenderString(u8 gender) {
      char text[4];
      get_small_gender_string(gender, text, 4);
      return std::string(text);
    }

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

  gen_pkx_bindings(Pk8, pk8, 0x148);
  gen_pkx_bindings(Pa8, pa8, 0x168);
  gen_pkx_bindings(Pk9, pk9, 0x148);
}
