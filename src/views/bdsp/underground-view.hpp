#pragma once

#include "../../components/button.hpp"
#include "../../utils/bdsp.hpp"
#include "../detachable-view.hpp"
#include "../pokemon-view.hpp"
#include <csight-core.h>
#include <memory>
#include <string>
#include <tesla.hpp>
#include <vector>

class UndergroundView : public tsl::Gui {
 public:
  UndergroundView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Underground", " ");
    auto list = new tsl::elm::List();

    // We always need at least one item in a list to prevent it from crashing
    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    auto pkxs = bdsp::utils::read_underground_pokemon();

    for (auto pkx : pkxs) {
      std::string label = pkx->SpeciesString() + (pkx->IsShiny() ? " ★" : " ");
      list->addItem(new PokemonViewButton(label, pkx));
    }

    frame->setContent(list);

    return frame;
  }
};

class UndergroundViewButton : public Button {
 public:
  UndergroundViewButton() : Button("Underground") { this->onClick(tsl::changeTo<UndergroundView>); }
};
