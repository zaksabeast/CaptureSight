#pragma once

#include "../components/button.hpp"
#include "../debug.hpp"
#include "../utils.hpp"
#include "pokemon-view.hpp"
#include <array>
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

class PartyListView : public tsl::Gui {
 public:
  PartyListView(std::array<u64, 6> party_offsets) : m_party_offsets(party_offsets) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Party Pokemon", " ");
    auto list = new tsl::elm::List();

    list->addItem(new PokemonViewButton("Party 1", m_party_offsets[0]));
    list->addItem(new PokemonViewButton("Party 2", m_party_offsets[1]));
    list->addItem(new PokemonViewButton("Party 3", m_party_offsets[2]));
    list->addItem(new PokemonViewButton("Party 4", m_party_offsets[3]));
    list->addItem(new PokemonViewButton("Party 5", m_party_offsets[4]));
    list->addItem(new PokemonViewButton("Party 6", m_party_offsets[5]));

    frame->setContent(list);

    return frame;
  }

 private:
  std::array<u64, 6> m_party_offsets;
};

class PartyListViewButton : public Button {
 public:
  PartyListViewButton(std::array<u64, 6> party_offsets) : Button("Party") {
    this->onClick([party_offsets]() { tsl::changeTo<PartyListView>(party_offsets); });
  }
};
