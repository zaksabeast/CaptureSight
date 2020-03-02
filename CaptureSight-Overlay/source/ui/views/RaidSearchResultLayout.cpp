#include <memory>
#include <functional>
#include <csight/core>
#include <tesla.hpp>
#include <ui/views/RaidSearchResultLayout.hpp>

RaidSearchResultLayout::RaidSearchResultLayout(u64 seed, u32 flawlessIVs) {
  m_seed = seed;
  m_flawlessIVs = flawlessIVs;
}

tsl::Element* RaidSearchResultLayout::createUI() {
  auto rootFrame = new tsl::element::Frame();
  auto denList = new tsl::element::List();
  auto searchSettings = std::make_shared<csight::raid::RaidSearchSettings>();

  searchSettings->SetSeed(m_seed);
  searchSettings->SetFlawlessIVs(m_flawlessIVs);

  if (m_seed > 0) {
    csight::raid::calculateRaidPKMList(searchSettings,
                                       std::bind(&RaidSearchResultLayout::AddRaidMenuItem, this, denList, std::placeholders::_1, std::placeholders::_2));
    m_title = csight::utils::convertNumToHexString(m_seed) + m_firstShinyTypeText + csight::utils::getRaidShinyFrameText(m_firstShinyFrame);
  } else {
    m_title = "Not a non-shiny raid Pokemon!";
  }

  auto titleBlock = new tsl::element::CustomDrawer(
      100, FB_WIDTH, 200, FB_WIDTH,
      std::bind(&RaidSearchResultLayout::AddTitleBlock, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

  rootFrame->addElement(denList);
  rootFrame->addElement(titleBlock);

  return rootFrame;
}

void RaidSearchResultLayout::AddRaidMenuItem(tsl::element::List* denList, std::shared_ptr<csight::raid::RaidPokemon> raid, u32 frame) {
  std::string shinyText = "";

  if (raid->GetIsShiny()) {
    shinyText = raid->GetShineType() == csight::shiny::Square ? " ■ " : " ★";

    if (m_firstShinyFrame == MAX_DEN_SHINY_FRAME) {
      m_firstShinyFrame = frame;
      m_firstShinyTypeText = shinyText;
    }
  }

  auto formattedIVs = csight::utils::joinNums(raid->GetIVs(), "/");
  std::string denTitle = "Fr " + std::to_string(frame) + " - " + formattedIVs + shinyText;
  auto menuItem = new tsl::element::ListItem(denTitle);

  denList->addItem(menuItem);
}

void RaidSearchResultLayout::AddTitleBlock(u16 x, u16 y, tsl::Screen* screen) {
  screen->drawString(m_title.c_str(), false, 20, 100, 20, tsl::a(0xFFFF));
}