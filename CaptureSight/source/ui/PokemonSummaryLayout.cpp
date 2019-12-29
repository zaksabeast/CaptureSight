#include <string>
#include <stratosphere.hpp>
#include <ui/PokemonSprite.hpp>
#include <ui/PokemonSummaryLayout.hpp>
#include <utils/GameReader.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/ConvertNumToHexString.hpp>
#include <utils/Utils.hpp>

extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void PokemonSummaryLayout::UpdateValues(std::string title, PK8* pkm, bool isShowingExtraDetail) {
  this->Clear();

  std::string instructions = i18n->Translate("More detail (X), Go back (B)");
  std::string moves = i18n->Translate("moves", std::to_string(pkm->GetMove(0)));
  std::string species = i18n->Translate("species", std::to_string(pkm->GetSpecies()));
  std::string nature = i18n->Translate("Nature") + ": " + i18n->Translate("natures", std::to_string(pkm->GetNature()));
  std::string mintedNature = i18n->Translate("Minted Nature") + ": " + i18n->Translate("natures", std::to_string(pkm->GetMintedNature()));
  std::string shinyTranslationKey = pkm->GetIsShiny() ? "Shiny" : "Not Shiny";
  std::string formattedIVs = i18n->Translate("IVs") + ": " + joinNums(pkm->GetIVs(), "/");
  std::string formattedEVs = i18n->Translate("EVs") + ": " + joinNums(pkm->GetEVs(), "/");
  std::string shiny = i18n->Translate("PSV") + " " + std::to_string(pkm->GetPSV()) + ", " + i18n->Translate("TSV") + " " +
                      std::to_string(pkm->GetTSV()) + ", " + i18n->Translate(shinyTranslationKey);
  std::string pidEc = i18n->Translate("PID") + ": " + ConvertNumToHexString(pkm->GetPID()) + ", " + i18n->Translate("EC") + ": " +
                      ConvertNumToHexString(pkm->GetEncryptionConstant());
  std::string friendshipTranslationKey = pkm->GetIsEgg() ? "Egg cycles" : "Friendship";
  std::string friendship = i18n->Translate(friendshipTranslationKey) + ": " + std::to_string(pkm->GetCurrentFriendship());

  for (u8 i = 1; i < 4; i++) {
    moves += ", " + i18n->Translate("moves", std::to_string(pkm->GetMove(i)));
  }

  this->spriteImage = createPokemonSprite(0, 0, 4, pkm->GetSpecies(), pkm->GetIsEgg());
  this->speciesBackgroundRectangle =
      pu::ui::elm::Rectangle::New(0, 0, 1280, this->spriteImage->GetHeight() + 50, gsets.GetTheme().background.light, 50);
  this->titleTextBlock = pu::ui::elm::TextBlock::New(700, 55, title, 50);
  this->titleTextBlock->SetColor(gsets.GetTheme().text.light);
  this->speciesNameTextBlock = pu::ui::elm::TextBlock::New(300, 55, species, 40);
  this->speciesNameTextBlock->SetColor(gsets.GetTheme().text.light);
  this->ivTextBlock = pu::ui::elm::TextBlock::New(300, 150, formattedIVs, 25);
  this->ivTextBlock->SetColor(gsets.GetTheme().text.light);
  this->evTextBlock = pu::ui::elm::TextBlock::New(300, 200, formattedEVs, 25);
  this->evTextBlock->SetColor(gsets.GetTheme().text.light);
  this->shinyInfoTextBlock = pu::ui::elm::TextBlock::New(100, 420, shiny, 25);
  this->shinyInfoTextBlock->SetColor(gsets.GetTheme().text.light);
  this->moveTextBlock = pu::ui::elm::TextBlock::New(100, 470, moves, 25);
  this->moveTextBlock->SetColor(gsets.GetTheme().text.light);
  this->natureTextBlock = pu::ui::elm::TextBlock::New(100, 520, nature, 25);
  this->natureTextBlock->SetColor(gsets.GetTheme().text.light);
  this->mintedNatureTextBlock = pu::ui::elm::TextBlock::New(100, 570, mintedNature, 25);
  this->mintedNatureTextBlock->SetColor(gsets.GetTheme().text.light);
  this->pidEcTextBlock = pu::ui::elm::TextBlock::New(700, 420, pidEc, 25);
  this->pidEcTextBlock->SetColor(gsets.GetTheme().text.light);
  this->instructionsTextBlock = pu::ui::elm::TextBlock::New(700, 620, instructions, 25);
  this->instructionsTextBlock->SetColor(gsets.GetTheme().text.light);
  this->friendshipTextBlock = pu::ui::elm::TextBlock::New(700, 520, friendship, 25);
  this->friendshipTextBlock->SetColor(gsets.GetTheme().text.light);

  this->Add(this->speciesBackgroundRectangle);
  this->Add(this->spriteImage);
  this->Add(this->speciesNameTextBlock);
  this->Add(this->ivTextBlock);
  this->Add(this->evTextBlock);
  this->Add(this->titleTextBlock);
  this->Add(this->shinyInfoTextBlock);
  this->Add(this->moveTextBlock);
  this->Add(this->natureTextBlock);
  this->Add(this->mintedNatureTextBlock);
  this->Add(this->instructionsTextBlock);
  this->Add(this->friendshipTextBlock);

  if (isShowingExtraDetail) {
    this->Add(this->pidEcTextBlock);
  }
}