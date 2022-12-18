#pragma once

#include "generated.h"
#include <switch.h>
#include <vector>

namespace csight {
  class RngTracker {
   public:
    RngTracker(void *tracker, RngType rng_type) : m_tracker(tracker), m_rng_type(rng_type) { }
    ~RngTracker() { free_rng_tracker(m_tracker, m_rng_type); }

    u64 GetAdvances() { return get_rng_tracker_advances(m_tracker, m_rng_type); }

    size_t GetStateCount() { return get_rng_tracker_state_count(m_rng_type); }

    size_t GetStateItemSize() { return get_rng_tracker_state_item_size(m_rng_type); }

    std::vector<u64> ReadState() {
      u64 states[4] = { 0 };
      size_t out_count = 0;
      size_t max_out = 4;

      read_rng_tracker_state(states, &out_count, max_out, m_tracker, m_rng_type);

      std::vector<u64> result;

      for (size_t i = 0; i < out_count; i++) {
        result.push_back(states[i]);
      }

      return result;
    }

   private:
    void *m_tracker;
    RngType m_rng_type;
  };
};
