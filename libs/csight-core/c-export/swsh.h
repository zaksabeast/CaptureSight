#pragma once

#include "generated.h"
#include "pkx.h"
#include "rng_tracker.h"
#include <memory>

namespace csight::swsh {
  std::shared_ptr<Pk8> read_party_pokemon(u8 index) {
    return std::make_shared<Pk8>(swsh_read_party_pokemon(index));
  }
  std::shared_ptr<Pk8> read_wild_pokemon() {
    return std::make_shared<Pk8>(swsh_read_wild_pokemon());
  }
  std::shared_ptr<Pk8> read_wild_legend_pokemon() {
    return std::make_shared<Pk8>(swsh_read_wild_legend_pokemon());
  }
  std::shared_ptr<Pk8> read_trade_pokemon() {
    return std::make_shared<Pk8>(swsh_read_trade_pokemon());
  }
  std::shared_ptr<Pk8> read_raid_pokemon() {
    return std::make_shared<Pk8>(swsh_read_raid_pokemon());
  }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)swsh_get_main_rng_tracker(), RngType::Xoroshiro);
  }

  std::shared_ptr<TrainerInfo> read_trainer_info() {
    TrainerInfo trainer_info;
    swsh_read_trainer_info(&trainer_info);
    return std::make_shared<TrainerInfo>(trainer_info);
  }
};
