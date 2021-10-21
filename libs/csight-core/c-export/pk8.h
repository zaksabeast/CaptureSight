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

  typedef struct pk8 pk8_t;

  pk8_t *get_pk8(u8 bytes[328]);
  void free_pk8(pk8_t *ptr);

  u32 pk8_encryption_constant(pk8_t *ptr);
  void pk8_species_string(pk8_t *ptr, char *out, size_t out_size);
  u16 pk8_tid(pk8_t *ptr);
  u16 pk8_sid(pk8_t *ptr);
  void pk8_ability_string(pk8_t *ptr, char *out, size_t out_size);
  u8 pk8_ability_number(pk8_t *ptr);
  u32 pk8_pid(pk8_t *ptr);
  void pk8_nature_string(pk8_t *ptr, char *out, size_t out_size);
  void pk8_minted_nature_string(pk8_t *ptr, char *out, size_t out_size);
  u8 pk8_gender(pk8_t *ptr);
  Stats pk8_evs(pk8_t *ptr);
  Stats pk8_ivs(pk8_t *ptr);
  void pk8_move1_string(pk8_t *ptr, char *out, size_t out_size);
  void pk8_move2_string(pk8_t *ptr, char *out, size_t out_size);
  void pk8_move3_string(pk8_t *ptr, char *out, size_t out_size);
  void pk8_move4_string(pk8_t *ptr, char *out, size_t out_size);
  u8 pk8_language(pk8_t *ptr);
  u8 pk8_current_friendship(pk8_t *ptr);
  bool pk8_is_shiny(pk8_t *ptr);
  bool pk8_is_egg(pk8_t *ptr);
  bool find_pk8_raid_seed(u64 *out, pk8_t *ptr);

#ifdef __cplusplus
  }

  class Pk8 : public Pkx {
   public:
    static const size_t StoredSize = 328;

    Pk8(std::array<u8, Pk8::StoredSize> bytes) : m_pk8(get_pk8(bytes.data())) { }
    ~Pk8() { free_pk8(m_pk8); }

    u32 EncryptionConstant() { return pk8_encryption_constant(m_pk8); }

    std::string SpeciesString() {
      char text[13];
      pk8_species_string(m_pk8, text, 13);
      return std::string(text);
    }

    u16 Tid() { return pk8_tid(m_pk8); }

    u16 Sid() { return pk8_sid(m_pk8); }

    std::string AbilityString() {
      char text[17];
      pk8_ability_string(m_pk8, text, 17);
      return std::string(text);
    }

    u8 AbilityNumber() { return pk8_ability_number(m_pk8); }

    u32 Pid() { return pk8_pid(m_pk8); }

    std::string NatureString() {
      char text[8];
      pk8_nature_string(m_pk8, text, 8);
      return std::string(text);
    }

    std::string MintedNatureString() {
      char text[8];
      pk8_minted_nature_string(m_pk8, text, 8);
      return std::string(text);
    }

    u8 Gender() { return pk8_gender(m_pk8); }

    Stats Evs() { return pk8_evs(m_pk8); }

    Stats Ivs() { return pk8_ivs(m_pk8); }

    std::string Move1String() {
      char text[28];
      pk8_move1_string(m_pk8, text, 28);
      return std::string(text);
    }

    std::string Move2String() {
      char text[28];
      pk8_move2_string(m_pk8, text, 28);
      return std::string(text);
    }

    std::string Move3String() {
      char text[28];
      pk8_move3_string(m_pk8, text, 28);
      return std::string(text);
    }

    std::string Move4String() {
      char text[28];
      pk8_move4_string(m_pk8, text, 28);
      return std::string(text);
    }

    u8 CurrentFriendship() { return pk8_current_friendship(m_pk8); }

    u8 Language() { return pk8_language(m_pk8); }

    bool IsShiny() { return pk8_is_shiny(m_pk8); }

    bool IsEgg() { return pk8_is_egg(m_pk8); }

    std::optional<u64> FindRaidSeed() {
      u64 seed = 0;
      bool is_found = find_pk8_raid_seed(&seed, m_pk8);

      if (is_found) {
        return std::optional<u64>(seed);
      }

      return std::nullopt;
    }

   private:
    pk8_t *m_pk8;
  };
};
#endif
