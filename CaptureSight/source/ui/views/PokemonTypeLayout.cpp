#include <csight/core>
#include <functional>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSprite.hpp>
#include <ui/elements/RoundedRectangle.hpp>
#include <ui/views/PokemonTypeLayout.hpp>
#include <utils/Constants.hpp>
#include <utils/I18N.hpp>
#include <utils/Settings.hpp>

extern MainApplication::Ref mainApp;
extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

void PokemonTypeLayout::SetTypeMatchUps(std::vector<csight::type::TypeMultiplier> matchUps) {
  this->Clear();

  u32 baseX = 50;
  u32 baseY = 50;
  u32 matchUpY = baseY + 25;
  u32 matchUpX = baseX + 25;
  auto theme = gsets.GetTheme();
  auto resistanceMatchUpStart
      = std::find_if(matchUps.begin(), matchUps.end(), [](auto typeMatchUp) { return typeMatchUp.multiplier < 1; });
  std::vector<csight::type::TypeMultiplier> weaknessMatchUp(matchUps.begin(), resistanceMatchUpStart);
  std::vector<csight::type::TypeMultiplier> resistanceMatchUp(resistanceMatchUpStart, matchUps.end());
  auto background = RoundedRectangle::New(baseX, baseY, 550, 600, theme.background.light, 5);

  this->Add(background);
  this->AddMatchUpText(weaknessMatchUp, i18n->Translate("Weakness"), matchUpX, matchUpY);
  this->AddMatchUpText(resistanceMatchUp, i18n->Translate("Resistance"), matchUpX + 250, matchUpY);
}

void PokemonTypeLayout::AddMatchUpText(std::vector<csight::type::TypeMultiplier> matchUps, std::string matchUpName, u32 x,
                                       u32 y) {
  auto matchUpYOffset = y + 60;
  auto theme = gsets.GetTheme();
  auto matchUpNameTextBlock = pu::ui::elm::TextBlock::New(x, y, matchUpName, 30);
  matchUpNameTextBlock->SetColor(theme.text.light);

  this->Add(matchUpNameTextBlock);

  for (u32 i = 0; i < matchUps.size(); i++) {
    auto matchUp = matchUps[i];
    auto typeNameTranslationKey = csight::utils::getTypeName(matchUp.type);
    auto typeName = i18n->Translate("types", typeNameTranslationKey);
    auto matchUpText = typeName + " " + csight::utils::convertFloatWithPrecision(matchUp.multiplier, 2);
    u32 matchUpY = matchUpYOffset + (i * 40);
    auto matchUpTextBlock = pu::ui::elm::TextBlock::New(x, matchUpY, matchUpText, 20);
    matchUpTextBlock->SetColor(theme.text.light);
    this->Add(matchUpTextBlock);
  }
}