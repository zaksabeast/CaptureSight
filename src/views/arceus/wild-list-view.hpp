#pragma once

#include "../../components/button.hpp"
#include "../../utils/general.hpp"
#include "../pokemon-view.hpp"
#include <csight-core.h>
#include <memory>
#include <switch.h>
#include <tesla.hpp>
#include <vector>

class WildListView : public tsl::Gui {
 public:
  WildListView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Wild List", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    auto wild_pokemon = csight::arceus::read_wild_pokemon();

    for (auto pkx : wild_pokemon) {
      list->addItem(new PokemonViewButton(pkx->SpeciesString(), pkx));
    }

    frame->setContent(list);

    return frame;
  }
};

class WildListViewButton : public Button {
 public:
  WildListViewButton() : Button("Wild List") { this->onClick(tsl::changeTo<WildListView>); }
};
