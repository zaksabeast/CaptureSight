#include <ui/DenMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/ConvertNumToHexString.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void DenMenuLayout::UpdateValues(std::vector<std::shared_ptr<Den>> dens) {
  this->Clear();
  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  for (auto denIterator = dens.begin(); denIterator != end(dens); ++denIterator) {
    auto den = *(denIterator);
    auto seed = ConvertNumToHexString(den->GetSeed());
    std::string title = i18n->Translate("Den Id") + ": " + std::to_string(den->GetDenId()) + " - " + seed + ", " + i18n->Translate("Stars") + ": " +
                        std::to_string(den->GetStars());
    auto menuItem = pu::ui::elm::MenuItem::New(title);
    menuItem->SetColor(gsets.GetTheme().text.light);
    menuItem->AddOnClick([&] {});
    this->menu->AddItem(menuItem);
  }

  this->Add(this->menu);
}