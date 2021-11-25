#pragma once

#include "den.h"
#include "lcrng.h"
#include "pk8.h"
#include "xoroshiro.h"
#include "xorshift.h"
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
