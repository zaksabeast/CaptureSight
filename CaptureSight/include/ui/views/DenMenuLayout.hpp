#pragma once

#include <csight/core>
#include <pu/Plutonium>
#include <vector>

class DenMenuLayout : public pu::ui::Layout {
 public:
  DenMenuLayout();
  PU_SMART_CTOR(DenMenuLayout)

  void UpdateValues(std::vector<std::shared_ptr<csight::raid::Den>> dens);
  void SetOnInputMenuItem(std::function<void(u64)> onInput);
  void ClickMenuItem(u64 seed);

 private:
  pu::ui::elm::Menu::Ref m_menu;
  pu::ui::elm::TextBlock::Ref m_headerTextBlock;
  std::function<void(u64)> m_onMenuItemInput = [&](u64) {};
};