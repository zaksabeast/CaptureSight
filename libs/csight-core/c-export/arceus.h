#pragma once

#include "pk9.h"
#include "rng_tracker.h"

#ifdef __cplusplus
#include <memory>
#include <vector>

namespace csight::arceus {
  extern "C" {
#endif

  pk9_t *arceus_read_party_pokemon(u8 index);
  pk9_t *arceus_read_wild_pokemon(u8 index);
  u8 arceus_read_wild_pokemon_count();
  xoroshiro_tracker_t *arceus_get_main_rng_tracker();

#ifdef __cplusplus
  }

  std::shared_ptr<Pk9> read_party_pokemon(u8 index) { return std::make_shared<Pk9>(arceus_read_party_pokemon(index)); }

  std::vector<std::shared_ptr<Pk9>> read_wild_pokemon() {
    u64 count = arceus_read_wild_pokemon_count();
    std::vector<std::shared_ptr<Pk9>> result;

    for (u64 i = 0; i < count; i++) {
      auto pkm = std::make_shared<Pk9>(arceus_read_wild_pokemon(i));
      result.push_back(pkm);
    }

    return result;
  }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)arceus_get_main_rng_tracker(), RngType::Xoroshiro);
  }
};
#endif
