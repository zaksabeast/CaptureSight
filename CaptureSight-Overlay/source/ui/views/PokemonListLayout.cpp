#include <tesla.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <ui/views/PokemonSummaryLayout.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>

PokemonListLayout::PokemonListLayout(std::string title, std::vector<std::shared_ptr<csight::PK8>> pkms, std::function<std::string(u32)> GetPKMTitle) {
  m_title = title;
  m_pkms = pkms;
  m_GetPKMTitle = GetPKMTitle;
}

tsl::elm::Element* PokemonListLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame(m_title, "Press (Y) to find raid seed");
  auto pkmList = new tsl::elm::List(6);

  for (u32 i = 0; i < m_pkms.size(); i++) {
    auto pkm = m_pkms[i];
    auto title = pkm->GetSpeciesString() + " - " + m_GetPKMTitle(i);
    auto listItem = new tsl::elm::ListItem(title);
    listItem->setClickListener(std::bind(&PokemonListLayout::OnClickPKM, this, pkm, std::placeholders::_1));
    pkmList->addItem(listItem);
  }

  rootFrame->setContent(pkmList);

  return rootFrame;
}

bool PokemonListLayout::OnClickPKM(std::shared_ptr<csight::PK8> pkm, s64 keys) {
  if (keys == KEY_A) {
    tsl::changeTo<PokemonSummaryLayout>(pkm);
    return true;
  } else if (keys == KEY_Y) {
    auto seedFuture = pkm->GetRaidSeedAsync();
    seedFuture.wait();
    tsl::changeTo<RaidSearchResultLayout>(seedFuture.get(), 5);
    return true;
  }

  return false;
}
