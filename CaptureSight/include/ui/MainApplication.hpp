#pragma once

#include <string>
#include <functional>
#include <pu/Plutonium>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/MainMenuLayout.hpp>
#include <ui/PokemonListLayout.hpp>
#include <ui/DenMenuLayout.hpp>
#include <ui/PokemonViewMode.hpp>
#include <ui/WarningLayout.hpp>
#include <utils/PK8.hpp>
#include <utils/GameReader.hpp>
#include <utils/Den.hpp>

class MainApplication : public pu::ui::Application {
 public:
  using Application::Application;
  PU_SMART_CTOR(MainApplication)

  void OnLoad() override;
  u32 GetSlot();

 private:
  u32 slot = 0;
  u32 maxSlot = 0;
  std::function<std::string(u32 slot)> GetSummaryTitle = [&](u32) { return ""; };
  std::unique_ptr<GameReader> save;
  std::vector<std::shared_ptr<PK8>> pkms;
  std::vector<std::shared_ptr<Den>> dens;
  bool isShowingExtraDetail = false;
  PokemonSummaryLayout::Ref pokemonSummaryLayout;
  MainMenuLayout::Ref mainMenuLayout;
  PokemonListLayout::Ref pokemonListLayout;
  DenMenuLayout::Ref denMenuLayout;
  WarningLayout::Ref warningLayout;

  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
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