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
  this->menuItems.clear();
  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  for (auto pk8 = begin(pk8s); pk8 != end(pk8s); ++pk8) {
    auto pkm = *(pk8);
    u32 slot = std::distance(pk8s.begin(), pk8);
    std::string title = i18n->GetPokemonName(pkm->GetSpecies()) + " - " + pkm->GetFormattedIVs() + " - " +
                        (pkm->GetIsShiny() ? "Shiny" : "Not shiny") + " - " + GetTitle(slot);

    auto menuItem = this->CreateMenuItem(pkm, slot, title);
    this->menuItems.push_back(menuItem);
    this->menu->AddItem(menuItem);
  }

  this->Add(this->menu);
}

pu::ui::elm::MenuItem::Ref PokemonListLayout::CreateMenuItem(std::shared_ptr<PK8> pk8, u32 slot, std::string title) {
  auto menuItem = pu::ui::elm::MenuItem::New(title);

  menuItem->SetColor(gsets.GetTheme().text.light);
  menuItem->SetIcon(getPokemonIconPath(pk8->GetSpecies(), pk8->GetIsEgg()));
  menuItem->AddOnClick(std::bind(&PokemonListLayout::OnInputPokemonItem, this, slot));

  return menuItem;
}

void PokemonListLayout::OnInputPokemonItem(u32 slot) {
  mainApp->SetSlot(slot);
  mainApp->LoadLayout(mainApp->GetPokemonSummaryLayout());
}