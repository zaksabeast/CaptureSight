#include <functional>
#include <csight/core>
#include <ui/views/RaidSearchResultLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

RaidSearchResultLayout::RaidSearchResultLayout() : Layout::Layout() {
  m_headerTextBlock = pu::ui::elm::TextBlock::New(50, 50, "", 25);
  m_headerTextBlock->SetColor(gsets.GetTheme().text.light);
  m_menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);

  this->Add(m_headerTextBlock);
  this->Add(m_menu);
}

void RaidSearchResultLayout::UpdateValues(std::shared_ptr<csight::raid::RaidSearchSettings> searchSettings) {
  std::string headerText = i18n->Translate("No raid seed found!  This may not be a raid Pokemon");
  auto seedString = csight::utils::convertNumToHexString(searchSettings->GetSeed());
  m_menu->SetSelectedIndex(0);
  m_menu->ClearItems();
  // Reset shiny frame
  m_firstShinyFrame = MAX_DEN_SHINY_FRAME;

  if (searchSettings->GetSeed() > 0) {
    csight::raid::calculateRaidPKMList(searchSettings,
                                       std::bind(&RaidSearchResultLayout::AddRaidMenuItem, this, std::placeholders::_1, std::placeholders::_2));
    headerText = i18n->Translate("Seed") + ": " + seedString + m_firstShineTypeText + i18n->Translate("Shiny") + " " +
                 csight::utils::getRaidShinyFrameText(m_firstShinyFrame) + " " + i18n->Translate("(A) to apply filters");
  }

  m_headerTextBlock->SetText(headerText);
}

void RaidSearchResultLayout::AddRaidMenuItem(std::shared_ptr<csight::raid::RaidPokemon> raid, u32 frame) {
  auto isShiny = raid->GetIsShiny();
  std::string shinyText = "";
  std::string frameShineType = "";

  if (isShiny) {
    frameShineType = raid->GetShineType() == csight::shiny::Square ? " ■ " : " ★ ";
    shinyText = "Shiny";

    if (m_firstShinyFrame == MAX_DEN_SHINY_FRAME) {
      m_firstShinyFrame = frame;
      m_firstShineTypeText = frameShineType;
    }
  }

  auto formattedIVs = csight::utils::joinNums(raid->GetIVs(), "/");
  std::string title = i18n->Translate("Frame") + " " + std::to_string(frame) + " - " + i18n->Translate("IVs") + ": " + formattedIVs + frameShineType +
                      i18n->Translate(shinyText);
  auto menuItem = pu::ui::elm::MenuItem::New(title);

  menuItem->SetColor(gsets.GetTheme().text.light);
  m_menu->AddItem(menuItem);
}
