#include <csight/RaidPokemon.hpp>
#include <csight/Shiny.hpp>
#include <csight/RNG.hpp>

namespace csight {
  namespace raid {
    RaidPokemon::RaidPokemon(u64 seed, u32 flawlessIvs, u16 species) {
      this->species = species;
      auto rng = rng::xoroshiro(seed);
      this->EC = rng.next(0xFFFFFFFF);
      u32 SIDTID = rng.next(0xFFFFFFFF);
      this->PID = rng.next(0xFFFFFFFF);
      this->isShiny = GetShinyType(PID, SIDTID) > None;

      this->IVs = {-1, -1, -1, -1, -1, -1};

      for (u32 i = 0; i < flawlessIvs; i++) {
        s32 ivIndex;

        do {
          ivIndex = (s32)rng.next(7);
        } while (this->IVs[ivIndex] != -1);

        this->IVs[ivIndex] = 31;
      }

      for (s32 i = 0; i < 6; i++) {
        if (this->IVs[i] == -1) {
          this->IVs[i] = (s8)rng.next(31);
        }
      }
    }

    u32 RaidPokemon::GetEC() { return this->EC; }

    u32 RaidPokemon::GetPID() { return this->PID; }

    u16 RaidPokemon::GetSpecies() { return this->species; }

    bool RaidPokemon::GetIsShiny() { return this->isShiny; }

    std::vector<s8> RaidPokemon::GetIVs() { return this->IVs; }
  }  // namespace raid
}  // namespace csight