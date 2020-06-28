#include <csight/core>
#include <future>
#include <optional>
#include <string>
#include <tesla.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <ui/views/PokemonSummaryLayout.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>

PokemonListLayout::PokemonListLayout(std::string title, std::vector<std::shared_ptr<csight::PK8>> pkms,
                                     std::function<std::string(u32)> GetPKMTitle) {
  m_title = title;
  m_pkms = pkms;
  m_GetPKMTitle = GetPKMTitle;
}

tsl::elm::Element *PokemonListLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame(m_title, "Press (Y) to find raid seed");
  auto pkmList = new tsl::elm::List();

  for (u32 i = 0; i < m_pkms.size(); i++) {
    auto pkm = m_pkms[i];
    auto title = pkm->getSpeciesString() + " - " + m_GetPKMTitle(i);
    auto listItem = new tsl::elm::ListItem(title);
    listItem->setClickListener(std::bind(&PokemonListLayout::onClickPKM, this, listItem, title, pkm, std::placeholders::_1));
    pkmList->addItem(listItem);
  }

  rootFrame->setContent(pkmList);

  return rootFrame;
}

void PokemonListLayout::update() {
  if (m_seedFuture && m_waitingButton) {
    if (csight::utils::waitingInterval(&(m_seedFuture.value()), 500)) {
      auto waitingText = "Calculating" + std::string(m_seedCount % 5, '.');
      m_seedCount++;
      m_waitingButton.value()->setText(waitingText);
    } else {
      tsl::changeTo<RaidSearchResultLayout>(m_seedFuture.value().get(), 5);
      m_waitingButton.value()->setText(m_waitingButtonText.value());
      m_waitingButton.reset();
      m_waitingButtonText.reset();
      m_seedFuture.reset();
      m_seedCount = 0;
    }
  }
}

bool PokemonListLayout::onClickPKM(tsl::elm::ListItem *button, std::string buttonText, std::shared_ptr<csight::PK8> pkm,
                                   s64 keys) {
  if (m_seedFuture) {
    return true;
  } else if (keys == KEY_A) {
    tsl::changeTo<PokemonSummaryLayout>(pkm);
    return true;
  } else if (keys == KEY_Y) {
    m_seedFuture = pkm->getRaidSeedAsync();
    m_waitingButton = button;
    m_waitingButtonText = buttonText;
    return true;
  }

  return false;
}
