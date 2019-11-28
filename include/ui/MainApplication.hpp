#pragma once

#include <pu/Plutonium>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/MainMenuLayout.hpp>
#include <ui/PokemonListLayout.hpp>
#include <ui/PokemonViewMode.hpp>
#include <utils/PK8.hpp>
#include <utils/GameReader.hpp>

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
  void SetViewMode(PokemonViewMode viewMode);

 private:
  u32 slot = 0;
  u32 maxSlot = 0;
  std::string pokemonSummaryTitle = "Party Pokemon";
  std::unique_ptr<GameReader> save;
  std::vector<std::shared_ptr<PK8>> pkms;
  PokemonSummaryLayout::Ref pokemonSummaryLayout;
  MainMenuLayout::Ref mainMenuLayout;
  PokemonListLayout::Ref pokemonListLayout;

  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void IncreaseSlot();
  void DecreaseSlot();
};