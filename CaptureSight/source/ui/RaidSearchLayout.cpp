#include <csight/core>
#include <ui/RaidSearchLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

RaidSearchLayout::RaidSearchLayout() : Layout::Layout() {
  m_headerTextBlock = pu::ui::elm::TextBlock::New(50, 50, "", 25);
  m_headerTextBlock->SetColor(gsets.GetTheme().text.light);
  m_menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);

  this->Add(m_headerTextBlock);
  this->Add(m_menu);
}

void RaidSearchLayout::UpdateValues() {
  uint firstShinyFrame = MAX_DEN_SHINY_FRAME;
  // Assume shiny will be star in case no nearby shinies are found
  std::string firstShineType = " ★ ";
  std::string headerText = i18n->Translate("No raid seed found!  This may not be a raid Pokemon");
  auto seedString = csight::utils::convertNumToHexString(m_seed);
  u64 nextSeed = m_seed;
  m_menu->ClearItems();

  if (m_seed > 0) {
    for (uint frame = 0; frame < MAX_DEN_SHINY_FRAME; frame++) {
      auto raid = csight::raid::RaidPokemon(nextSeed, m_flawlessIVs, 0);
      auto rng = csight::rng::xoroshiro(nextSeed);
      nextSeed = rng.nextulong();

      auto isShiny = raid.GetIsShiny();
      std::string shinyText = "";
      std::string frameShineType = "";

      if (isShiny) {
        frameShineType = raid.GetShineType() == csight::shiny::Square ? " ■ " : " ★ ";
        shinyText = "Shiny";

        if (firstShinyFrame == MAX_DEN_SHINY_FRAME) {
          firstShinyFrame = frame;
          firstShineType = frameShineType;
        }
      }

      auto formattedIVs = csight::utils::joinNums(raid.GetIVs(), "/");
      std::string title = i18n->Translate("Frame") + " " + std::to_string(frame) + " - " + i18n->Translate("IVs") + ": " + formattedIVs +
                          frameShineType + i18n->Translate(shinyText);
      auto menuItem = pu::ui::elm::MenuItem::New(title);

      menuItem->SetColor(gsets.GetTheme().text.light);
      m_menu->AddItem(menuItem);
    }

    headerText = i18n->Translate("Seed") + ": " + seedString + firstShineType + i18n->Translate("Shiny") + " " +
                 csight::utils::getRaidShinyFrameText(firstShinyFrame) + ", (-L) " + i18n->Translate("Flawless IVs") + " " +
                 std::to_string(m_flawlessIVs) + " (+R)";
  }

  m_headerTextBlock->SetText(headerText);
}

void RaidSearchLayout::SetSeed(u64 seed) {
  m_seed = seed;
}

void RaidSearchLayout::IncreaseFlawlessIVs() {
  m_flawlessIVs = m_flawlessIVs >= 5 ? 1 : m_flawlessIVs + 1;
}

void RaidSearchLayout::DecreaseFlawlessIVs() {
  m_flawlessIVs = m_flawlessIVs == 1 ? 5 : m_flawlessIVs - 1;
}
