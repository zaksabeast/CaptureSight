#pragma once

#include <string>
#include <memory>
#include <vector>
#include <switch.h>
#include <stratosphere.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/RaidTemplateTables.hpp>

namespace csight::raid {
  class Den {
   public:
    Den(u8* data, u8 denId, std::vector<RaidEncounterTable> encounterTables, std::shared_ptr<RaidEncounterTable> eventEncounterTable);
    ~Den();
    u64 GetSeed();
    u16 GetShinyFrame();
    std::string GetShinyFrameText();
    shiny::ShinyType GetShineType();
    u8 GetStars();
    u8 GetDisplayStars();
    u8 GetRandRoll();
    u8 GetType();
    u8 GetFlagByte();
    bool GetHasWatts();
    bool GetIsEvent();
    bool GetIsActive();
    u8 GetDenId();
    bool GetIsRare();
    std::shared_ptr<raid::RaidPokemon> GetPKM();

   private:
    u8 size = 0x18;
    u8* data = new u8[0x18];
    u8 denId = 0;
    u16 species = 0;
    u8 flawlessIVs = 0;
    u16 shinyFrame = 0;
    shiny::ShinyType shineType = shiny::Star;
    raid::RaidEncounter FindSpawn(std::vector<raid::RaidEncounter> raidEncounters);
    void CalculateShinyDetails();
  };
}  // namespace csight::raid
