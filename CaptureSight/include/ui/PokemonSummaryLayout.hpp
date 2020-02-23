#pragma once

#include <pu/Plutonium>
#include <csight/core>
#include <ui/elements/Polygon.hpp>
#include <ui/elements/RoundedRectangle.hpp>

namespace statType {
  enum StatType { ivs, evs };
};

class PokemonSummaryLayout : public pu::ui::Layout {
 public:
  PokemonSummaryLayout();
  PU_SMART_CTOR(PokemonSummaryLayout)

  void UpdateValues(std::string title, std::shared_ptr<csight::PK8> pkm, bool isShowingExtraDetail);
  statType::StatType GetStatType();
  void SetStatType(statType::StatType _statType);

 private:
  statType::StatType statType = statType::ivs;
  RoundedRectangle::Ref instructionLabelBackground;
  pu::ui::elm::TextBlock::Ref instructionsTextBlock;
  RoundedRectangle::Ref statLabelBackground;
  pu::ui::elm::TextBlock::Ref statTextBlock;
  pu::ui::elm::TextBlock::Ref titleTextBlock;
  pu::ui::elm::TextBlock::Ref speciesNameTextBlock;
  pu::ui::elm::TextBlock::Ref hpStatTextBlock;
  pu::ui::elm::TextBlock::Ref atkStatTextBlock;
  pu::ui::elm::TextBlock::Ref defStatTextBlock;
  pu::ui::elm::TextBlock::Ref spaStatTextBlock;
  pu::ui::elm::TextBlock::Ref spdStatTextBlock;
  pu::ui::elm::TextBlock::Ref speStatTextBlock;
  pu::ui::elm::TextBlock::Ref shinyInfoTextBlock;
  RoundedRectangle::Ref moveTableBackground;
  pu::ui::elm::TextBlock::Ref move1TextBlock;
  pu::ui::elm::TextBlock::Ref move2TextBlock;
  pu::ui::elm::TextBlock::Ref move3TextBlock;
  pu::ui::elm::TextBlock::Ref move4TextBlock;
  RoundedRectangle::Ref mainInfoTableBackground;
  pu::ui::elm::TextBlock::Ref natureTextBlock;
  pu::ui::elm::TextBlock::Ref mintedNatureTextBlock;
  pu::ui::elm::TextBlock::Ref abilityTextBlock;
  RoundedRectangle::Ref extraInfoTableBackground;
  pu::ui::elm::TextBlock::Ref pidEcTextBlock;
  pu::ui::elm::TextBlock::Ref friendshipTextBlock;
  pu::ui::elm::Image::Ref spriteImage;
  pu::ui::elm::Rectangle::Ref headerBackground;
  Polygon::Ref outerStatPolygon;
  Polygon::Ref innerStatPolygon;
};