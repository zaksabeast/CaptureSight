#include <functional>
#include <csight/core>
#include <ui/DenMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

DenMenuLayout::DenMenuLayout() : Layout::Layout() {
  this->headerTextBlock = pu::ui::elm::TextBlock::New(50, 50, "", 25);
  this->headerTextBlock->SetColor(gsets.GetTheme().text.light);

  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  this->Add(this->menu);
  this->Add(this->headerTextBlock);
}

void DenMenuLayout::UpdateValues(std::vector<std::shared_ptr<csight::raid::Den>> dens) {
  this->menu->ClearItems();

  for (auto denIterator = dens.begin(); denIterator != end(dens); ++denIterator) {
    auto den = *(denIterator);
    auto pkm = den->GetPKM();
    auto formattedIVs = csight::utils::joinNums(pkm->GetIVs(), "/");
    auto stars = std::to_string(den->GetDisplayStars());
    auto shinyframe = std::to_string(den->GetShinyFrame());
    std::string eventText = den->GetIsEvent() ? " - " + i18n->Translate("Event") : "";
    std::string title = i18n->Translate("Den Id") + ": " + std::to_string(den->GetDenId()) + " - " + i18n->Translate("IVs") + ": " + formattedIVs +
                        ", " + stars + "★ " + i18n->Translate("Shiny") + ": " + shinyframe + eventText;
    auto menuItem = pu::ui::elm::MenuItem::New(title);

    menuItem->SetColor(gsets.GetTheme().text.light);
    menuItem->SetIcon(getPokemonIconPath(pkm->GetSpecies(), false));
    menuItem->AddOnClick(std::bind(&DenMenuLayout::ClickMenuItem, this, den->GetSeed()));
    this->menu->AddItem(menuItem);
  }

  this->menu->SetSelectedIndex(0);

  auto headerText = i18n->Translate("View upcoming frames (A)");

  this->headerTextBlock->SetText(headerText);
}

void DenMenuLayout::ClickMenuItem(u64 seed) {
  this->onMenuItemInput(seed);
}

void DenMenuLayout::SetOnInputMenuItem(std::function<void(u64)> onInput) {
  this->onMenuItemInput = onInput;
}
