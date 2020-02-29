#include <functional>
#include <pu/Plutonium>
#include <csight/core>
#include <ui/views/RaidSearchSettingsLayout.hpp>
#include <utils/Constants.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

std::string GetShinyTypeName(csight::shiny::ShinyType type) {
  switch (type) {
    case csight::shiny::Star:
      return "Star";
    case csight::shiny::Square:
      return "Square";
    case csight::shiny::Any:
      return "Star or square";
    default:
      return "No filter";
  }
}

RaidSearchSettingsLayout::RaidSearchSettingsLayout() : Layout::Layout() {
  auto raidSearchSettingsText = i18n->Translate("Raid Search Settings");
  auto intructionsText = i18n->Translate("(A) or (B) to apply filters, (L) and (R) to change filters");

  m_titleTextBlock = pu::ui::elm::TextBlock::New(100, 90, raidSearchSettingsText, 30);
  m_titleTextBlock->SetColor(gsets.GetTheme().text.light);
  m_instructionsTextBlock = pu::ui::elm::TextBlock::New(100, 150, intructionsText, 25);
  m_instructionsTextBlock->SetColor(gsets.GetTheme().text.light);
  m_filterMenu = pu::ui::elm::Menu::New(100, 220, SCREEN_MAX_WIDTH / 2, gsets.GetTheme().active.dark, 80, 4);

  m_shinyFilterMenuItem = pu::ui::elm::MenuItem::New("");
  m_shinyFilterMenuItem->SetColor(gsets.GetTheme().text.light);
  m_shinyFilterMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::DecrementShinyTypeFilter, this), KEY_L);
  m_shinyFilterMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::IncrementShinyTypeFilter, this), KEY_R);

  m_flawlessIVFilterMenuItem = pu::ui::elm::MenuItem::New("");
  m_flawlessIVFilterMenuItem->SetColor(gsets.GetTheme().text.light);
  m_flawlessIVFilterMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::IncrementFlawlessIVFilter, this), KEY_R);
  m_flawlessIVFilterMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::DecrementFlawlessIVFilter, this), KEY_L);

  m_flawlessIVsMenuItem = pu::ui::elm::MenuItem::New("");
  m_flawlessIVsMenuItem->SetColor(gsets.GetTheme().text.light);
  m_flawlessIVsMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::IncrementFlawlessIVs, this), KEY_R);
  m_flawlessIVsMenuItem->AddOnClick(std::bind(&RaidSearchSettingsLayout::DecrementFlawlessIVs, this), KEY_L);

  m_filterMenu->AddItem(m_flawlessIVsMenuItem);
  m_filterMenu->AddItem(m_shinyFilterMenuItem);
  m_filterMenu->AddItem(m_flawlessIVFilterMenuItem);

  this->Add(m_titleTextBlock);
  this->Add(m_filterMenu);
  this->Add(m_instructionsTextBlock);
}

void RaidSearchSettingsLayout::UpdateValues(std::shared_ptr<csight::raid::RaidSearchSettings> searchSettings) {
  m_raidSearchSettings = searchSettings;
  std::string flawlessIVsText = i18n->Translate("Flawless IVs") + " - " + std::to_string(searchSettings->GetFlawlessIVs());
  std::string shinyFilterText = i18n->Translate("Shiny filter") + " - " + i18n->Translate(GetShinyTypeName(searchSettings->GetShinyTypeFilter()));
  std::string flawlessIVFilterText = i18n->Translate("Flawless IV filter") + " - " + std::to_string(searchSettings->GetFlawlessIVFilter());

  m_flawlessIVsMenuItem->SetName(flawlessIVsText);
  m_shinyFilterMenuItem->SetName(shinyFilterText);
  m_flawlessIVFilterMenuItem->SetName(flawlessIVFilterText);
  m_filterMenu->ClearItems();
  m_filterMenu->AddItem(m_flawlessIVsMenuItem);
  m_filterMenu->AddItem(m_shinyFilterMenuItem);
  m_filterMenu->AddItem(m_flawlessIVFilterMenuItem);
}

void RaidSearchSettingsLayout::IncrementShinyTypeFilter() {
  csight::shiny::ShinyType newShinyTypeFilter = csight::shiny::None;
  auto shinyTypeFilter = m_raidSearchSettings->GetShinyTypeFilter();

  switch (shinyTypeFilter) {
    case csight::shiny::Any:
      newShinyTypeFilter = csight::shiny::None;
      break;
    case csight::shiny::None:
      newShinyTypeFilter = csight::shiny::Star;
      break;
    case csight::shiny::Star:
      newShinyTypeFilter = csight::shiny::Square;
      break;
    case csight::shiny::Square:
    default:
      newShinyTypeFilter = csight::shiny::Any;
      break;
  }

  m_raidSearchSettings->SetShinyTypeFilter(newShinyTypeFilter);
}

void RaidSearchSettingsLayout::DecrementShinyTypeFilter() {
  csight::shiny::ShinyType newShinyTypeFilter = csight::shiny::None;
  auto shinyTypeFilter = m_raidSearchSettings->GetShinyTypeFilter();

  switch (shinyTypeFilter) {
    case csight::shiny::Any:
      newShinyTypeFilter = csight::shiny::Square;
      break;
    case csight::shiny::Square:
      newShinyTypeFilter = csight::shiny::Star;
      break;
    case csight::shiny::Star:
      newShinyTypeFilter = csight::shiny::None;
      break;
    case csight::shiny::None:
    default:
      newShinyTypeFilter = csight::shiny::Any;
      break;
  }

  m_raidSearchSettings->SetShinyTypeFilter(newShinyTypeFilter);
}

void RaidSearchSettingsLayout::IncrementFlawlessIVFilter() {
  auto flawlessIVFilter = m_raidSearchSettings->GetFlawlessIVFilter();
  m_raidSearchSettings->SetFlawlessIVFilter(flawlessIVFilter >= 6 ? 1 : flawlessIVFilter + 1);
}

void RaidSearchSettingsLayout::DecrementFlawlessIVFilter() {
  auto flawlessIVFilter = m_raidSearchSettings->GetFlawlessIVFilter();
  m_raidSearchSettings->SetFlawlessIVFilter(flawlessIVFilter <= 1 ? 6 : flawlessIVFilter - 1);
}

void RaidSearchSettingsLayout::IncrementFlawlessIVs() {
  auto flawlessIVs = m_raidSearchSettings->GetFlawlessIVs();
  m_raidSearchSettings->SetFlawlessIVs(flawlessIVs >= 5 ? 1 : flawlessIVs + 1);
}

void RaidSearchSettingsLayout::DecrementFlawlessIVs() {
  auto flawlessIVs = m_raidSearchSettings->GetFlawlessIVs();
  m_raidSearchSettings->SetFlawlessIVs(flawlessIVs <= 1 ? 5 : flawlessIVs - 1);
}
