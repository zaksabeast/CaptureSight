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
  std::function<void(ViewMode)> m_onMenuItemInput;
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::MenuItem::Ref m_wildMenuItem;
  pu::ui::elm::MenuItem::Ref m_partyMenuItem;
  pu::ui::elm::MenuItem::Ref m_boxMenuItem;
  pu::ui::elm::MenuItem::Ref m_activeDenMenuItem;
  pu::ui::elm::MenuItem::Ref m_allDensMenuItem;
  void ClickMenuItem(ViewMode m_mode);
  void ClickWildPokemon();
};