#pragma once

#include "pkx.h"
#include <switch.h>

#ifdef __cplusplus

#include <array>
#include <optional>
#include <string>

namespace csight {
  extern "C" {
#endif

  typedef struct pk9 pk9_t;

  void free_pk9(pk9_t *ptr);

  u32 pk9_encryption_constant(pk9_t *ptr);
  void pk9_species_string(pk9_t *ptr, char *out, size_t out_size);
  u16 pk9_tid(pk9_t *ptr);
  u16 pk9_sid(pk9_t *ptr);
  void pk9_ability_string(pk9_t *ptr, char *out, size_t out_size);
  u8 pk9_ability_number(pk9_t *ptr);
  u32 pk9_pid(pk9_t *ptr);
  void pk9_nature_string(pk9_t *ptr, char *out, size_t out_size);
  void pk9_minted_nature_string(pk9_t *ptr, char *out, size_t out_size);
  u8 pk9_gender(pk9_t *ptr);
  Stats pk9_evs(pk9_t *ptr);
  Stats pk9_ivs(pk9_t *ptr);
  void pk9_move1_string(pk9_t *ptr, char *out, size_t out_size);
  void pk9_move2_string(pk9_t *ptr, char *out, size_t out_size);
  void pk9_move3_string(pk9_t *ptr, char *out, size_t out_size);
  void pk9_move4_string(pk9_t *ptr, char *out, size_t out_size);
  u8 pk9_language(pk9_t *ptr);
  u8 pk9_current_friendship(pk9_t *ptr);
  bool pk9_is_shiny(pk9_t *ptr);
  bool pk9_is_egg(pk9_t *ptr);
  bool find_pk9_raid_seed(u64 *out, pk9_t *ptr);

#ifdef __cplusplus
  }

  class Pk9 : public Pkx {
   public:
    static const size_t StoredSize = 328;

    Pk9(pk9_t *pk9) : m_pk9(pk9) { }
    ~Pk9() { free_pk9(m_pk9); }

    u32 EncryptionConstant() { return pk9_encryption_constant(m_pk9); }

    std::string SpeciesString() {
      char text[13];
      pk9_species_string(m_pk9, text, 13);
      return std::string(text);
    }

    u16 Tid() { return pk9_tid(m_pk9); }

    u16 Sid() { return pk9_sid(m_pk9); }

    std::string AbilityString() {
      char text[17];
      pk9_ability_string(m_pk9, text, 17);
      return std::string(text);
    }

    u8 AbilityNumber() { return pk9_ability_number(m_pk9); }

    u32 Pid() { return pk9_pid(m_pk9); }

    std::string NatureString() {
      char text[8];
      pk9_nature_string(m_pk9, text, 8);
      return std::string(text);
    }

    std::string MintedNatureString() {
      char text[8];
      pk9_minted_nature_string(m_pk9, text, 8);
      return std::string(text);
    }

    u8 Gender() { return pk9_gender(m_pk9); }

    Stats Evs() { return pk9_evs(m_pk9); }

    Stats Ivs() { return pk9_ivs(m_pk9); }

    std::string Move1String() {
      char text[28];
      pk9_move1_string(m_pk9, text, 28);
      return std::string(text);
    }

    std::string Move2String() {
      char text[28];
      pk9_move2_string(m_pk9, text, 28);
      return std::string(text);
    }

    std::string Move3String() {
      char text[28];
      pk9_move3_string(m_pk9, text, 28);
      return std::string(text);
    }

    std::string Move4String() {
      char text[28];
      pk9_move4_string(m_pk9, text, 28);
      return std::string(text);
    }

    u8 CurrentFriendship() { return pk9_current_friendship(m_pk9); }

    u8 Language() { return pk9_language(m_pk9); }

    bool IsShiny() { return pk9_is_shiny(m_pk9); }

    bool IsEgg() { return pk9_is_egg(m_pk9); }

    std::optional<u64> FindRaidSeed() { return std::nullopt; }

   private:
    pk9_t *m_pk9;
  };
};
#endif
