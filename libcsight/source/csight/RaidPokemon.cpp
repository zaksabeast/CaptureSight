#include <string>
#include <csight/RaidPokemon.hpp>
#include <csight/Shiny.hpp>
#include <csight/RNG.hpp>
#include <csight/Shiny.hpp>
#include <csight/Utils.hpp>
#include <csight/lookups/Species.hpp>

namespace csight::raid {
  RaidPokemon::RaidPokemon(u64 seed, u32 flawlessIvs, u16 species) {
    this->species = species;
    auto rng = rng::xoroshiro(seed);
    this->EC = rng.next(0xFFFFFFFF);
    u32 SIDTID = rng.next(0xFFFFFFFF);
    this->PID = rng.next(0xFFFFFFFF);
    this->shineType = shiny::GetShinyType(PID, SIDTID);

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

  std::string RaidPokemon::GetSpeciesString() { return utils::getIndex(SpeciesList, this->GetSpecies()); }

  bool RaidPokemon::GetIsShiny() { return this->shineType > shiny::None; }

  shiny::ShinyType RaidPokemon::GetShineType() { return this->shineType; }

  std::vector<s8> RaidPokemon::GetIVs() { return this->IVs; }
}  // namespace csight::raid