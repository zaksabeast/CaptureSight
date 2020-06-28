#pragma once

#include <csight/RaidPokemon.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <memory>
#include <string>
#include <switch.h>
#include <vector>

#define FIRST_IOA_DEN_ID 100

namespace csight::raid {
  enum DenType {
    Vanilla,
    IsleOfArmor,
  };

  class Den {
   public:
    Den(u8 *data, u8 denId, std::vector<RaidEncounterTable> encounterTables,
        std::shared_ptr<RaidEncounterTable> eventEncounterTable);
    ~Den();
    u64 getSeed();
    u16 getShinyAdvance();
    std::string getShinyAdvanceText();
    shiny::ShinyType getShinyType();
    u8 getStars();
    u8 getDisplayStars();
    u8 getRandRoll();
    u8 getType();
    u8 getFlagByte();
    bool getHasWatts();
    bool getIsEvent();
    bool getIsActive();
    u8 getDenId();
    std::string getDenDisplayId();
    std::string getDenDisplayName();
    bool getIsRare();
    std::shared_ptr<raid::RaidPokemon> getPKM();
    DenType getDenType();

   private:
    u8 m_size = 0x18;
    u8 *m_data = new u8[0x18];
    u8 m_denId = 0;
    u16 m_shinyAdvance = 0;
    RaidEncounter m_spawn;
    shiny::ShinyType m_shineType = shiny::Star;

    raid::RaidEncounter findSpawn(std::vector<raid::RaidEncounter> raidEncounters);
  };
}  // namespace csight::raid
