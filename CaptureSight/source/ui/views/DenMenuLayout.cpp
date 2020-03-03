#include <functional>
#include <csight/core>
#include <ui/views/DenMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

DenMenuLayout::DenMenuLayout() : Layout::Layout() {
  m_headerTextBlock = pu::ui::elm::TextBlock::New(50, 50, "", 25);
  m_headerTextBlock->SetColor(gsets.GetTheme().text.light);

  m_menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);

  this->Add(m_menu);
  this->Add(m_headerTextBlock);
}

void DenMenuLayout::UpdateValues(std::vector<std::shared_ptr<csight::raid::Den>> dens) {
  m_menu->ClearItems();

  for (auto denIterator = dens.begin(); denIterator != end(dens); ++denIterator) {
    auto den = *(denIterator);
    auto pkm = den->GetPKM();
    auto formattedIVs = csight::utils::joinNums(pkm->GetIVs(), "/");
    auto stars = std::to_string(den->GetDisplayStars());
    std::string eventText = den->GetIsEvent() ? " - " + i18n->Translate("Event") : "";
    std::string title = i18n->Translate("Den Id") + ": " + std::to_string(den->GetDenDisplayId()) + " - " + i18n->Translate("IVs") + ": " +
                        formattedIVs + ", " + stars + "★ " + i18n->Translate("Shiny") + ": " + den->GetShinyAdvanceText() + eventText;
    auto menuItem = pu::ui::elm::MenuItem::New(title);

    menuItem->SetColor(gsets.GetTheme().text.light);
    menuItem->SetIcon(getPokemonIconPath(pkm->GetSpecies(), false));
    menuItem->AddOnClick(std::bind(&DenMenuLayout::ClickMenuItem, this, den->GetSeed()));
    m_menu->AddItem(menuItem);
  }

  m_menu->SetSelectedIndex(0);

  auto headerText = i18n->Translate("View upcoming advances (A)");

  m_headerTextBlock->SetText(headerText);
}

void DenMenuLayout::ClickMenuItem(u64 seed) {
  m_onMenuItemInput(seed);
}

void DenMenuLayout::SetOnInputMenuItem(std::function<void(u64)> onInput) {
  m_onMenuItemInput = onInput;
}
