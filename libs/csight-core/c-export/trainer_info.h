#pragma once

#include <switch.h>

#ifdef __cplusplus

namespace csight {
  extern "C" {
#endif

  struct TrainerInfo {
    u16 tid;
    u16 sid;
  } trainer_info;

#ifdef __cplusplus
  }
};
#endif
