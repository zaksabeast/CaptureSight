#pragma once

#include <pu/Plutonium>

class WarningLayout : public pu::ui::Layout {
 public:
  WarningLayout();
  PU_SMART_CTOR(WarningLayout)

  void SetWarningText(std::string warning);

 private:
  pu::ui::elm::TextBlock::Ref warningTextBlock;
};