#pragma once

#include "../constants.hpp"
#include "./debug.hpp"
#include "./general.hpp"
#include <algorithm>
#include <csight-core.h>
#include <vector>

namespace bdsp {

  struct __attribute__((__packed__)) EggDetails {
    bool exists;
    u8 padding[3];
    u64 seed;
    s32 stepCount;
  };

  static_assert(sizeof(struct EggDetails) == 0x10);

  struct __attribute__((__packed__)) Roamer {
    s32 area_id;
    u64 rng_seed;
    u32 species;
    u32 hp;
    u8 level;
    u8 padding_1[3];
    u32 status;
    u8 encounter_status;
    u8 padding_2[3];
  };

  static_assert(sizeof(struct Roamer) == 0x20);

  namespace utils {
    u64 get_player_prefs_provider() {
      u64 tmp = dbg::ReadCheatProcessNso<u64>(bdsp::Offsets::PlayerPrefsProviderInstance);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x18);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0xc0);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x28);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0xb8);
      return dbg::ReadCheatProcess<u64>(tmp);
    }

    u64 get_field_manager_addr() {
      u64 tmp = dbg::ReadCheatProcessNso<u64>(bdsp::Offsets::FieldManager);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0xb8);
      return dbg::ReadCheatProcess<u64>(tmp);
    }

    u64 get_union_room_manager() {
      u64 tmp = dbg::ReadCheatProcessNso<u64>(bdsp::Offsets::UnionRoomManager);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x18);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0xb8);
      return dbg::ReadCheatProcess<u64>(tmp);
    }

    u64 get_battle_setup_param_addr() { return dbg::ReadCheatProcess<u64>(get_player_prefs_provider() + 0x7e8); }

    u64 get_read_player_party_addr() { return dbg::ReadCheatProcess<u64>(get_player_prefs_provider() + 0x7f0); }

    u64 get_daycare_addr() { return get_player_prefs_provider() + 0x450; }

    u64 get_random_group_addr() { return dbg::ReadCheatProcess<u64>(get_player_prefs_provider() + 0x348); }

    std::shared_ptr<csight::Pkx> read_pokemon_from_poke_param(u64 address) {
      u64 tmp = dbg::ReadCheatProcess<u64>(address + 0x20);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x18);
      return ::utils::read_pkx(tmp + 0x20);
    }

    std::shared_ptr<csight::Pkx> read_pokemon_in_party(u64 address, size_t index) {
      u64 tmp = dbg::ReadCheatProcess<u64>(address + 0x10);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x20 + (8 * index));
      return read_pokemon_from_poke_param(tmp);
    }

    std::shared_ptr<csight::Pkx> read_party_pokemon(size_t index) {
      u64 address = get_read_player_party_addr();
      return read_pokemon_in_party(address, index);
    }

    std::shared_ptr<csight::Pkx> read_wild_pokemon() {
      u64 address = get_battle_setup_param_addr();
      u64 tmp = dbg::ReadCheatProcess<u64>(address + 0x58);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x28);
      return read_pokemon_in_party(tmp, 0);
    }

    std::shared_ptr<EggDetails> read_egg_data() {
      EggDetails default_egg_details = {
        exists : false,
        seed : 0,
        stepCount : 0,
      };
      u64 address = get_daycare_addr();
      auto egg_details = dbg::ReadCheatProcess<EggDetails>(address + 8, default_egg_details);
      return std::make_shared<EggDetails>(egg_details);
    }

    u64 read_underground_main_proc_addr() {
      u64 tmp = get_field_manager_addr();
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0xa8);
      return dbg::ReadCheatProcess<u64>(tmp + 0x10);
    }

    std::vector<std::shared_ptr<csight::Pkx>> read_underground_pokemon() {
      u64 tmp = read_underground_main_proc_addr();
      u8 read_size = dbg::ReadCheatProcess<u8>(tmp + 0x18);
      u8 size = std::min(read_size, (u8)15);
      tmp = dbg::ReadCheatProcess<u64>(tmp + 0x10);
      std::vector<std::shared_ptr<csight::Pkx>> result;

      result.reserve(size);

      for (u8 i = 0; i < size; i++) {
        u64 pkx_addr = dbg::ReadCheatProcess<u64>(tmp + 0x20 + (8 * i));
        pkx_addr = dbg::ReadCheatProcess<u64>(pkx_addr + 0x10);
        pkx_addr = dbg::ReadCheatProcess<u64>(pkx_addr + 0x10);
        auto pkx = ::utils::read_pkx(pkx_addr + 0x20);
        result.push_back(pkx);
      }

      return result;
    }

    u64 get_random_group_state_addr(size_t index) {
      u64 addr = get_random_group_addr();
      return addr + (index * 0x38) + 0x40;
    }

    std::shared_ptr<::utils::TrainerInfo> read_trainer_info() {
      u32 sidtid = dbg::ReadCheatProcess<u32>(get_player_prefs_provider() + 0xe8);
      return ::utils::get_trainer_info(sidtid);
    }

    std::shared_ptr<csight::Pkx> read_other_player_union_trade_pokemon() {
      u64 union_trade_manager_addr = dbg::ReadCheatProcess<u64>(get_union_room_manager() + 0x108);
      u64 trade_select_model_addr = dbg::ReadCheatProcess<u64>(union_trade_manager_addr + 0x28);
      u64 poke_param_addr = dbg::ReadCheatProcess<u64>(trade_select_model_addr + 0x70);
      return read_pokemon_from_poke_param(poke_param_addr);
    }

    std::vector<Roamer> read_roamers() {
      u64 roamer_list = dbg::ReadCheatProcess<u64>(get_player_prefs_provider() + 0x2a0);
      u32 read_size = dbg::ReadCheatProcess<u32>(roamer_list + 0x18);
      // This is hardcoded to be 2,
      // but we'll do this just in case the
      // roamer list ever expands in the future
      u32 size = std::min(read_size, (u32)10);

      std::vector<Roamer> result;
      result.reserve(size);

      for (u32 i = 0; i < size; i++) {
        result.push_back(dbg::ReadCheatProcess<Roamer>(roamer_list + 0x20 + (sizeof(struct Roamer) * i), Roamer {
          area_id : 0,
          rng_seed : 0,
          species : 0,
          hp : 0,
          level : 0,
          status : 0,
          encounter_status : 0,
        }));
      }

      return result;
    }
  }
}
