#include <vector>
#include <pu/Plutonium>
#include <ui/PokemonListLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void PokemonListLayout::UpdateValues(std::vector<std::shared_ptr<PK8>> pk8s, std::function<std::string(u32)> GetTitle) {
  this->Clear();
  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  for (auto pk8 = pk8s.begin(); pk8 != end(pk8s); ++pk8) {
    auto pkm = *(pk8);
    u32 slot = std::distance(pk8s.begin(), pk8);
    std::string species = i18n->Translate("species", std::to_string(pkm->GetSpecies()));
    std::string shinyTranslationKey = pkm->GetIsShiny() ? "Shiny" : "Not shiny";
    std::string title = species + " - " + pkm->GetFormattedIVs() + " - " + i18n->Translate(shinyTranslationKey) + " - " + GetTitle(slot);
    auto menuItem = this->CreateMenuItem(pkm, slot, title);

    this->menu->AddItem(menuItem);
  }

  this->Add(this->menu);
}

pu::ui::elm::MenuItem::Ref PokemonListLayout::CreateMenuItem(std::shared_ptr<PK8> pk8, u32 slot, std::string title) {
  auto menuItem = pu::ui::elm::MenuItem::New(title);

  menuItem->SetColor(gsets.GetTheme().text.light);
  menuItem->SetIcon(getPokemonIconPath(pk8->GetSpecies(), pk8->GetIsEgg()));
  menuItem->AddOnClick(std::bind(&PokemonListLayout::ClickMenuItem, this, slot));

  return menuItem;
}

void PokemonListLayout::ClickMenuItem(u32 slot) {
  this->onMenuItemInput(slot);
}

void PokemonListLayout::SetOnInputMenuItem(std::function<void(u32)> onInput) {
  this->onMenuItemInput = onInput;
}

void PokemonListLayout::SetSelectedIndex(u32 index) {
  this->menu->SetSelectedIndex(index);
}