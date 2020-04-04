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
  m_instructionTextBlock = pu::ui::elm::TextBlock::New(50, 50, "View details (A), View type matches (Y)", 25);
  m_instructionTextBlock->SetColor(gsets.GetTheme().text.light);
  this->Add(m_menu);
  this->Add(m_instructionTextBlock);
}

void PokemonListLayout::UpdateValues(std::vector<std::shared_ptr<csight::PK8>> pk8s, std::function<std::string(u32)> GetTitle) {
  m_menu->ClearItems();

  for (u32 i = 0; i < pk8s.size(); i++) {
    auto pk8 = pk8s[i];
    auto formattedIVs = csight::utils::joinNums(pk8->GetIVs(), "/");
    std::string species = i18n->Translate("species", pk8->GetSpeciesString());
    std::string shinyTranslationKey = pk8->GetIsShiny() ? "Shiny" : "Not Shiny";
    std::string title = pk8->GetIsValid()
        ? species + " - " + formattedIVs + " - " + i18n->Translate(shinyTranslationKey) + " - " + GetTitle(i)
        : i18n->Translate("Empty") + " - " + GetTitle(i);
    auto menuItem = this->CreateMenuItem(pk8, i, title);

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

s32 PokemonListLayout::GetSelectedIndex() {
  return m_menu->GetSelectedIndex();
}