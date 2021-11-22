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

    list->addItem(new PokemonViewButton("Party 1", [this]() { return this->m_read_party_slot(0); }));
    list->addItem(new PokemonViewButton("Party 2", [this]() { return this->m_read_party_slot(1); }));
    list->addItem(new PokemonViewButton("Party 3", [this]() { return this->m_read_party_slot(2); }));
    list->addItem(new PokemonViewButton("Party 4", [this]() { return this->m_read_party_slot(3); }));
    list->addItem(new PokemonViewButton("Party 5", [this]() { return this->m_read_party_slot(4); }));
    list->addItem(new PokemonViewButton("Party 6", [this]() { return this->m_read_party_slot(5); }));

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
