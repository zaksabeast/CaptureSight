#pragma once

#include <switch.h>

#ifdef __cplusplus

#include <array>
#include <string>
namespace csight {
  extern "C" {
#endif
  typedef struct xoroshiro xoroshiro_t;

  xoroshiro_t *get_xoroshiro(u64 s0, u64 s1);
  void free_xoroshiro(xoroshiro_t *ptr);

  u64 xoroshiro_advance_to_state(xoroshiro_t *ptr, u64 s0, u64 s1);

#ifdef __cplusplus
  }

  class Xoroshiro {
   public:
    Xoroshiro(u64 s0, u64 s1) { m_xoroshiro = get_xoroshiro(s0, s1); }
    ~Xoroshiro() { free_xoroshiro(m_xoroshiro); }

    u64 AdvanceToState(u64 s0, u64 s1) { return xoroshiro_advance_to_state(m_xoroshiro, s0, s1); }

   private:
    xoroshiro_t *m_xoroshiro;
  };
};
#endif
