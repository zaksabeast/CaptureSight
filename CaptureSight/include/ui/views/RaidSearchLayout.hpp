#pragma once

#include <vector>
#include <pu/Plutonium>
#include <csight/core>

class RaidSearchLayout : public pu::ui::Layout {
 public:
  RaidSearchLayout();
  PU_SMART_CTOR(RaidSearchLayout)

  void UpdateValues();
  void SetSeed(u64 seed);
  void IncreaseFlawlessIVs();
  void DecreaseFlawlessIVs();
  void AddRaidMenuItem(csight::raid::RaidPokemon* raid, u32 frame);

 private:
  u8 m_flawlessIVs = 1;
  u64 m_seed = 0;
  u32 m_firstShinyFrame = MAX_DEN_SHINY_FRAME;
  // Assume shiny will be star in case no nearby shinies are found
  std::string m_firstShineTypeText = " ★ ";
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::TextBlock::Ref m_headerTextBlock;
};