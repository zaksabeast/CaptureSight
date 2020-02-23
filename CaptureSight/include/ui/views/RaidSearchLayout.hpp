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

 private:
  u32 m_flawlessIVs = 1;
  u64 m_seed = 0;
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::TextBlock::Ref m_headerTextBlock;
};