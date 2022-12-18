#pragma once

#include "generated.h"
#include "pkx.h"
#include "rng_tracker.h"
#include <memory>

namespace csight::bdsp {
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

  std::shared_ptr<Pk8> read_encounter_pokemon(u8 index) {
    return std::make_shared<Pk8>(bdsp_read_encounter_pokemon(index));
  }
  u64 read_encounter_pokemon_count() {
    return bdsp_read_encounter_pokemon_count();
  }
  std::shared_ptr<Pk8> read_party_pokemon(u8 index) {
    return std::make_shared<Pk8>(bdsp_read_party_pokemon(index));
  }
  u64 read_party_pokemon_count() {
    return bdsp_read_party_pokemon_count();
  }
  std::shared_ptr<Pk8> read_underground_pokemon(u8 index) {
    return std::make_shared<Pk8>(bdsp_read_underground_pokemon(index));
  }
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

  std::vector<BdspRoamer> read_roamers() {
    std::vector<BdspRoamer> result;
    auto count = bdsp_read_roamer_count();

    for (size_t i = 0; i < count; i++) {
      BdspRoamer roamer;
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
