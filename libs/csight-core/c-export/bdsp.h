#pragma once

#include "pk8.h"
#include "rng_tracker.h"
#include "trainer_info.h"

#ifdef __cplusplus
#include <memory>

namespace csight::bdsp {
  extern "C" {
#endif

  struct EggDetails {
    bool exists;
    u64 seed;
    s32 stepCount;
  };

  static_assert(sizeof(struct EggDetails) == 24);

  // MV_POKE_DATA
  struct Roamer {
    s32 area_id;
    u32 rng_seed_low;
    u32 rng_seed_high;
    u32 species;
    u32 hp;
    u8 level;
    u32 status;
    u8 encounter_status;
  };

  static_assert(sizeof(struct Roamer) == 32);

  void bdsp_read_trainer_info(TrainerInfo *out);
  void bdsp_read_egg_details(EggDetails *out);
  pk8_t *bdsp_read_wild_pokemon();
  pk8_t *bdsp_read_party_pokemon(u8 index);
  pk8_t *bdsp_read_other_player_union_trade_pokemon();
  size_t bdsp_read_underground_pokemon_count();
  pk8_t *bdsp_read_underground_pokemon(size_t index);
  size_t bdsp_read_roamer_count();
  void bdsp_read_roamer(Roamer *out, size_t index);

  xorshift_tracker_t *bdsp_get_main_rng_tracker();
  lcrng_tracker_t *bdsp_get_random_group_rng_tracker(size_t index);

#ifdef __cplusplus
  }

  std::shared_ptr<TrainerInfo> read_trainer_info() {
    TrainerInfo trainer_info;
    bdsp_read_trainer_info(&trainer_info);
    return std::make_shared<TrainerInfo>(trainer_info);
  }

  std::shared_ptr<EggDetails> read_egg_details() {
    EggDetails egg_details;
    bdsp_read_egg_details(&egg_details);
    return std::make_shared<EggDetails>(egg_details);
  }

  std::shared_ptr<Pk8> read_wild_pokemon() { return std::make_shared<Pk8>(bdsp_read_wild_pokemon()); }

  std::shared_ptr<Pk8> read_party_pokemon(u8 index) { return std::make_shared<Pk8>(bdsp_read_party_pokemon(index)); }
  std::shared_ptr<Pk8> read_underground_pokemon(u8 index) { return std::make_shared<Pk8>(bdsp_read_underground_pokemon(index)); }
  std::shared_ptr<Pk8> read_other_player_union_trade_pokemon() {
    return std::make_shared<Pk8>(bdsp_read_other_player_union_trade_pokemon());
  }

  std::vector<std::shared_ptr<Pk8>> read_underground_pokemon() {
    std::vector<std::shared_ptr<Pk8>> result;
    auto count = bdsp_read_underground_pokemon_count();

    for (size_t i = 0; i < count; i++) {
      result.push_back(read_underground_pokemon(i));
    }

    return result;
  }

  std::vector<Roamer> read_roamers() {
    std::vector<Roamer> result;
    auto count = bdsp_read_roamer_count();

    for (size_t i = 0; i < count; i++) {
      Roamer roamer;
      bdsp_read_roamer(&roamer, i);
      result.push_back(roamer);
    }

    return result;
  }

  std::shared_ptr<RngTracker> get_main_rng_tracker() {
    return std::make_shared<RngTracker>((void *)bdsp_get_main_rng_tracker(), RngType::Xorshift);
  }

  std::shared_ptr<RngTracker> get_random_group_rng_tracker(size_t index) {
    return std::make_shared<RngTracker>((void *)bdsp_get_random_group_rng_tracker(index), RngType::Lcrng);
  }
};
#endif
