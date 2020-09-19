#pragma once

#include <borealis.hpp>
#include <csight/core>
#include <memory>

namespace ui {
  class PokemonSummaryView : public brls::TabFrame {
   public:
    PokemonSummaryView(std::shared_ptr<csight::pkm::PK8> pkm);
    virtual ~PokemonSummaryView();

   private:
    brls::List *m_raidSeedView;
    brls::Table *m_miscTable;
    brls::Table *m_ivTable;
    brls::Table *m_evTable;
    brls::Table *m_moveTable;
    brls::Table *m_weaknessTable;

    void onClickFindRaidSeed(std::shared_ptr<csight::pkm::PK8> pkm, brls::View *view);
    void addTranslatedTab(std::string label, brls::View *view);
  };
}