#pragma once

#include <switch.h>

#ifdef __cplusplus

#include <array>
#include <string>
namespace csight {
  extern "C" {
#endif
  typedef struct xorshift xorshift_t;

  xorshift_t *get_xorshift(u32 s0, u32 s1, u32 s2, u32 s3);
  void free_xorshift(xorshift_t *ptr);

  u64 xorshift_advance_to_state(xorshift_t *ptr, u32 s0, u32 s1, u32 s2, u32 s3);

#ifdef __cplusplus
  }

  class Xorshift {
   public:
    static const size_t StateCount = 4;
    typedef u32 StateItem;
    typedef std::array<Xorshift::StateItem, Xorshift::StateCount> State;

    Xorshift(Xorshift::State state) { m_xorshift = get_xorshift(state[0], state[1], state[2], state[3]); }
    ~Xorshift() { free_xorshift(m_xorshift); }

    u64 AdvanceToState(Xorshift::State state) {
      return xorshift_advance_to_state(m_xorshift, state[0], state[1], state[2], state[3]);
    }

   private:
    xorshift_t *m_xorshift;
  };
};
#endif
