#include <vector>
#include <switch.h>

namespace raid {
  ulong CalculateRaidSeed(uint ec, uint pid, std::vector<s8> ivs);
}  // namespace raid