#include <csight/core>
#include <tesla.hpp>
#include <ui/views/DenMenuLayout.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>

DenMenuLayout::DenMenuLayout(std::vector<std::shared_ptr<csight::raid::Den>> dens, std::string title) {
  m_dens = dens;
  m_title = title;
}

tsl::elm::Element *DenMenuLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame(m_title, "");
  auto denList = new tsl::elm::List(6);

  for (u32 i = 0; i < m_dens.size(); i++) {
    auto den = m_dens[i];
    std::string shinyTypeText = den->GetShinyType() == csight::shiny::Square ? " ■ " : " ★ ";
    auto speciesText = den->GetPKM()->GetSpeciesString();
    auto title = "Id: " + std::to_string(den->GetDenDisplayId()) + shinyTypeText + den->GetShinyAdvanceText() + " " + speciesText;
    auto listItem = new tsl::elm::ListItem(title);
    listItem->setClickListener(std::bind(&DenMenuLayout::OnClickDen, this, den, std::placeholders::_1));
    denList->addItem(listItem);
  }

  rootFrame->setContent(denList);

  return rootFrame;
}

bool DenMenuLayout::OnClickDen(std::shared_ptr<csight::raid::Den> den, s64 keys) {
  if (keys == KEY_A) {
    tsl::changeTo<RaidSearchResultLayout>(den->GetSeed(), 5);

    return true;
  }

  return false;
}
