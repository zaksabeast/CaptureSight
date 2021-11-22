#pragma once

#include "../../constants.hpp"
#include "../../utils/bdsp.hpp"
#include "../party-list-view.hpp"
#include "../pokemon-view.hpp"
#include "../rng-view.hpp"
#include "./daycare-view.hpp"
#include <csight-core.h>
#include <cstring>
#include <iomanip>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class MainBdSpView : public tsl::Gui {
 public:
  MainBdSpView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("CaptureSight", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    list->addItem(new PokemonViewButton("Wild", bdsp::utils::read_wild_pokemon));
    list->addItem(new PartyListViewButton(bdsp::utils::read_party_pokemon));
    list->addItem(new DaycareViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));

    auto rng_address = dbg::ReadCheatProcessNso<u64>(bdsp::RngOffset::MainPtr);
    list->addItem(new XorshiftRngViewButton("Main RNG", rng_address));

    frame->setContent(list);

    return frame;
  }
};
