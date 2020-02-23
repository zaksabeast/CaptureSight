#pragma once

#include <string>
#include <functional>
#include <pu/Plutonium>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/MainMenuLayout.hpp>
#include <ui/PokemonListLayout.hpp>
#include <ui/DenMenuLayout.hpp>
#include <ui/RaidSearchLayout.hpp>
#include <ui/PokemonViewMode.hpp>
#include <ui/WarningLayout.hpp>
#include <csight/core>

class MainApplication : public pu::ui::Application {
 public:
  using Application::Application;
  PU_SMART_CTOR(MainApplication)

  void OnLoad() override;
  u32 GetSlot();

 private:
  u32 m_slot = 0;
  u32 m_maxSlot = 0;
  std::function<std::string(u32 slot)> m_GetSummaryTitle = [&](u32) { return ""; };
  std::unique_ptr<csight::GameReader> m_save;
  std::vector<std::shared_ptr<csight::PK8>> m_pkms;
  std::vector<std::shared_ptr<csight::raid::Den>> m_dens;
  bool m_isShowingExtraDetail = false;
  PokemonSummaryLayout::Ref m_pokemonSummaryLayout;
  MainMenuLayout::Ref m_mainMenuLayout;
  PokemonListLayout::Ref m_pokemonListLayout;
  RaidSearchLayout::Ref m_raidSearchLayout;
  DenMenuLayout::Ref m_denMenuLayout;
  WarningLayout::Ref m_warningLayout;
  pu::ui::elm::TextBlock::Ref m_versionTextBlock;

  void OnWarningInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnMainApplicationInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputRaidSearchLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputDenList(u64 seed);
  void SelectPokemonSlot(u32 slot);
  void IncreaseSlot(u32 slotIncrease);
  void DecreaseSlot(u32 slotDecrease);
  void SetViewMode(ViewMode viewMode);
  void SetSlot(u32 slot);
  void RefreshSummaryLayout();
  std::string GetWildSummaryTitle(u32 slot);
  std::string GetBoxSummaryTitle(u32 slot);
  std::string GetPartySummaryTitle(u32 slot);
};