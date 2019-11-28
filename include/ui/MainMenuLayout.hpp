#pragma once

#include <functional>
#include <pu/Plutonium>
#include <ui/PokemonViewMode.hpp>

class MainMenuLayout : public pu::ui::Layout {
 public:
  MainMenuLayout();
  PU_SMART_CTOR(MainMenuLayout)

  void SetOnInputMenuItem(std::function<void(PokemonViewMode)> onInput);

 private:
  std::function<void(PokemonViewMode)> onMenuItemInput;
  pu::ui::elm::Menu::Ref menu;
  pu::ui::elm::MenuItem::Ref wildMenuItem;
  pu::ui::elm::MenuItem::Ref partyMenuItem;
  pu::ui::elm::MenuItem::Ref boxMenuItem;
  void ClickMenuItem(PokemonViewMode mode);
  void ClickWildPokemon();
};