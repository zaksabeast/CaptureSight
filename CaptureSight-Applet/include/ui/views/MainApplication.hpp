#pragma once

#include <borealis.hpp>
#include <csight/core>
#include <memory>

namespace ui {
  class MainView : public brls::TabFrame {
   public:
    MainView();
    virtual ~MainView();

   private:
    brls::List *m_partyPokemonList;
    brls::List *m_miscPokemonList;
    brls::List *m_boxPokemonList;
    brls::List *m_activeDenList;
    brls::List *m_allDenList;
    brls::List *m_raidSearchSettingsList;
    brls::SelectListItem *m_flawlessIVFilter;
    brls::SelectListItem *m_abilityFilter;

    void OnClickShinyRaidFilter(size_t selection);
    void OnClickFlawlessIVRaidFilter(size_t selection);
    void OnClickAbilityRaidFilter(size_t selection);
  };
}