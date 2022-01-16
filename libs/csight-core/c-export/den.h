#pragma once

#include <switch.h>

#ifdef __cplusplus

#include <array>
#include <string>
namespace csight::swsh {
  extern "C" {
#endif
  typedef struct den den_t;

  enum DenType {
    Vanilla = 0,
    IslandOfArmor = 1,
    CrownTundra = 2,
  };

  den_t *swsh_read_den(bool is_sword, size_t index, DenType den_type);
  void free_den(den_t *ptr);
  void den_shiny_details_string(den_t *ptr, char *out, size_t out_size);
  void den_species_string(den_t *ptr, char *out, size_t out_size);
  bool den_is_event(den_t *ptr);
  bool den_is_active(den_t *ptr);
  u64 den_seed(den_t *ptr);

#ifdef __cplusplus
  }

  class Den {
   public:
    static const size_t Size = 0x18;

    Den(bool is_sword, size_t index, DenType den_type) { m_den = swsh_read_den(is_sword, index, den_type); }
    ~Den() { free_den(m_den); }

    std::string ShinyDetailsString() {
      char text[16];
      den_shiny_details_string(m_den, text, 16);
      return std::string(text);
    }

    std::string SpeciesString() {
      char text[17];
      den_species_string(m_den, text, 17);
      return std::string(text);
    }

    bool IsEvent() { return den_is_event(m_den); }

    bool IsActive() { return den_is_active(m_den); }

    u64 Seed() { return den_seed(m_den); }

   private:
    den_t *m_den;
  };
};
#endif
