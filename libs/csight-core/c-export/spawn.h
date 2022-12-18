#pragma once

#include "generated.h"
#include <array>
#include <memory>
#include <switch.h>

namespace csight::arceus {
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
