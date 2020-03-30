#pragma once

#include <csight/RaidPokemon.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <memory>
#include <stratosphere.hpp>
#include <string>
#include <switch.h>
#include <vector>

namespace csight::raid {
  class Den {
   public:
    Den(u8 *data, u8 denId, std::vector<RaidEncounterTable> encounterTables,
        std::shared_ptr<RaidEncounterTable> eventEncounterTable);
    ~Den();
    u64 GetSeed();
    u16 GetShinyAdvance();
    std::string GetShinyAdvanceText();
    shiny::ShinyType GetShinyType();
    u8 GetStars();
    u8 GetDisplayStars();
    u8 GetRandRoll();
    u8 GetType();
    u8 GetFlagByte();
    bool GetHasWatts();
    bool GetIsEvent();
    bool GetIsActive();
    u8 GetDenId();
    u8 GetDenDisplayId();
    bool GetIsRare();
    std::shared_ptr<raid::RaidPokemon> GetPKM();

   private:
    u8 m_size = 0x18;
    u8 *m_data = new u8[0x18];
    u8 m_denId = 0;
    u16 m_shinyAdvance = 0;
    RaidEncounter m_spawn;
    shiny::ShinyType m_shineType = shiny::Star;

    raid::RaidEncounter FindSpawn(std::vector<raid::RaidEncounter> raidEncounters);
    void CalculateShinyDetails();
  };
}  // namespace csight::raid
