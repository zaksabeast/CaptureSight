#pragma once

#include "generated.h"
#include "pkx.h"
#include "rng_tracker.h"
#include <memory>
#include <vector>

namespace csight::arceus {
  std::shared_ptr<Pa8> read_party_pokemon(u8 index) {
    return std::make_shared<Pa8>(arceus_read_party_pokemon(index));
  }

  std::vector<std::shared_ptr<Pa8>> read_wild_pokemon() {
    u64 count = arceus_read_wild_pokemon_count();
    std::vector<std::shared_ptr<Pa8>> result;

    for (u64 i = 0; i < count; i++) {
      auto pkm = std::make_shared<Pa8>(arceus_read_wild_pokemon(i));
      result.push_back(pkm);
    }

    return result;
  }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)arceus_get_main_rng_tracker(), RngType::Xoroshiro);
  }
};
