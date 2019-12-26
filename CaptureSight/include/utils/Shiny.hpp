#pragma once

#include <switch.h>

enum ShinyType {
  None = 0,
  Star = 1,
  Square = 2,
};

u32 GetShinyValue(u32 value);
ShinyType GetShinyType(u32 PID, u32 SIDTID);