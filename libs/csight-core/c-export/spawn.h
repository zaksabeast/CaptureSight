#pragma once

#include <memory>
#include <switch.h>
#include <vector>

#ifdef __cplusplus

namespace csight::arceus {
  extern "C" {
#endif
  typedef struct arceus_spawn arceus_spawn_t;

  u64 spawn_get_hash(arceus_spawn_t *ptr);
  u64 spawn_get_seed(arceus_spawn_t *ptr);
  bool spawn_get_is_active(arceus_spawn_t *ptr);
  arceus_spawn_t *free_spawn(arceus_spawn_t *ptr);
  arceus_spawn_t *arceus_read_spawn(size_t index);
  arceus_spawn_t *arceus_read_next_active_spawn(size_t start_index, size_t *found_index);
  size_t arceus_read_active_spawn_count();
  size_t arceus_read_spawn_count();

#ifdef __cplusplus
  }

  class Spawn {
   public:
    static const size_t Size = 0x18;

    Spawn(size_t index, bool find_next_active = false) {
      if (find_next_active) {
        m_spawn = arceus_read_next_active_spawn(index, &m_index);
      } else {
        m_spawn = arceus_read_spawn(index);
        m_index = index;
      }
    }
    ~Spawn() { free_spawn(m_spawn); }

    size_t Index() { return m_index; }

    u64 Hash() { return spawn_get_hash(m_spawn); }

    u64 Seed() { return spawn_get_seed(m_spawn); }

    bool IsActive() { return spawn_get_is_active(m_spawn); }

   private:
    arceus_spawn_t *m_spawn;
    size_t m_index;
  };

  // TODO: clean.  This was super dirty and quick
  std::vector<std::shared_ptr<Spawn>> readActiveSpawns(size_t start_index, size_t end_index) {
    std::vector<std::shared_ptr<Spawn>> result;

    for (size_t next_index = start_index; next_index < end_index;) {
      auto spawn = std::make_shared<Spawn>(next_index, true);

      if (!spawn->IsActive()) {
        break;
      }

      next_index = spawn->Index() + 1;
      result.push_back(spawn);
    }

    return result;
  }
};
#endif
