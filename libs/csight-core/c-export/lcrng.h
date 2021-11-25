#pragma once

#include <switch.h>

#ifdef __cplusplus

#include <array>
#include <string>
namespace csight {
  extern "C" {
#endif
  typedef struct lcrng lcrng_t;

  lcrng_t *get_lcrng(u64 state);
  void free_lcrng(lcrng_t *ptr);

  u64 lcrng_advance_to_state(lcrng_t *ptr, u64 state);

#ifdef __cplusplus
  }

  class Lcrng {
   public:
    static const size_t StateCount = 1;
    typedef u64 StateItem;
    typedef std::array<Lcrng::StateItem, Lcrng::StateCount> State;

    Lcrng(Lcrng::State state) { m_lcrng = get_lcrng(state[0]); }
    ~Lcrng() { free_lcrng(m_lcrng); }

    u64 AdvanceToState(Lcrng::State state) { return lcrng_advance_to_state(m_lcrng, state[0]); }

   private:
    lcrng_t *m_lcrng;
  };
};
#endif
