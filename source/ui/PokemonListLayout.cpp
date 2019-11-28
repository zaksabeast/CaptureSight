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

PokemonListLayout::PokemonListLayout() : Layout::Layout() {
  this->menu = pu::ui::elm::Menu::New(0, 100, 1280, gsets.GetTheme().active.dark, 160, 3);
  this->Add(this->menu);
}

void PokemonListLayout::UpdateValues(std::vector<std::shared_ptr<PK8>> pk8s) {
  this->Clear();
  this->menuItems.clear();
  this->menu = pu::ui::elm::Menu::New(0, 100, 1280, gsets.GetTheme().active.dark, 160, 3);

  for (auto pk8 = begin(pk8s); pk8 != end(pk8s); ++pk8) {
    auto menuItem = this->GetMenuItem(pk8->get(), std::distance(pk8s.begin(), pk8));
    this->menuItems.push_back(menuItem);
    this->menu->AddItem(menuItem);
  }

  this->Add(this->menu);
}

pu::ui::elm::MenuItem::Ref PokemonListLayout::GetMenuItem(PK8* pkm, u32 slot) {
  std::string itemText = i18n->GetPokemonName(pkm->GetSpecies()) + " - " + pkm->GetFormattedIVs();
  auto menuItem = pu::ui::elm::MenuItem::New(itemText);
  menuItem->SetColor(gsets.GetTheme().text.light);
  menuItem->SetIcon(getPokemonIconPath(pkm->GetSpecies()));
  menuItem->AddOnClick(std::bind(&PokemonListLayout::OnInputPokemonItem, this, slot));

  return menuItem;
}

void PokemonListLayout::OnInputPokemonItem(u32 slot) {
  mainApp->SetSlot(slot);
  mainApp->LoadLayout(mainApp->GetPokemonSummaryLayout());
}