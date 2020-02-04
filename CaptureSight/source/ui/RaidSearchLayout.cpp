#include <csight/core>
#include <ui/RaidSearchLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

RaidSearchLayout::RaidSearchLayout() : Layout::Layout() {
  this->headerTextBlock = pu::ui::elm::TextBlock::New(50, 50, "", 25);
  this->headerTextBlock->SetColor(gsets.GetTheme().text.light);
  this->menu = pu::ui::elm::Menu::New(0, 120, 1280, gsets.GetTheme().active.dark, 150, 4);

  this->Add(this->headerTextBlock);
  this->Add(this->menu);
}

void RaidSearchLayout::UpdateValues() {
  uint shinyFrame = 0;
  std::string headerText = i18n->Translate("No raid seed found!  This may not be a raid Pokemon");
  auto seedString = csight::utils::convertNumToHexString(this->seed);
  ulong nextSeed = this->seed;
  this->menu->ClearItems();

  if (this->seed > 0) {
    for (uint frame = 0; frame < 9999; frame++) {
      auto raid = new raid::RaidPokemon(nextSeed, this->flawlessIVs, 0);
      auto rng = rng::xoroshiro(nextSeed);
      nextSeed = rng.nextulong();

      auto isShiny = raid->GetIsShiny();
      auto shinyText = "Not shiny";

      if (isShiny) {
        shinyFrame = shinyFrame == 0 ? frame : shinyFrame;
        shinyText = "Shiny";
      }

      auto formattedIVs = csight::utils::joinNums(raid->GetIVs(), "/");
      std::string title = i18n->Translate("Frame") + " " + std::to_string(frame) + " - " + i18n->Translate("IVs") + ": " + formattedIVs + " ★ " +
                          i18n->Translate("Shiny") + ": " + shinyText;
      auto menuItem = pu::ui::elm::MenuItem::New(title);

      menuItem->SetColor(gsets.GetTheme().text.light);
      this->menu->AddItem(menuItem);
    }

    headerText = i18n->Translate("Seed") + ": " + seedString + ", " + i18n->Translate("Shiny") + " " + std::to_string(shinyFrame) + ", (-L) " +
                 i18n->Translate("Flawless IVs") + " " + std::to_string(this->flawlessIVs) + " (+R)";
  }

  this->headerTextBlock->SetText(headerText);
}

void RaidSearchLayout::SetSeed(ulong seed) {
  this->seed = seed;
}

void RaidSearchLayout::IncreaseFlawlessIVs() {
  this->flawlessIVs = this->flawlessIVs >= 5 ? 1 : this->flawlessIVs + 1;
}

void RaidSearchLayout::DecreaseFlawlessIVs() {
  this->flawlessIVs = this->flawlessIVs == 1 ? 5 : this->flawlessIVs - 1;
}
