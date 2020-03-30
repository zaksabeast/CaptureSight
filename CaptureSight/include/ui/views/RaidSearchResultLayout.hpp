#pragma once

#include <csight/core>
#include <pu/Plutonium>
#include <vector>

class RaidSearchResultLayout : public pu::ui::Layout {
 public:
  RaidSearchResultLayout();
  PU_SMART_CTOR(RaidSearchResultLayout)

  void UpdateValues();
  void AddRaidMenuItem(std::shared_ptr<csight::raid::RaidPokemon> raid, u32 advance);

 private:
  // Assume shiny will be star in case no nearby shinies are found
  std::string m_firstShinyTypeText = " ★ ";
  u32 m_firstShinyAdvance = MAX_RAID_ADVANCES;
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::TextBlock::Ref m_headerTextBlock;
};