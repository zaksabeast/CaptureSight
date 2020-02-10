#pragma once

#include <vector>
#include <pu/Plutonium>
#include <csight/core>

class DenMenuLayout : public pu::ui::Layout {
 public:
  DenMenuLayout();
  PU_SMART_CTOR(DenMenuLayout)

  void UpdateValues(std::vector<std::shared_ptr<csight::raid::Den>> dens);
  void SetOnInputMenuItem(std::function<void(u64)> onInput);
  void ClickMenuItem(u64 seed);

 private:
  pu::ui::elm::Menu::Ref menu;
  pu::ui::elm::TextBlock::Ref headerTextBlock;
  std::function<void(u64)> onMenuItemInput = [&](u64) {};
};