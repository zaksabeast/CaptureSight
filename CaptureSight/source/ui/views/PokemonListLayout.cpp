#include <csight/core>
#include <pu/Plutonium>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <utils/Constants.hpp>
#include <utils/I18N.hpp>
#include <utils/Settings.hpp>
#include <vector>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

PokemonListLayout::PokemonListLayout() : Layout::Layout() {
  m_menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);
  this->Add(m_menu);
}

void PokemonListLayout::UpdateValues(std::vector<std::shared_ptr<csight::PK8>> pk8s, std::function<std::string(u32)> GetTitle) {
  m_menu->ClearItems();

  for (auto pk8 = pk8s.begin(); pk8 != end(pk8s); ++pk8) {
    auto pkm = *(pk8);
    auto formattedIVs = csight::utils::joinNums(pkm->GetIVs(), "/");
    u32 slot = std::distance(pk8s.begin(), pk8);
    std::string species = i18n->Translate("species", pkm->GetSpeciesString());
    std::string shinyTranslationKey = pkm->GetIsShiny() ? "Shiny" : "Not Shiny";
    std::string title = pkm->GetIsValid()
        ? species + " - " + formattedIVs + " - " + i18n->Translate(shinyTranslationKey) + " - " + GetTitle(slot)
        : i18n->Translate("Empty") + " - " + GetTitle(slot);
    auto menuItem = this->CreateMenuItem(pkm, slot, title);

    m_menu->AddItem(menuItem);
  }

  m_menu->SetSelectedIndex(0);
}

pu::ui::elm::MenuItem::Ref PokemonListLayout::CreateMenuItem(std::shared_ptr<csight::PK8> pk8, u32 slot, std::string title) {
  auto menuItem = pu::ui::elm::MenuItem::New(title);

  menuItem->SetColor(gsets.GetTheme().text.light);
  menuItem->SetIcon(getPokemonIconPath(pk8->GetSpecies(), pk8->GetIsEgg(), pk8->GetIsShiny()));
  menuItem->AddOnClick(std::bind(&PokemonListLayout::ClickMenuItem, this, slot));

  return menuItem;
}

void PokemonListLayout::ClickMenuItem(u32 slot) {
  m_onMenuItemInput(slot);
}

void PokemonListLayout::SetOnInputMenuItem(std::function<void(u32)> onInput) {
  m_onMenuItemInput = onInput;
}

void PokemonListLayout::SetSelectedIndex(u32 index) {
  m_menu->SetSelectedIndex(index);
}