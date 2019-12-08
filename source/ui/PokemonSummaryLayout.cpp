#include <sstream>
#include <iostream>
#include <string>
#include <stratosphere.hpp>
#include <ui/PokemonSprite.hpp>
#include <ui/PokemonSummaryLayout.hpp>
#include <utils/GameReader.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void PokemonSummaryLayout::UpdateValues(std::string title, PK8* pkm) {
  this->Clear();

  std::string shinyInfo =
      "PSV " + std::to_string(pkm->GetPSV()) + ", TSV " + std::to_string(pkm->GetTSV()) + (pkm->GetIsShiny() ? ", Shiny" : ", Not shiny");
  std::string nature = "Nature: " + i18n->GetPokemonNature(pkm->GetNature());
  std::string moves = i18n->GetPokemonMoveName(pkm->GetMove(0));

  for (u8 i = 1; i < 4; i++) {
    moves += ", " + i18n->GetPokemonMoveName(pkm->GetMove(i));
  }

  this->spriteImage = createPokemonSprite(0, 0, 4, pkm->GetSpecies(), pkm->GetIsEgg());
  this->speciesBackgroundRectangle =
      pu::ui::elm::Rectangle::New(0, 0, 1280, this->spriteImage->GetHeight() + 50, gsets.GetTheme().background.light, 50);
  this->titleTextBlock = pu::ui::elm::TextBlock::New(700, this->spriteImage->GetHeight() / 4, title, 50);
  this->titleTextBlock->SetColor(gsets.GetTheme().text.light);
  this->speciesNameTextBlock = pu::ui::elm::TextBlock::New(300, this->spriteImage->GetHeight() / 4, i18n->GetPokemonName(pkm->GetSpecies()), 40);
  this->speciesNameTextBlock->SetColor(gsets.GetTheme().text.light);
  this->ivTextBlock = pu::ui::elm::TextBlock::New(300, this->spriteImage->GetHeight() / 2, pkm->GetFormattedIVs(), 25);
  this->ivTextBlock->SetColor(gsets.GetTheme().text.light);
  this->shinyInfoTextBlock = pu::ui::elm::TextBlock::New(100, this->spriteImage->GetHeight() + 200, shinyInfo, 25);
  this->shinyInfoTextBlock->SetColor(gsets.GetTheme().text.light);
  this->moveTextBlock = pu::ui::elm::TextBlock::New(100, this->spriteImage->GetHeight() + 250, moves, 25);
  this->moveTextBlock->SetColor(gsets.GetTheme().text.light);
  this->natureTextBlock = pu::ui::elm::TextBlock::New(100, this->spriteImage->GetHeight() + 300, nature, 25);
  this->natureTextBlock->SetColor(gsets.GetTheme().text.light);

  this->Add(this->speciesBackgroundRectangle);
  this->Add(this->spriteImage);
  this->Add(this->speciesNameTextBlock);
  this->Add(this->ivTextBlock);
  this->Add(this->titleTextBlock);
  this->Add(this->shinyInfoTextBlock);
  this->Add(this->moveTextBlock);
  this->Add(this->natureTextBlock);
}