#include <csight/core>
#include <functional>
#include <pu/Plutonium>
#include <ui/MainApplication.hpp>
#include <ui/views/RaidSearchSettingsLayout.hpp>
#include <utils/Constants.hpp>
#include <utils/I18N.hpp>
#include <utils/Settings.hpp>

extern MainApplication::Ref mainApp;
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

#define SETUP_MENU_ITEM(menu, item, Increment, Decrement) \
  item = pu::ui::elm::MenuItem::New("");                  \
  item->SetColor(gsets.GetTheme().text.light);            \
  item->AddOnClick(std::bind(&Increment, this), KEY_R);   \
  item->AddOnClick(std::bind(&Decrement, this), KEY_L);   \
  menu->AddItem(item);

RaidSearchSettingsLayout::RaidSearchSettingsLayout() : Layout::Layout() {
  auto raidSearchSettingsText = i18n->Translate("Raid Search Settings");
  auto intructionsText = i18n->Translate("(A) or (B) to apply filters, (L) and (R) to change filters");

  m_titleTextBlock = pu::ui::elm::TextBlock::New(100, 90, raidSearchSettingsText, 30);
  m_titleTextBlock->SetColor(gsets.GetTheme().text.light);
  m_instructionsTextBlock = pu::ui::elm::TextBlock::New(100, 150, intructionsText, 25);
  m_instructionsTextBlock->SetColor(gsets.GetTheme().text.light);
  m_filterMenu = pu::ui::elm::Menu::New(100, 220, SCREEN_MAX_WIDTH / 2, gsets.GetTheme().active.dark, 80, 6);

  SETUP_MENU_ITEM(m_filterMenu, m_shinyFilterMenuItem, RaidSearchSettingsLayout::IncrementShinyTypeFilter,
                  RaidSearchSettingsLayout::DecrementShinyTypeFilter);
  SETUP_MENU_ITEM(m_filterMenu, m_flawlessIVFilterMenuItem, RaidSearchSettingsLayout::IncrementFlawlessIVFilter,
                  RaidSearchSettingsLayout::DecrementFlawlessIVFilter);
  SETUP_MENU_ITEM(m_filterMenu, m_abilityFiltermenuItem, RaidSearchSettingsLayout::IncrementAbilityFilter,
                  RaidSearchSettingsLayout::DecrementAbilityFilter);
  SETUP_MENU_ITEM(m_filterMenu, m_denIndexMenuItem, RaidSearchSettingsLayout::IncrementDenIndex,
                  RaidSearchSettingsLayout::DecrementDenIndex);
  SETUP_MENU_ITEM(m_filterMenu, m_spawnIndexMenuItem, RaidSearchSettingsLayout::IncrementEncounterIndex,
                  RaidSearchSettingsLayout::DecrementEncounterIndex);
  SETUP_MENU_ITEM(m_filterMenu, m_isRareDenFilterMenuItem, RaidSearchSettingsLayout::ToggleIsRareDenFilter,
                  RaidSearchSettingsLayout::ToggleIsRareDenFilter);

  this->Add(m_titleTextBlock);
  this->Add(m_filterMenu);
  this->Add(m_instructionsTextBlock);

  // Set correct den 0 encounter
  this->SetEncounterIndex(0);
}

void RaidSearchSettingsLayout::UpdateValues() {
  auto searchSettings = mainApp->GetRaidSearchSettings();
  std::string shinyFilterText
      = i18n->Translate("Shiny filter") + " - " + i18n->Translate(GetShinyTypeName(searchSettings->GetShinyTypeFilter()));
  std::string flawlessIVFilterText
      = i18n->Translate("Flawless IV filter") + " - " + std::to_string(searchSettings->GetFlawlessIVFilter());
  std::string abilityFilterText
      = i18n->Translate("Ability filter") + " - " + csight::ability::GetAbilityFilterString(searchSettings->GetAbilityFilter());
  std::string rareDenFilterText = m_isRareDenFilter ? i18n->Translate("Rare den") : i18n->Translate("Regular den");
  std::string denIndexText = i18n->Translate("Den Id filter") + " - " + std::to_string(m_denIndex + 1);
  auto nest = searchSettings->GetRaidEncounter();
  u8 lowestStar = 0;
  u8 highestStar = 0;

  for (u32 i = 0; i < nest.probabilities.size(); i++) {
    if (nest.probabilities[i] != 0) {
      if (lowestStar == 0) {
        lowestStar = i + 1;
      }
      highestStar = i + 1;
    }
  }

  std::string starText
      = lowestStar == highestStar ? std::to_string(lowestStar) : std::to_string(lowestStar) + "-" + std::to_string(highestStar);
  std::string speciesName = i18n->Translate("species", csight::utils::getSpeciesName(nest.species));
  std::string spawnText = i18n->Translate("Spawn filter") + " - " + speciesName + " " + starText + "★";

  m_shinyFilterMenuItem->SetName(shinyFilterText);
  m_flawlessIVFilterMenuItem->SetName(flawlessIVFilterText);
  m_abilityFiltermenuItem->SetName(abilityFilterText);
  m_isRareDenFilterMenuItem->SetName(rareDenFilterText);
  m_denIndexMenuItem->SetName(denIndexText);
  m_spawnIndexMenuItem->SetName(spawnText);
  m_filterMenu->ClearItems();
  m_filterMenu->AddItem(m_shinyFilterMenuItem);
  m_filterMenu->AddItem(m_flawlessIVFilterMenuItem);
  m_filterMenu->AddItem(m_abilityFiltermenuItem);
  m_filterMenu->AddItem(m_isRareDenFilterMenuItem);
  m_filterMenu->AddItem(m_denIndexMenuItem);
  m_filterMenu->AddItem(m_spawnIndexMenuItem);
}

