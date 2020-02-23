#include <tesla.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <ui/views/PokemonSummaryLayout.hpp>

PokemonListLayout::PokemonListLayout(std::string title, std::vector<std::shared_ptr<csight::PK8>> pkms, std::function<std::string(u32)> GetPKMTitle) {
  m_title = title;
  m_pkms = pkms;
  m_GetPKMTitle = GetPKMTitle;
}

tsl::Element* PokemonListLayout::createUI() {
  auto rootFrame = new tsl::element::Frame();
  auto pkmList = new tsl::element::List();
  auto titleBlock = new tsl::element::CustomDrawer(
      100, FB_WIDTH, 200, FB_WIDTH,
      std::bind(&PokemonListLayout::AddTitleBlock, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

  for (u32 i = 0; i < m_pkms.size(); i++) {
    auto pkm = m_pkms[i];
    auto title = pkm->GetSpeciesString() + " - " + m_GetPKMTitle(i);
    auto listItem = new tsl::element::ListItem(title);
    listItem->setClickListener(std::bind(&PokemonListLayout::OnClickPKM, this, pkm, std::placeholders::_1));
    pkmList->addItem(listItem);
  }

  rootFrame->addElement(titleBlock);
  rootFrame->addElement(pkmList);

  return rootFrame;
}

void PokemonListLayout::AddTitleBlock(u16 x, u16 y, tsl::Screen* screen) {
  screen->drawString(m_title.c_str(), false, 20, 100, 20, tsl::a(0xFFFF));
}

bool PokemonListLayout::OnClickPKM(std::shared_ptr<csight::PK8> pkm, s64 keys) {
  if (keys == KEY_A) {
    this->changeTo(new PokemonSummaryLayout(pkm));
    return true;
  }

  return false;
}
