#pragma once

#include "generated.h"
#include <array>
#include <string>
#include <switch.h>

namespace csight::swsh {
  class Den {
   public:
    static const size_t Size = 0x18;

    Den(bool is_sword, size_t index, SwshDenType den_type) { m_den = swsh_read_den(is_sword, index, den_type); }
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
