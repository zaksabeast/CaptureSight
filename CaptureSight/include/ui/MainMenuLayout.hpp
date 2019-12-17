#pragma once

#include <functional>
#include <pu/Plutonium>
#include <ui/PokemonViewMode.hpp>

class MainMenuLayout : public pu::ui::Layout {
 public:
  MainMenuLayout();
  PU_SMART_CTOR(MainMenuLayout)

  void SetOnInputMenuItem(std::function<void(ViewMode)> onInput);

 private:
  std::function<void(ViewMode)> onMenuItemInput;
  pu::ui::elm::Menu::Ref menu;
  pu::ui::elm::MenuItem::Ref wildMenuItem;
  pu::ui::elm::MenuItem::Ref partyMenuItem;
  pu::ui::elm::MenuItem::Ref boxMenuItem;
  pu::ui::elm::MenuItem::Ref activeDenMenuItem;
  pu::ui::elm::MenuItem::Ref allDensMenuItem;
  void ClickMenuItem(ViewMode mode);
  void ClickWildPokemon();
};