#pragma once

#include <vector>
#include <memory>
#include <functional>
#include <switch.h>
#include <csight/RaidPokemon.hpp>
#include <csight/Shiny.hpp>

namespace csight::raid {
  class RaidSearchSettings {
   public:
    u64 GetSeed() { return m_seed; }
    void SetSeed(u64 seed) {
      m_seed = seed;
      this->OnUpdate();
    }
    u8 GetFlawlessIVs() { return m_flawlessIVs; }
    void SetFlawlessIVs(u8 flawlesIVs) {
      m_flawlessIVs = flawlesIVs;
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
    void AddUpdateCallback(std::function<void(void)> callback) { m_callbacks.push_back(callback); }

   private:
    std::vector<std::function<void(void)>> m_callbacks;
    u64 m_seed = 0;
    u8 m_flawlessIVs = 1;
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
                            std::function<void(std::shared_ptr<RaidPokemon> raid, u32 frame)> callback);
}  // namespace csight::raid