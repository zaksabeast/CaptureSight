#pragma once

#include "pk8.h"
#include "rng_tracker.h"
#include "trainer_info.h"

#ifdef __cplusplus
#include <memory>

namespace csight::swsh {
  extern "C" {
#endif

  void swsh_read_trainer_info(TrainerInfo *out);
  pk8_t *swsh_read_party_pokemon(u8 index);
  pk8_t *swsh_read_wild_pokemon();
  pk8_t *swsh_read_wild_legend_pokemon();
  pk8_t *swsh_read_trade_pokemon();
  pk8_t *swsh_read_raid_pokemon();
  xoroshiro_tracker_t *swsh_get_main_rng_tracker();

#ifdef __cplusplus
  }

  std::shared_ptr<Pk8> read_party_pokemon(u8 index) { return std::make_shared<Pk8>(swsh_read_party_pokemon(index)); }
  std::shared_ptr<Pk8> read_wild_pokemon() { return std::make_shared<Pk8>(swsh_read_wild_pokemon()); }
  std::shared_ptr<Pk8> read_wild_legend_pokemon() { return std::make_shared<Pk8>(swsh_read_wild_legend_pokemon()); }
  std::shared_ptr<Pk8> read_trade_pokemon() { return std::make_shared<Pk8>(swsh_read_trade_pokemon()); }
  std::shared_ptr<Pk8> read_raid_pokemon() { return std::make_shared<Pk8>(swsh_read_raid_pokemon()); }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)swsh_get_main_rng_tracker(), RngType::Xoroshiro);
  }

  std::shared_ptr<TrainerInfo> read_trainer_info() {
    TrainerInfo trainer_info;
    swsh_read_trainer_info(&trainer_info);
    return std::make_shared<TrainerInfo>(trainer_info);
  }
};
#endif
