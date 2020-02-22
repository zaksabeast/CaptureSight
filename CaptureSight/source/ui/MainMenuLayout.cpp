#include <string>
#include <functional>
#include <stratosphere.hpp>
#include <pu/Plutonium>
#include <ui/MainMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

MainMenuLayout::MainMenuLayout() : Layout::Layout() {
  this->onMenuItemInput = [&](ViewMode) {};
  this->menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);
  this->wildMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Wild and Trade Pokemon"));
  this->wildMenuItem->SetColor(gsets.GetTheme().text.light);
  this->wildMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, wild));
  this->partyMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Party Pokemon"));
  this->partyMenuItem->SetColor(gsets.GetTheme().text.light);
  this->partyMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, party));
  this->boxMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Box Pokemon"));
  this->boxMenuItem->SetColor(gsets.GetTheme().text.light);
  this->boxMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, box));
  this->activeDenMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Active Den List"));
  this->activeDenMenuItem->SetColor(gsets.GetTheme().text.light);
  this->activeDenMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, activeDens));
  this->allDensMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("All Dens List"));
  this->allDensMenuItem->SetColor(gsets.GetTheme().text.light);
  this->allDensMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, allDens));

  this->menu->AddItem(this->wildMenuItem);
  this->menu->AddItem(this->partyMenuItem);
  this->menu->AddItem(this->boxMenuItem);
  this->menu->AddItem(this->activeDenMenuItem);
  this->menu->AddItem(this->allDensMenuItem);
  this->Add(this->menu);
}

void MainMenuLayout::ClickMenuItem(ViewMode mode) {
  this->onMenuItemInput(mode);
}

void MainMenuLayout::SetOnInputMenuItem(std::function<void(ViewMode)> onInput) {
  this->onMenuItemInput = onInput;
}