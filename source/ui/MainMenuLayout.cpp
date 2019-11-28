#include <string>
#include <functional>
#include <stratosphere.hpp>
#include <pu/Plutonium>
#include <ui/MainMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;

MainMenuLayout::MainMenuLayout() : Layout::Layout() {
  this->onMenuItemInput = [&](PokemonViewMode) {};
  this->menu = pu::ui::elm::Menu::New(0, 100, 1280, gsets.GetTheme().active.dark, 160, 3);
  this->wildMenuItem = pu::ui::elm::MenuItem::New("Wild Pokemon");
  this->wildMenuItem->SetColor(gsets.GetTheme().text.light);
  this->wildMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickWildPokemon, this));
  this->partyMenuItem = pu::ui::elm::MenuItem::New("Party Pokemon");
  this->partyMenuItem->SetColor(gsets.GetTheme().text.light);
  this->partyMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, party));
  this->boxMenuItem = pu::ui::elm::MenuItem::New("Box Pokemon");
  this->boxMenuItem->SetColor(gsets.GetTheme().text.light);
  this->boxMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, box));

  this->menu->AddItem(this->wildMenuItem);
  this->menu->AddItem(this->partyMenuItem);
  this->menu->AddItem(this->boxMenuItem);
  this->Add(this->menu);
}

void MainMenuLayout::ClickMenuItem(PokemonViewMode mode) {
  this->onMenuItemInput(mode);
}

void MainMenuLayout::ClickWildPokemon() {
  mainApp->SetViewMode(wild);
}

void MainMenuLayout::SetOnInputMenuItem(std::function<void(PokemonViewMode)> onInput) {
  this->onMenuItemInput = onInput;
}