#pragma once

#include "../../utils/general.hpp"
#include "../party-list-view.hpp"
#include "../rng-view.hpp"
#include "./spawn-group-list-view.hpp"
#include "./wild-list-view.hpp"
#include <csight-core.h>
#include <tesla.hpp>

class MainArceusView : public tsl::Gui {
 public:
  MainArceusView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("CaptureSight", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    list->addItem(new WildListViewButton());
    list->addItem(new PartyListViewButton(csight::arceus::read_party_pokemon));
    list->addItem(new SpawnGroupListViewButton("Active spawners", true));
    list->addItem(new SpawnGroupListViewButton("All spawners", false));

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    list->addItem(new RngViewButton("Main RNG", csight::arceus::get_main_rng_tracker));

    frame->setContent(list);

    return frame;
  }
};