void RaidSearchSettingsLayout::IncrementAbilityFilter() {
  csight::ability::filter::AbilityFilter newAbilityFilter = csight::ability::filter::Any;
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto abilityFilter = searchSettings->GetAbilityFilter();

  switch (abilityFilter) {
    case csight::ability::filter::Any:
      newAbilityFilter = csight::ability::filter::First;
      break;
    case csight::ability::filter::First:
      newAbilityFilter = csight::ability::filter::Second;
      break;
    case csight::ability::filter::Second:
      newAbilityFilter = csight::ability::filter::Hidden;
      break;
    default:
    case csight::ability::filter::Hidden:
      newAbilityFilter = csight::ability::filter::Any;
      break;
  }

  searchSettings->SetAbilityFilter(newAbilityFilter);
}

void RaidSearchSettingsLayout::DecrementAbilityFilter() {
  csight::ability::filter::AbilityFilter newAbilityFilter = csight::ability::filter::Any;
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto abilityFilter = searchSettings->GetAbilityFilter();

  switch (abilityFilter) {
    case csight::ability::filter::Any:
      newAbilityFilter = csight::ability::filter::Hidden;
      break;
    case csight::ability::filter::First:
      newAbilityFilter = csight::ability::filter::Any;
      break;
    case csight::ability::filter::Second:
      newAbilityFilter = csight::ability::filter::First;
      break;
    default:
    case csight::ability::filter::Hidden:
      newAbilityFilter = csight::ability::filter::Second;
      break;
  }

  searchSettings->SetAbilityFilter(newAbilityFilter);
}

void RaidSearchSettingsLayout::IncrementShinyTypeFilter() {
  csight::shiny::ShinyType newShinyTypeFilter = csight::shiny::None;
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto shinyTypeFilter = searchSettings->GetShinyTypeFilter();

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

  searchSettings->SetShinyTypeFilter(newShinyTypeFilter);
}

void RaidSearchSettingsLayout::DecrementShinyTypeFilter() {
  csight::shiny::ShinyType newShinyTypeFilter = csight::shiny::None;
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto shinyTypeFilter = searchSettings->GetShinyTypeFilter();

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

  searchSettings->SetShinyTypeFilter(newShinyTypeFilter);
}

void RaidSearchSettingsLayout::IncrementFlawlessIVFilter() {
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto flawlessIVFilter = searchSettings->GetFlawlessIVFilter();
  searchSettings->SetFlawlessIVFilter(flawlessIVFilter >= 6 ? 1 : flawlessIVFilter + 1);
}

void RaidSearchSettingsLayout::DecrementFlawlessIVFilter() {
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto flawlessIVFilter = searchSettings->GetFlawlessIVFilter();
  searchSettings->SetFlawlessIVFilter(flawlessIVFilter <= 1 ? 6 : flawlessIVFilter - 1);
}

void RaidSearchSettingsLayout::IncrementDenIndex() {
  auto encounterTables = mainApp->GetGameReader()->GetEncounterTables();
  auto nests = encounterTables;
  m_denIndex = m_denIndex >= DEN_LIST_SIZE - 1 ? 0 : m_denIndex + 1;
  this->SetEncounterIndex(0);
}

void RaidSearchSettingsLayout::DecrementDenIndex() {
  auto encounterTables = mainApp->GetGameReader()->GetEncounterTables();
  auto nests = encounterTables;
  m_denIndex = m_denIndex <= 0 ? DEN_LIST_SIZE - 1 : m_denIndex - 1;
  this->SetEncounterIndex(0);
}

void RaidSearchSettingsLayout::SetEncounterIndex(u32 encounterIndex) {
  m_encounterIndex = encounterIndex;
  auto searchSettings = mainApp->GetRaidSearchSettings();
  auto encounterTables = mainApp->GetGameReader()->GetEncounterTables();
  auto nests = csight::utils::findRaidEncounterTable(encounterTables, m_denIndex, m_isRareDenFilter);
  auto encounter = nests.templates[m_encounterIndex];
  searchSettings->SetRaidEncounter(encounter);
}

void RaidSearchSettingsLayout::IncrementEncounterIndex() {
  auto encounterTables = mainApp->GetGameReader()->GetEncounterTables();
  auto nests = csight::utils::findRaidEncounterTable(encounterTables, m_denIndex, m_isRareDenFilter);
  auto templates = nests.templates;
  auto encounterIndex = m_encounterIndex >= templates.size() - 1 ? 0 : m_encounterIndex + 1;
  this->SetEncounterIndex(encounterIndex);
}

void RaidSearchSettingsLayout::DecrementEncounterIndex() {
  auto encounterTables = mainApp->GetGameReader()->GetEncounterTables();
  auto nests = csight::utils::findRaidEncounterTable(encounterTables, m_denIndex, m_isRareDenFilter);
  auto templates = nests.templates;
  auto encounterIndex = m_encounterIndex <= 0 ? templates.size() - 1 : m_encounterIndex - 1;
  this->SetEncounterIndex(encounterIndex);
}

void RaidSearchSettingsLayout::ToggleIsRareDenFilter() {
  m_isRareDenFilter = !m_isRareDenFilter;
  this->SetEncounterIndex(0);
}