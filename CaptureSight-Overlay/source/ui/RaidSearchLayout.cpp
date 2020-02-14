#include <csight/core>
#include <tesla.hpp>
#include <ui/RaidSearchLayout.hpp>

RaidSearchLayout::RaidSearchLayout(u64 seed, u32 flawlessIVs) {
  this->seed = seed;
  this->flawlessIVs = flawlessIVs;
}

tsl::Element* RaidSearchLayout::createUI() {
  u64 nextSeed = this->seed;
  u32 shinyFrame = MAX_DEN_SHINY_FRAME;
  std::string firstShinyType = "";
  auto rootFrame = new tsl::element::Frame();
  auto denList = new tsl::element::List();

  if (this->seed > 0) {
    for (u32 frame = 0; frame < MAX_DEN_SHINY_FRAME; frame++) {
      auto raid = csight::raid::RaidPokemon(nextSeed, this->flawlessIVs, 0);
      auto rng = csight::rng::xoroshiro(nextSeed);
      nextSeed = rng.nextulong();

      std::string shinyText = "";

      if (raid.GetIsShiny()) {
        shinyText = raid.GetShineType() == csight::shiny::Square ? " ■ " : " ★";

        if (shinyFrame == MAX_DEN_SHINY_FRAME) {
          shinyFrame = frame;
          firstShinyType = shinyText;
        }
      }

      auto formattedIVs = csight::utils::joinNums(raid.GetIVs(), "/");
      std::string denTitle = "Fr " + std::to_string(frame) + " - " + formattedIVs + shinyText;
      auto menuItem = new tsl::element::ListItem(denTitle);

      denList->addItem(menuItem);
    }
    this->title = csight::utils::convertNumToHexString(this->seed) + firstShinyType + std::to_string(shinyFrame);
  } else {
    this->title = "Not a non-shiny raid Pokemon!";
  }

  auto titleBlock = new tsl::element::CustomDrawer(
      100, FB_WIDTH, 200, FB_WIDTH,
      std::bind(&RaidSearchLayout::AddTitleBlock, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

  rootFrame->addElement(denList);
  rootFrame->addElement(titleBlock);

  return rootFrame;
}

void RaidSearchLayout::AddTitleBlock(u16 x, u16 y, tsl::Screen* screen) {
  screen->drawString(this->title.c_str(), false, 20, 100, 20, tsl::a(0xFFFF));
}