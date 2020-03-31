#pragma once

#include <csight/Config.hpp>
#include <csight/Ability.hpp>
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
    u64 GetSeed() { return m_seed; }
    void SetSeed(u64 seed) {
      m_seed = seed;
      this->OnUpdate();
    }
    RaidEncounter GetRaidEncounter() { return m_raidEncounter; }
    void SetRaidEncounter(RaidEncounter raidEncounter) {
      m_raidEncounter = raidEncounter;
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
    RaidEncounter m_raidEncounter;
    ability::filter::AbilityFilter m_abilityFilter = ability::filter::Any;
    u8 m_flawlessIVFilter = 1;
    shiny::ShinyType m_shinyTypeFilter = shiny::None;
    void OnUpdate() {
      for (auto callback : m_callbacks) {
        callback();
      }
    }
  };

  // Using a callback reduces memory consumption by only having one RaidPokemon in memory at a time
  void calculateRaidPKMList(std::shared_ptr<RaidSearchSettings> searchSettings,
                            std::function<void(std::shared_ptr<RaidPokemon> raid, u32 advance)> callback);
}  // namespace csight::raid