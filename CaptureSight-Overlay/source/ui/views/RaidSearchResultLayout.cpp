#include <csight/core>
#include <functional>
#include <memory>
#include <tesla.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>

RaidSearchResultLayout::RaidSearchResultLayout(u64 seed, u32 flawlessIVs) {
  m_seed = seed;
  m_flawlessIVs = flawlessIVs;
}

tsl::elm::Element *RaidSearchResultLayout::createUI() {
  auto denList = new tsl::elm::List();
  auto searchSettings = std::make_shared<csight::raid::RaidSearchSettings>();
  std::string title = "Oops!";
  std::string subTitle = "Not a non-shiny raid Pokemon!";

  searchSettings->SetSeed(m_seed);
  searchSettings->SetAdvancesToSearch(ADVANCES_TO_SEARCH);
  searchSettings->SetRaidEncounter(csight::raid::RaidEncounter {
    species : 0,
    flawlessIVs : m_flawlessIVs,
    ability : csight::ability::raid::FirstOrSecond,
    probabilities : { 35, 0, 0, 0, 0 }
  });

  if (m_seed > 0) {
    csight::raid::calculateRaidPKMList(
        searchSettings,
        std::bind(&RaidSearchResultLayout::AddRaidMenuItem, this, denList, std::placeholders::_1, std::placeholders::_2));
    title = csight::utils::convertNumToHexString(m_seed);
    subTitle = "Next shiny frame: " + m_firstShinyTypeText
        + csight::utils::getRaidShinyAdvanceText(m_firstShinyAdvance, ADVANCES_TO_SEARCH);
  }

  auto rootFrame = new tsl::elm::OverlayFrame(title, subTitle);

  rootFrame->setContent(denList);

  return rootFrame;
}

void RaidSearchResultLayout::AddRaidMenuItem(tsl::elm::List *denList, std::shared_ptr<csight::raid::RaidPokemon> raid,
                                             u32 advance) {
  std::string shinyText = "";

  if (raid->GetIsShiny()) {
    shinyText = raid->GetShinyType() == csight::shiny::Square ? " ■ " : " ★";

    if (m_firstShinyAdvance == ADVANCES_TO_SEARCH) {
      m_firstShinyAdvance = advance;
      m_firstShinyTypeText = shinyText;
    }
  }

  auto formattedIVs = csight::utils::joinNums(raid->GetIVs(), "/");
  std::string denTitle = "Fr " + std::to_string(advance) + " - " + formattedIVs + shinyText;
  auto menuItem = new tsl::elm::ListItem(denTitle);

  denList->addItem(menuItem);
}
