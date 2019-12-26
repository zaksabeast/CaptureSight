#include <ui/WarningLayout.hpp>
#include <utils/Settings.hpp>

extern Settings gsets;

WarningLayout::WarningLayout() : Layout::Layout() {
  this->warningTextBlock = pu::ui::elm::TextBlock::New(100, 200, "", 30);
  this->warningTextBlock->SetColor(gsets.GetTheme().text.light);

  this->Add(this->warningTextBlock);
}

void WarningLayout::SetWarningText(std::string warning) {
  this->warningTextBlock->SetText(warning);
}