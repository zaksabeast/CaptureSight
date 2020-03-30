#pragma once

#include <csight/core>
#include <pu/Plutonium>
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
  void Tick();
  statType::StatType GetStatType();
  void SetStatType(statType::StatType _statType);

 private:
  statType::StatType m_statType = statType::ivs;
  int m_raidSearchCount = 0;
  RoundedRectangle::Ref m_instructionLabelBackground;
  pu::ui::elm::TextBlock::Ref m_instructionsTextBlock;
  RoundedRectangle::Ref m_statLabelBackground;
  pu::ui::elm::TextBlock::Ref m_statTextBlock;
  pu::ui::elm::TextBlock::Ref m_titleTextBlock;
  pu::ui::elm::TextBlock::Ref m_speciesNameTextBlock;
  pu::ui::elm::TextBlock::Ref m_hpStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_atkStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_defStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_spaStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_spdStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_speStatTextBlock;
  pu::ui::elm::TextBlock::Ref m_shinyInfoTextBlock;
  RoundedRectangle::Ref m_moveTableBackground;
  pu::ui::elm::TextBlock::Ref m_move1TextBlock;
  pu::ui::elm::TextBlock::Ref m_move2TextBlock;
  pu::ui::elm::TextBlock::Ref m_move3TextBlock;
  pu::ui::elm::TextBlock::Ref m_move4TextBlock;
  RoundedRectangle::Ref m_mainInfoTableBackground;
  pu::ui::elm::TextBlock::Ref m_natureTextBlock;
  pu::ui::elm::TextBlock::Ref m_mintedNatureTextBlock;
  pu::ui::elm::TextBlock::Ref m_abilityTextBlock;
  RoundedRectangle::Ref m_extraInfoTableBackground;
  pu::ui::elm::TextBlock::Ref m_pidEcTextBlock;
  pu::ui::elm::TextBlock::Ref m_friendshipTextBlock;
  pu::ui::elm::Image::Ref m_spriteImage;
  pu::ui::elm::Rectangle::Ref m_headerBackground;
  Polygon::Ref m_outerStatPolygon;
  Polygon::Ref m_innerStatPolygon;
};