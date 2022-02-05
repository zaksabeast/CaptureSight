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

  typedef struct pa8 pa8_t;

  void free_pa8(pa8_t *ptr);

  u32 pa8_encryption_constant(pa8_t *ptr);
  void pa8_species_string(pa8_t *ptr, char *out, size_t out_size);
  u16 pa8_tid(pa8_t *ptr);
  u16 pa8_sid(pa8_t *ptr);
  void pa8_ability_string(pa8_t *ptr, char *out, size_t out_size);
  u8 pa8_ability_number(pa8_t *ptr);
  u32 pa8_pid(pa8_t *ptr);
  void pa8_nature_string(pa8_t *ptr, char *out, size_t out_size);
  void pa8_minted_nature_string(pa8_t *ptr, char *out, size_t out_size);
  u8 pa8_gender(pa8_t *ptr);
  Stats pa8_evs(pa8_t *ptr);
  Stats pa8_ivs(pa8_t *ptr);
  void pa8_move1_string(pa8_t *ptr, char *out, size_t out_size);
  void pa8_move2_string(pa8_t *ptr, char *out, size_t out_size);
  void pa8_move3_string(pa8_t *ptr, char *out, size_t out_size);
  void pa8_move4_string(pa8_t *ptr, char *out, size_t out_size);
  u8 pa8_language(pa8_t *ptr);
  u8 pa8_current_friendship(pa8_t *ptr);
  bool pa8_is_shiny(pa8_t *ptr);
  bool pa8_is_egg(pa8_t *ptr);
  bool find_pa8_raid_seed(u64 *out, pa8_t *ptr);

#ifdef __cplusplus
  }

  class Pa8 : public Pkx {
   public:
    static const size_t StoredSize = 328;

    Pa8(pa8_t *pa8) : m_pa8(pa8) { }
    ~Pa8() { free_pa8(m_pa8); }

    u32 EncryptionConstant() { return pa8_encryption_constant(m_pa8); }

    std::string SpeciesString() {
      char text[13];
      pa8_species_string(m_pa8, text, 13);
      return std::string(text);
    }

    u16 Tid() { return pa8_tid(m_pa8); }

    u16 Sid() { return pa8_sid(m_pa8); }

    std::string AbilityString() {
      char text[17];
      pa8_ability_string(m_pa8, text, 17);
      return std::string(text);
    }

    u8 AbilityNumber() { return pa8_ability_number(m_pa8); }

    u32 Pid() { return pa8_pid(m_pa8); }

    std::string NatureString() {
      char text[8];
      pa8_nature_string(m_pa8, text, 8);
      return std::string(text);
    }

    std::string MintedNatureString() {
      char text[8];
      pa8_minted_nature_string(m_pa8, text, 8);
      return std::string(text);
    }

    u8 Gender() { return pa8_gender(m_pa8); }

    Stats Evs() { return pa8_evs(m_pa8); }

    Stats Ivs() { return pa8_ivs(m_pa8); }

    std::string Move1String() {
      char text[28];
      pa8_move1_string(m_pa8, text, 28);
      return std::string(text);
    }

    std::string Move2String() {
      char text[28];
      pa8_move2_string(m_pa8, text, 28);
      return std::string(text);
    }

    std::string Move3String() {
      char text[28];
      pa8_move3_string(m_pa8, text, 28);
      return std::string(text);
    }

    std::string Move4String() {
      char text[28];
      pa8_move4_string(m_pa8, text, 28);
      return std::string(text);
    }

    u8 CurrentFriendship() { return pa8_current_friendship(m_pa8); }

    u8 Language() { return pa8_language(m_pa8); }

    bool IsShiny() { return pa8_is_shiny(m_pa8); }

    bool IsEgg() { return pa8_is_egg(m_pa8); }

    std::optional<u64> FindRaidSeed() { return std::nullopt; }

   private:
    pa8_t *m_pa8;
  };
};
#endif
