#include <csight/Ability.hpp>
#include <csight/RaidPokemon.hpp>
#include <future>
#include <iostream>
#include <vector>

u64 rotateLeft(u64 first, u64 second) {
  return (first << second) | (first >> (64 - second));
}

u64 rotateRight(u64 first, u64 second) {
  return (first >> second) | (first << (64 - second));
}

// Minimal xoroshiro since we don't need any more than this
std::vector<u64> xoroshiro(u64 s0, u64 s1) {
  auto temp = s1 ^ s0;
  auto s0_2 = rotateLeft(s0, 24) ^ temp ^ (temp << 16);
  auto s1_2 = rotateLeft(temp, 37);

  return { s0_2, s1_2 };
}

namespace csight::raid {
  u64 calculateRaidSeed(u32 ec, u32 pid, std::vector<u8> ivs) {
    u64 s1 = 0x82A2B175229D6A5B;
    u32 pidMask = 0x3FC000;
    u32 maskedPID = pid & pidMask;
    u64 s0_low = (ec - s1) & 0xFFFFFFFF;
    u64 temp_low = (s0_low ^ s1) & 0xFFFFFFFF;
    temp_low = temp_low ^ (temp_low << 16);

    // Test the bytes that impact the PID most
    // By picking only the most impactful bytes, we avoid unneeded iterations
    // TODO: choose most impactful bits
    for (u64 i = 0; i <= 0xFF; i++) {
      for (u64 j = 0; j <= 0xFF; j++) {
        auto s0_high = (rotateRight(j ^ temp_low, 24) & 0xFFFFFFFF00000000) | (i << 32);
        auto partialTestSeed = s0_low | s0_high;
        auto res = xoroshiro((partialTestSeed & 0xffffffffffff), s1);  // ec
        res = xoroshiro(res[0], res[1]);  // sidtid
        auto testPID = (res[0] + res[1]) & pidMask;  // pid

        // Only compare bits of the PID guaranteed with the missing seed bytes
        if (testPID == maskedPID) {
          // tmp spawn for testing generated IVs
          RaidEncounter spawn = {
            species : 1,
            flawlessIVs : 1,
            ability : ability::raid::FirstOrSecond,
            form : 0,
            probabilities : {},
            shinyType : csight::shiny::ShinyRaidSetting::Random
          };
          for (u64 k = 0; k <= 0xffff; k++) {
            auto seed = (k << 48) + partialTestSeed;
            res = xoroshiro(seed, s1);  // ec
            res = xoroshiro(res[0], res[1]);  // sidtid
            auto generatedPID = (res[0] + res[1]) & 0xFFFFFFFF;  // pid

            if (generatedPID == pid) {
              for (u32 flawlessIVs = 1; flawlessIVs <= 5; flawlessIVs++) {
                spawn.flawlessIVs = flawlessIVs;
                auto ivsToCheck = RaidPokemon(seed, spawn, 0).getIVs();
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

  std::future<u64> calculateRaidSeedAsync(u32 ec, u32 pid, std::vector<u8> ivs) {
    return std::async(&csight::raid::calculateRaidSeed, ec, pid, ivs);
  }
}  // namespace csight::raid
