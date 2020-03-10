#include <tesla.hpp>
#include <csight/core>
#include <future>
#include <optional>
#include <string>
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
    listItem->setClickListener(std::bind(&PokemonListLayout::OnClickPKM, this, listItem, pkm, std::placeholders::_1));
    pkmList->addItem(listItem);
  }

  rootFrame->setContent(pkmList);

  return rootFrame;
}

void PokemonListLayout::update() {
  if (this->seedFuture && this->waitingButton) {
    if (csight::utils::waitingInterval(&(this->seedFuture.value()), 500)) {
      auto waitingText = "Calculating" + std::string(this->seedCount % 5, '.');
      this->seedCount++;
      this->waitingButton.value()->setText(waitingText);
    } else {
      this->waitingButton.reset();
      this->seedFuture.reset();
      this->seedCount = 0;
      tsl::changeTo<RaidSearchResultLayout>(seedFuture.value().get(), 5);
    }
  }
}

bool PokemonListLayout::OnClickPKM(tsl::elm::ListItem* button, std::shared_ptr<csight::PK8> pkm, s64 keys) {
  if (this->seedFuture) {
    return true;
  } else if (keys == KEY_A) {
    tsl::changeTo<PokemonSummaryLayout>(pkm);
    return true;
  } else if (keys == KEY_Y) {
    this->seedFuture = pkm->GetRaidSeedAsync();
    this->waitingButton = button;
    return true;
  }

  return false;
}
