#pragma once

#include <vector>
#include <pu/Plutonium>
#include <csight/core>

using namespace csight;

class RaidSearchLayout : public pu::ui::Layout {
 public:
  RaidSearchLayout();
  PU_SMART_CTOR(RaidSearchLayout)

  void UpdateValues();
  void SetSeed(ulong seed);
  void IncreaseFlawlessIVs();
  void DecreaseFlawlessIVs();

 private:
  uint flawlessIVs = 1;
  ulong seed = 0;
  pu::ui::elm::Menu::Ref menu;
  pu::ui::elm::TextBlock::Ref headerTextBlock;
};