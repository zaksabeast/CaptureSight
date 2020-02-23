#include <string>
#include <functional>
#include <stratosphere.hpp>
#include <pu/Plutonium>
#include <ui/views/MainMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

MainMenuLayout::MainMenuLayout() : Layout::Layout() {
  m_onMenuItemInput = [&](ViewMode) {};
  m_menu = pu::ui::elm::Menu::New(0, 120, SCREEN_MAX_WIDTH, gsets.GetTheme().active.dark, 150, 4);
  m_wildMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Wild and Trade Pokemon"));
  m_wildMenuItem->SetColor(gsets.GetTheme().text.light);
  m_wildMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, wild));
  m_partyMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Party Pokemon"));
  m_partyMenuItem->SetColor(gsets.GetTheme().text.light);
  m_partyMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, party));
  m_boxMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Box Pokemon"));
  m_boxMenuItem->SetColor(gsets.GetTheme().text.light);
  m_boxMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, box));
  m_activeDenMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("Active Den List"));
  m_activeDenMenuItem->SetColor(gsets.GetTheme().text.light);
  m_activeDenMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, activeDens));
  m_allDensMenuItem = pu::ui::elm::MenuItem::New(i18n->Translate("All Dens List"));
  m_allDensMenuItem->SetColor(gsets.GetTheme().text.light);
  m_allDensMenuItem->AddOnClick(std::bind(&MainMenuLayout::ClickMenuItem, this, allDens));

  m_menu->AddItem(m_wildMenuItem);
  m_menu->AddItem(m_partyMenuItem);
  m_menu->AddItem(m_boxMenuItem);
  m_menu->AddItem(m_activeDenMenuItem);
  m_menu->AddItem(m_allDensMenuItem);
  this->Add(m_menu);
}

void MainMenuLayout::ClickMenuItem(ViewMode mode) {
  m_onMenuItemInput(mode);
}

void MainMenuLayout::SetOnInputMenuItem(std::function<void(ViewMode)> onInput) {
  m_onMenuItemInput = onInput;
}