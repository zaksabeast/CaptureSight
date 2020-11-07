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
    brls::List *m_dmaxAdventureList;

    void addTranslatedTab(std::string label, brls::View *view);
  };
}