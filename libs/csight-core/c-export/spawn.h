#pragma once

#include <array>
#include <memory>
#include <switch.h>

#ifdef __cplusplus

namespace csight::arceus {
  extern "C" {
#endif
  typedef struct arceus_spawn_group arceus_spawn_group_t;

  arceus_spawn_group_t *free_spawn_group(arceus_spawn_group_t *ptr);
  void spawn_group_get_spawn_pair_seeds(arceus_spawn_group_t *ptr, u64 *seed0, u64 *seed1, size_t index);
  u64 spawn_group_get_seed(arceus_spawn_group_t *ptr);
  arceus_spawn_group_t *arceus_read_spawn_group(size_t index);
  arceus_spawn_group_t *arceus_read_next_active_spawn(size_t start_index, size_t *found_index);
  size_t arceus_read_spawn_group_count();
  size_t arceus_read_active_spawn_group_count();

#ifdef __cplusplus
  }

  typedef std::array<u64, 2> SpawnSeedPair;

  class SpawnGroup {
   public:
    SpawnGroup(size_t index) {
      m_spawn_group = arceus_read_spawn_group(index);
      m_index = index;
    }
    ~SpawnGroup() { free_spawn_group(m_spawn_group); }

    size_t Index() { return m_index; }

    SpawnSeedPair SpawnPairSeeds(size_t index) {
      u64 seed0 = 0;
      u64 seed1 = 0;
      spawn_group_get_spawn_pair_seeds(m_spawn_group, &seed0, &seed1, index);

      return { seed0, seed1 };
    }

    std::array<SpawnSeedPair, 8> SpawnPairsSeeds() {
      return {
        this->SpawnPairSeeds(0), this->SpawnPairSeeds(1), this->SpawnPairSeeds(2), this->SpawnPairSeeds(3),
        this->SpawnPairSeeds(4), this->SpawnPairSeeds(5), this->SpawnPairSeeds(6), this->SpawnPairSeeds(7),
      };
    }

    u64 Seed() { return spawn_group_get_seed(m_spawn_group); }

   private:
    arceus_spawn_group_t *m_spawn_group;
    size_t m_index;
  };
};
#endif
