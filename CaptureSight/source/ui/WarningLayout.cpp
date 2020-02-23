#include <ui/WarningLayout.hpp>
#include <utils/Settings.hpp>

extern Settings gsets;

WarningLayout::WarningLayout() : Layout::Layout() {
  m_warningTextBlock = pu::ui::elm::TextBlock::New(100, 200, "", 30);
  m_warningTextBlock->SetColor(gsets.GetTheme().text.light);

  this->Add(m_warningTextBlock);
}

void WarningLayout::SetWarningText(std::string warning) {
  m_warningTextBlock->SetText(warning);
}