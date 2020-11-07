#pragma once

#include <csight/Enums/ShinyType.hpp>
#include <csight/Game/SWSH/RaidTemplateTables.hpp>
#include <csight/PKM/RaidPokemon.hpp>
#include <memory>
#include <string>
#include <switch.h>
#include <vector>

#ifndef MAX_RAID_ADVANCES
#define MAX_RAID_ADVANCES 9999
#endif

#define FIRST_IOA_DEN_ID 100
#define FIRST_CT_DEN_ID 190

namespace csight::game::swsh {
  enum DenType { Vanilla, IsleOfArmor, CrownTundra };

  class Den {
   public:
    Den(u8 *data, u16 denId, std::vector<RaidEncounterTable> encounterTables,
        std::shared_ptr<RaidEncounterTable> eventEncounterTable, u32 playerSIDTID);
    ~Den();
    u64 getSeed();
    u16 getShinyAdvance();
    std::string getShinyAdvanceText();
    enums::ShinyType getShinyType();
    u8 getStars();
    u8 getDisplayStars();
    u8 getRandRoll();
    u8 getType();
    u8 getFlagByte();
    bool getHasWatts();
    bool getIsEvent();
    bool getIsActive();
    u16 getDenId();
    std::string getDenDisplayId();
    std::string getDenDisplayName();
    bool getIsRare();
    std::shared_ptr<pkm::RaidPokemon> getPKM();
    DenType getDenType();

   private:
    u8 m_size = 0x18;
    u8 *m_data = new u8[0x18];
    u16 m_denId = 0;
    u16 m_shinyAdvance = 0;
    u32 m_playerSIDTID = 0;
    RaidEncounter m_spawn;
    enums::ShinyType m_shineType = enums::ShinyType::Star;

    RaidEncounter findSpawn(std::vector<RaidEncounter> raidEncounters);
  };
}
