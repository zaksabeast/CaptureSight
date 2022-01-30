#pragma once

#include "pk9.h"
#include "rng_tracker.h"

#ifdef __cplusplus
#include <memory>

namespace csight::arceus {
  extern "C" {
#endif

  pk9_t *arceus_read_party_pokemon(u8 index);
  pk9_t *arceus_read_wild_pokemon();
  xoroshiro_tracker_t *arceus_get_main_rng_tracker();

#ifdef __cplusplus
  }

  std::shared_ptr<Pk9> read_party_pokemon(u8 index) { return std::make_shared<Pk9>(arceus_read_party_pokemon(index)); }

  std::shared_ptr<Pk9> read_wild_pokemon() { return std::make_shared<Pk9>(arceus_read_wild_pokemon()); }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)arceus_get_main_rng_tracker(), RngType::Xoroshiro);
  }
};
#endif
