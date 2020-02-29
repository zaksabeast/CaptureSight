#pragma once

#include <vector>
#include <pu/Plutonium>
#include <csight/core>

class RaidSearchLayout : public pu::ui::Layout {
 public:
  RaidSearchLayout();
  PU_SMART_CTOR(RaidSearchLayout)

  void UpdateValues(std::shared_ptr<csight::raid::RaidSearchSettings> searchSettings);
  void AddRaidMenuItem(std::shared_ptr<csight::raid::RaidPokemon> raid, u32 frame);

 private:
  // Assume shiny will be star in case no nearby shinies are found
  std::string m_firstShineTypeText = " ★ ";
  u32 m_firstShinyFrame = MAX_DEN_SHINY_FRAME;
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::TextBlock::Ref m_headerTextBlock;
};