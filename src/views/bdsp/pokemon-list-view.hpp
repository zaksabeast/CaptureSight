#pragma once

#include "../../components/button.hpp"
#include "../../utils/general.hpp"
#include "../party-list-view.hpp"
#include "../pokemon-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <functional>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

typedef std::function<std::shared_ptr<csight::Pkx>(size_t index)> ReadPokemonByIndex;

class PokemonListView : public tsl::Gui {
 public:
  PokemonListView(std::string label, ReadPokemonByIndex read_pokemon_by_index, u32 count) :
      m_label(label), m_read_pokemon_by_index(read_pokemon_by_index), m_count(count) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame(m_label, " ");
    auto list = new tsl::elm::List();

    for (u32 index = 0; index < m_count; index++) {
      auto current_pokemon = this->m_read_pokemon_by_index(index);
      list->addItem(
          new PokemonViewButton(current_pokemon->SpeciesString() + (current_pokemon->IsShiny() ? " ★" : " "), current_pokemon));
    }

    frame->setContent(list);

    return frame;
  }

 private:
  std::string m_label;
  ReadPartyPokemonFn m_read_pokemon_by_index;
  u32 m_count;
};

class PokemonListViewButton : public Button {
 public:
  PokemonListViewButton(std::string label, ReadPokemonByIndex read_pokemon_by_index, u32 count) : Button(label) {
    this->onClick(
        [label, read_pokemon_by_index, count]() { tsl::changeTo<PokemonListView>(label, read_pokemon_by_index, count); });
  }
};
