#include <csight/core>
#include <tesla.hpp>
#include <ui/views/DenMenuLayout.hpp>

DenMenuLayout::DenMenuLayout(std::vector<std::shared_ptr<csight::raid::Den>> dens, std::string title) {
  m_dens = dens;
  m_title = title;
}

tsl::elm::Element *DenMenuLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame(m_title, "");
  auto denList = new tsl::elm::List();

  for (u32 i = 0; i < m_dens.size(); i++) {
    auto den = m_dens[i];
    std::string shinyTypeText = den->getShinyType() == csight::shiny::Square ? " ■ " : " ★ ";
    std::string eventText = den->getIsEvent() ? " (Event)" : "";
    auto title = den->getDenDisplayName() + shinyTypeText + den->getShinyAdvanceText() + eventText;
    auto listItem = new tsl::elm::ListItem(title);
    denList->addItem(listItem);
  }

  rootFrame->setContent(denList);

  return rootFrame;
}
