#pragma once

#include <functional>
#include <pu/Plutonium>
#include <string>

class RaidSearchSettingsLayout : public pu::ui::Layout {
 public:
  RaidSearchSettingsLayout();
  PU_SMART_CTOR(RaidSearchSettingsLayout)

  void UpdateValues();
  void DecrementAbilityFilter();
  void IncrementAbilityFilter();
  void IncrementShinyTypeFilter();
  void DecrementShinyTypeFilter();
  void IncrementFlawlessIVFilter();
  void DecrementFlawlessIVFilter();
  void ToggleIsRareDenFilter();
  void IncrementFlawlessIVs();
  void DecrementFlawlessIVs();
  void IncrementDenIndex();
  void DecrementDenIndex();
  void SetEncounterIndex(u32 encounterIndex);
  void IncrementEncounterIndex();
  void DecrementEncounterIndex();

 private:
  u32 m_denIndex = 0;
  u32 m_encounterIndex = 0;
  bool m_isRareDenFilter = false;
  pu::ui::elm::TextBlock::Ref m_titleTextBlock;
  pu::ui::elm::TextBlock::Ref m_instructionsTextBlock;
  pu::ui::elm::Menu::Ref m_filterMenu;
  pu::ui::elm::MenuItem::Ref m_shinyFilterMenuItem;
  pu::ui::elm::MenuItem::Ref m_flawlessIVFilterMenuItem;
  pu::ui::elm::MenuItem::Ref m_abilityFiltermenuItem;
  pu::ui::elm::MenuItem::Ref m_denIndexMenuItem;
  pu::ui::elm::MenuItem::Ref m_spawnIndexMenuItem;
  pu::ui::elm::MenuItem::Ref m_isRareDenFilterMenuItem;
};