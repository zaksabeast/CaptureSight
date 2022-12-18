#pragma once

#include "arceus.h"
#include "bdsp.h"
#include "den.h"
#include "rng_tracker.h"
#include "spawn.h"
#include "sv.h"
#include "swsh.h"
#include <switch.h>

#ifdef __cplusplus
namespace csight {
  extern "C" {
#endif
  typedef struct switch_reader switch_reader_t;

  void init();

#ifdef __cplusplus
  }
};
#endif
