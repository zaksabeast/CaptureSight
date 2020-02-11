#include <iostream>
#include <vector>
#include <csight/RaidPokemon.hpp>

ulong rotateLeft(ulong first, ulong second) {
  return (first << second) | (first >> (64 - second));
}

ulong rotateRight(ulong first, ulong second) {
  return (first >> second) | (first << (64 - second));
}

// Minimal xoroshiro since we don't need any more than this
std::vector<ulong> xoroshiro(ulong s0, ulong s1) {
  auto temp = s1 ^ s0;
  auto s0_2 = rotateLeft(s0, 24) ^ temp ^ (temp << 16);
  auto s1_2 = rotateLeft(temp, 37);

  return {s0_2, s1_2};
}

namespace csight {
  namespace raid {
    ulong CalculateRaidSeed(uint ec, uint pid, std::vector<s8> ivs) {
      ulong s1 = 0x82A2B175229D6A5B;
      uint pidMask = 0x3FC000;
      uint maskedPID = pid & pidMask;
      ulong s0_low = (ec - s1) & 0xFFFFFFFF;
      ulong temp_low = (s0_low ^ s1) & 0xFFFFFFFF;
      temp_low = temp_low ^ (temp_low << 16);

      // Test the bytes that impact the PID most
      // By picking only the most impactul bytes, we avoid unneeded iterations
      // TODO: choose most impactful bits
      for (ulong i = 0; i <= 0xFF; i++) {
        for (ulong j = 0; j <= 0xFF; j++) {
          auto s0_high = (rotateRight(j ^ temp_low, 24) & 0xFFFFFFFF00000000) | (i << 32);
          auto partialTestSeed = s0_low | s0_high;
          auto res = xoroshiro((partialTestSeed & 0xffffffffffff), s1);  // ec
          res = xoroshiro(res[0], res[1]);                               // sidtid
          auto testPID = (res[0] + res[1]) & pidMask;                    // pid

          // Only compare bits of the PID guaranteed with the missing seed bytes
          if (testPID == maskedPID) {
            for (ulong k = 0; k <= 0xffff; k++) {
              auto seed = (k << 48) + partialTestSeed;
              res = xoroshiro(seed, s1);                           // ec
              res = xoroshiro(res[0], res[1]);                     // sidtid
              auto generatedPID = (res[0] + res[1]) & 0xFFFFFFFF;  // pid

              if (generatedPID == pid) {
                for (uint flawlessIVs = 1; flawlessIVs <= 5; flawlessIVs++) {
                  auto ivsToCheck = RaidPokemon(seed, flawlessIVs, 0).GetIVs();
                  bool hasCorrectIVs = std::equal(ivs.begin(), ivs.end(), ivsToCheck.begin());

                  if (hasCorrectIVs)
                    return seed;
                }
              }
            }
          }
        }
      }

      return 0;
    }
  }  // namespace raid
}  // namespace csight
