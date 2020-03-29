#pragma once

#include <string>
#include <functional>
#include <pu/Plutonium>
#include <csight/core>
#include <ui/views/PokemonSummaryLayout.hpp>
#include <ui/views/MainMenuLayout.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <ui/views/DenMenuLayout.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>
#include <ui/views/WarningLayout.hpp>
#include <ui/views/RaidSearchSettingsLayout.hpp>
#include <ui/PokemonViewMode.hpp>

class MainApplication : public pu::ui::Application {
 public:
  using Application::Application;
  PU_SMART_CTOR(MainApplication)

  void OnLoad() override;
  u32 GetSlot();
  std::shared_ptr<csight::GameReader> GetGameReader();
  std::shared_ptr<csight::raid::RaidSearchSettings> GetRaidSearchSettings();

 private:
  u32 m_slot = 0;
  u32 m_maxSlot = 0;
  std::function<std::string(u32 slot)> m_GetSummaryTitle = [&](u32) { return ""; };
  std::shared_ptr<csight::GameReader> m_gameReader;
  std::vector<std::shared_ptr<csight::PK8>> m_pkms;
  std::vector<std::shared_ptr<csight::raid::Den>> m_dens;
  bool m_isShowingExtraDetail = false;
  PokemonSummaryLayout::Ref m_pokemonSummaryLayout;
  MainMenuLayout::Ref m_mainMenuLayout;
  PokemonListLayout::Ref m_pokemonListLayout;
  RaidSearchResultLayout::Ref m_raidSearchResultLayout;
  DenMenuLayout::Ref m_denMenuLayout;
  WarningLayout::Ref m_warningLayout;
  RaidSearchSettingsLayout::Ref m_raidSearchSettingsLayout;
  std::shared_ptr<csight::raid::RaidSearchSettings> m_raidSearchSettings = std::make_shared<csight::raid::RaidSearchSettings>();
  pu::ui::elm::TextBlock::Ref m_versionTextBlock;
  std::vector<std::shared_ptr<pu::ui::Layout>> m_navigationHistory;

  void OnWarningInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnMainApplicationInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputRaidSearchResultLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputDenList(u64 seed);
  void OnInputPokemonListLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputRaidSearchSettingsLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void SelectPokemonSlot(u32 slot);
  void IncreaseSlot(u32 slotIncrease);
  void DecreaseSlot(u32 slotDecrease);
  void SetViewMode(ViewMode viewMode);
  void SetSlot(u32 slot);
  void RefreshSummaryLayout();
  void NavigateTo(std::shared_ptr<pu::ui::Layout> layout);
  void NavigateBack();
  std::string GetWildSummaryTitle(u32 slot);
  std::string GetBoxSummaryTitle(u32 slot);
  std::string GetPartySummaryTitle(u32 slot);
};