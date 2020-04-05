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
  auto secondMatchUpStart
      = std::find_if(matchUps.begin(), matchUps.end(), [](auto typeMatchUp) { return typeMatchUp.multiplier < 1; });
  std::vector<csight::type::TypeMultiplier> firstMatchUp(matchUps.begin(), secondMatchUpStart);
  std::vector<csight::type::TypeMultiplier> secondMatchUp(secondMatchUpStart, matchUps.end());
  auto background = RoundedRectangle::New(baseX, baseY, 550, 600, theme.background.light, 5);

  this->Add(background);
  this->AddMatchUpText(firstMatchUp, "Weakness", matchUpX, matchUpY);
  this->AddMatchUpText(secondMatchUp, "Resistance", matchUpX + 250, matchUpY);
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
    auto typeName = csight::utils::getTypeName(matchUp.type);
    auto matchUpText = typeName + " " + csight::utils::convertFloatWithPrecision(matchUp.multiplier, 2);
    u32 matchUpY = matchUpYOffset + (i * 40);
    auto matchUpTextBlock = pu::ui::elm::TextBlock::New(x, matchUpY, matchUpText, 20);
    matchUpTextBlock->SetColor(theme.text.light);
    this->Add(matchUpTextBlock);
  }
}