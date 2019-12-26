#include <ui/DenMenuLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/ConvertNumToHexString.hpp>
#include <utils/Utils.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void DenMenuLayout::UpdateValues(std::vector<std::shared_ptr<Den>> dens) {
  this->Clear();
  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  for (auto denIterator = dens.begin(); denIterator != end(dens); ++denIterator) {
    auto den = *(denIterator);
    auto pkm = den->GetPKM();
    auto formattedIVs = joinNums(pkm->GetIVs(), "/");
    auto seed = ConvertNumToHexString(den->GetSeed());
    auto stars = std::to_string(den->GetDisplayStars());
    std::string title = i18n->Translate("Den Id") + ": " + std::to_string(den->GetDenId()) + " - " + seed + " - " + i18n->Translate("IVs") + ": " +
                        formattedIVs + ", " + i18n->Translate("Stars") + ": " + stars;
    auto menuItem = pu::ui::elm::MenuItem::New(title);

    menuItem->SetColor(gsets.GetTheme().text.light);
    menuItem->SetIcon(getPokemonIconPath(pkm->GetSpecies(), false));
    menuItem->AddOnClick([&] {});
    this->menu->AddItem(menuItem);
  }

  this->Add(this->menu);
}