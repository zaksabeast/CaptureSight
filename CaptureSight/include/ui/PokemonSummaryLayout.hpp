#pragma once

#include <pu/Plutonium>
#include <utils/PK8.hpp>

class PokemonSummaryLayout : public pu::ui::Layout {
 public:
  PokemonSummaryLayout();
  PU_SMART_CTOR(PokemonSummaryLayout)

  void UpdateValues(std::string title, std::shared_ptr<PK8> pkm, bool isShowingExtraDetail);

 private:
  pu::ui::elm::TextBlock::Ref titleTextBlock;
  pu::ui::elm::TextBlock::Ref speciesNameTextBlock;
  pu::ui::elm::TextBlock::Ref ivTextBlock;
  pu::ui::elm::TextBlock::Ref evTextBlock;
  pu::ui::elm::TextBlock::Ref shinyInfoTextBlock;
  pu::ui::elm::TextBlock::Ref moveTextBlock;
  pu::ui::elm::TextBlock::Ref natureTextBlock;
  pu::ui::elm::TextBlock::Ref mintedNatureTextBlock;
  pu::ui::elm::TextBlock::Ref abilityTextBlock;
  pu::ui::elm::TextBlock::Ref pidEcTextBlock;
  pu::ui::elm::TextBlock::Ref instructionsTextBlock;
  pu::ui::elm::TextBlock::Ref friendshipTextBlock;
  pu::ui::elm::Image::Ref spriteImage;
  pu::ui::elm::Rectangle::Ref speciesBackgroundRectangle;
};