#pragma once

#include <string>
#include <functional>
#include <pu/Plutonium>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/MainMenuLayout.hpp>
#include <ui/PokemonListLayout.hpp>
#include <ui/DenMenuLayout.hpp>
#include <ui/PokemonViewMode.hpp>
#include <utils/PK8.hpp>
#include <utils/GameReader.hpp>
#include <utils/Den.hpp>

class MainApplication : public pu::ui::Application {
 public:
  using Application::Application;
  PU_SMART_CTOR(MainApplication)

  void OnLoad() override;
  PokemonSummaryLayout::Ref GetPokemonSummaryLayout();
  MainMenuLayout::Ref GetMainMenuLayout();
  PokemonListLayout::Ref GetPokemonListLayout();
  u32 GetSlot();
  void SetSlot(u32 slot);
  void SetViewMode(ViewMode viewMode);

 private:
  u32 slot = 0;
  u32 maxSlot = 0;
  std::function<std::string(u32 slot)> GetSummaryTitle = [&](u32) { return ""; };
  std::unique_ptr<GameReader> save;
  std::vector<std::shared_ptr<PK8>> pkms;
  std::vector<std::shared_ptr<Den>> dens;
  PokemonSummaryLayout::Ref pokemonSummaryLayout;
  MainMenuLayout::Ref mainMenuLayout;
  PokemonListLayout::Ref pokemonListLayout;
  DenMenuLayout::Ref denMenuLayout;

  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void IncreaseSlot(u32 slotIncrease);
  void DecreaseSlot(u32 slotDecrease);
  std::string GetWildSummaryTitle(u32 slot);
  std::string GetBoxSummaryTitle(u32 slot);
  std::string GetPartySummaryTitle(u32 slot);
};