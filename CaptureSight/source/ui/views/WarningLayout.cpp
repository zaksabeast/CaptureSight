#include <ui/elements/createTextBlock.hpp>
#include <ui/views/WarningLayout.hpp>
#include <utils/Settings.hpp>

extern Settings gsets;

WarningLayout::WarningLayout() : Layout::Layout() {
  m_warningTextBlock = createTextBlock(100, 200, "", 30);

  this->Add(m_warningTextBlock);
}

void WarningLayout::SetWarningText(std::string warning) {
  m_warningTextBlock->SetText(warning);
}