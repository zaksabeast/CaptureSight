#pragma once

#include <functional>
#include <string>
#include <pu/Plutonium>

class RaidSearchSettingsLayout : public pu::ui::Layout {
 public:
  RaidSearchSettingsLayout();
  PU_SMART_CTOR(RaidSearchSettingsLayout)

  void UpdateValues(std::shared_ptr<csight::raid::RaidSearchSettings> searchSettings);
  void IncrementShinyTypeFilter();
  void DecrementShinyTypeFilter();
  void IncrementFlawlessIVFilter();
  void DecrementFlawlessIVFilter();
  void IncrementFlawlessIVs();
  void DecrementFlawlessIVs();

 private:
  std::shared_ptr<csight::raid::RaidSearchSettings> m_raidSearchSettings;
  pu::ui::elm::TextBlock::Ref m_titleTextBlock;
  pu::ui::elm::TextBlock::Ref m_instructionsTextBlock;
  pu::ui::elm::Menu::Ref m_filterMenu;
  pu::ui::elm::MenuItem::Ref m_shinyFilterMenuItem;
  pu::ui::elm::MenuItem::Ref m_flawlessIVFilterMenuItem;
  pu::ui::elm::MenuItem::Ref m_flawlessIVsMenuItem;
};