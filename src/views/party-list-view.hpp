#pragma once

#include "../components/button.hpp"
#include "../utils/general.hpp"
#include "pokemon-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <functional>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

typedef std::function<std::shared_ptr<csight::Pkx>(size_t slot)> ReadPartyPokemonFn;

class PartyListView : public tsl::Gui {
 public:
  PartyListView(ReadPartyPokemonFn read_party_slot) : m_read_party_slot(read_party_slot) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Party Pokemon", " ");
    auto list = new tsl::elm::List();

    for (int party_pokemon = 0; party_pokemon < 6; party_pokemon++) {
      auto current_pokemon = this->m_read_party_slot(party_pokemon);
      if (current_pokemon->SpeciesString() != "None") {
        list->addItem(
            new PokemonViewButton(current_pokemon->SpeciesString() + (current_pokemon->IsShiny() ? " ★" : " "), current_pokemon));
      }
    }

    frame->setContent(list);

    return frame;
  }

 private:
  ReadPartyPokemonFn m_read_party_slot;
};

class PartyListViewButton : public Button {
 public:
  PartyListViewButton(ReadPartyPokemonFn read_party_slot) : Button("Party") {
    this->onClick([read_party_slot]() { tsl::changeTo<PartyListView>(read_party_slot); });
  }
};
