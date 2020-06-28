#pragma once

#include <csight/Ability.hpp>
#include <csight/Config.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <csight/Shiny.hpp>
#include <functional>
#include <memory>
#include <switch.h>
#include <vector>

namespace csight::raid {
  class RaidSearchSettings {
   public:
    RaidSearchSettings() : m_encounterTables {} {}
    RaidSearchSettings(const std::vector<RaidEncounterTable> &encounterTables) : m_encounterTables(encounterTables) {
      this->updateRaidEncounter();
    }

    u64 getSeed() { return m_seed; }
    void setSeed(u64 seed) {
      m_seed = seed;
      this->onUpdate();
    }
    RaidEncounter getRaidEncounter() { return m_raidEncounter; }
    void setSpawnIndex(u32 spawnIndex) {
      m_spawnIndex = spawnIndex;
      this->updateRaidEncounter();
      this->onUpdate();
    }
    void setDenIndex(u32 denIndex) {
      m_denIndex = denIndex;
      this->updateRaidEncounter();
      this->onUpdate();
    }
    void setIsRareDen(bool isRareDen) {
      m_isRareDen = isRareDen;
      this->updateRaidEncounter();
      this->onUpdate();
    }
    u8 getFlawlessIVFilter() { return m_flawlessIVFilter; }
    void setFlawlessIVFilter(u8 flawlessIVFilter) {
      m_flawlessIVFilter = flawlessIVFilter;
      this->onUpdate();
    }
    shiny::ShinyType getShinyTypeFilter() { return m_shinyTypeFilter; }
    void setShinyTypeFilter(shiny::ShinyType shinyTypeFilter) {
      m_shinyTypeFilter = shinyTypeFilter;
      this->onUpdate();
    }
    ability::filter::AbilityFilter getAbilityFilter() { return m_abilityFilter; }
    void setAbilityFilter(ability::filter::AbilityFilter abilityFilter) {
      m_abilityFilter = abilityFilter;
      this->onUpdate();
    }
    u32 getAdvancesToSearch() { return m_advancesToSearch; }
    void setAdvancesToSearch(u32 advancesToSearch) {
      m_advancesToSearch = advancesToSearch;
      this->onUpdate();
    }
    void addUpdateCallback(std::function<void(void)> callback) { m_callbacks.push_back(callback); }

   private:
    std::vector<std::function<void(void)>> m_callbacks;
    u64 m_seed = 0;
    u32 m_advancesToSearch = MAX_RAID_ADVANCES;
    ability::filter::AbilityFilter m_abilityFilter = ability::filter::Any;
    u8 m_flawlessIVFilter = 1;
    shiny::ShinyType m_shinyTypeFilter = shiny::None;
    u32 m_spawnIndex = 0;
    u32 m_denIndex = 0;
    bool m_isRareDen = false;
    const std::vector<RaidEncounterTable> &m_encounterTables;
    RaidEncounter m_raidEncounter = {
      species : 0,
      flawlessIVs : 5,
      ability : ability::raid::AbilityRaidSetting::FirstOrSecond,
      form : 0,
      probabilities : { 35, 0, 0, 0, 0 }
    };
    void onUpdate() {
      for (auto callback : m_callbacks) {
        callback();
      }
    }
    void updateRaidEncounter() {
      if (m_encounterTables.size() > 0) {
        auto nests = csight::utils::findRaidEncounterTable(m_encounterTables, m_denIndex, m_isRareDen);
        auto encounter = nests.templates[m_spawnIndex];
        m_raidEncounter = encounter;
      }
    }
  };

  // Using a callback reduces memory consumption by only having one RaidPokemon in memory at a time
  void calculateRaidPKMList(std::shared_ptr<RaidSearchSettings> searchSettings,
                            std::function<void(std::shared_ptr<RaidPokemon> raid, u32 advance)> callback);
}  // namespace csight::raid