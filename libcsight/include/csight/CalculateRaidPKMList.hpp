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
      this->UpdateRaidEncounter();
    }

    u64 GetSeed() { return m_seed; }
    void SetSeed(u64 seed) {
      m_seed = seed;
      this->OnUpdate();
    }
    RaidEncounter GetRaidEncounter() { return m_raidEncounter; }
    void SetSpawnIndex(u32 spawnIndex) {
      m_spawnIndex = spawnIndex;
      this->UpdateRaidEncounter();
      this->OnUpdate();
    }
    void SetDenIndex(u32 denIndex) {
      m_denIndex = denIndex;
      this->UpdateRaidEncounter();
      this->OnUpdate();
    }
    void SetIsRareDen(bool isRareDen) {
      m_isRareDen = isRareDen;
      this->UpdateRaidEncounter();
      this->OnUpdate();
    }
    u8 GetFlawlessIVFilter() { return m_flawlessIVFilter; }
    void SetFlawlessIVFilter(u8 flawlessIVFilter) {
      m_flawlessIVFilter = flawlessIVFilter;
      this->OnUpdate();
    }
    shiny::ShinyType GetShinyTypeFilter() { return m_shinyTypeFilter; }
    void SetShinyTypeFilter(shiny::ShinyType shinyTypeFilter) {
      m_shinyTypeFilter = shinyTypeFilter;
      this->OnUpdate();
    }
    ability::filter::AbilityFilter GetAbilityFilter() { return m_abilityFilter; }
    void SetAbilityFilter(ability::filter::AbilityFilter abilityFilter) {
      m_abilityFilter = abilityFilter;
      this->OnUpdate();
    }
    u32 GetAdvancesToSearch() { return m_advancesToSearch; }
    void SetAdvancesToSearch(u32 advancesToSearch) {
      m_advancesToSearch = advancesToSearch;
      this->OnUpdate();
    }
    void AddUpdateCallback(std::function<void(void)> callback) { m_callbacks.push_back(callback); }

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
    void OnUpdate() {
      for (auto callback : m_callbacks) {
        callback();
      }
    }
    void UpdateRaidEncounter() {
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