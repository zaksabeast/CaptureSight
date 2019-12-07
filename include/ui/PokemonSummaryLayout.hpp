#pragma once

#include <pu/Plutonium>
#include <utils/PK8.hpp>

class PokemonSummaryLayout : public pu::ui::Layout {
 public:
  PU_SMART_CTOR(PokemonSummaryLayout)

  void UpdateValues(std::string title, PK8* pkm);

 private:
  pu::ui::elm::TextBlock::Ref titleTextBlock;
  pu::ui::elm::TextBlock::Ref speciesNameTextBlock;
  pu::ui::elm::TextBlock::Ref ivTextBlock;
  pu::ui::elm::TextBlock::Ref shinyInfoTextBlock;
  pu::ui::elm::TextBlock::Ref moveTextBlock;
  pu::ui::elm::TextBlock::Ref ecTextBlock;
  pu::ui::elm::Image::Ref spriteImage;
  pu::ui::elm::Rectangle::Ref speciesBackgroundRectangle;
};