#pragma once

#include "../../components/button.hpp"
#include "../../utils/general.hpp"
#include "../pokemon-view.hpp"
#include "../party-list-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <functional>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

typedef std::function<std::shared_ptr<csight::Pkx>(size_t slot)> ReadPartyPokemonFn;

class EncounterListView : public tsl::Gui {
 public:
  EncounterListView(ReadPartyPokemonFn read_party_slot) : m_read_party_slot(read_party_slot) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Enconter", " ");
    auto list = new tsl::elm::List();

    for (int wild_pokemon = 0; wild_pokemon < 6;wild_pokemon++){ // tried to implement gathering of wild party count through offsets but got tired
      auto current_pokemon = this->m_read_party_slot(wild_pokemon);
      if (current_pokemon->SpeciesString() != "None") {
        list->addItem(new PokemonViewButton(current_pokemon->SpeciesString()+ (current_pokemon->IsShiny() ? " ★" : " "), current_pokemon));
      }
    }

    frame->setContent(list);

    return frame;
  }

 private:
  ReadPartyPokemonFn m_read_party_slot;
};

class EncounterListViewButton : public Button {
 public:
  EncounterListViewButton(ReadPartyPokemonFn read_party_slot) : Button("Encounter") {
    this->onClick([read_party_slot]() { tsl::changeTo<EncounterListView>(read_party_slot); });
  }
};