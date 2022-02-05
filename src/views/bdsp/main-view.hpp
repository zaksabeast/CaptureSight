#pragma once

#include "../../constants.hpp"
#include "../party-list-view.hpp"
#include "../pokemon-view.hpp"
#include "../rng-view.hpp"
#include "../trainer-view.hpp"
#include "./daycare-view.hpp"
#include "./roamer-view.hpp"
#include "./underground-view.hpp"
#include "./wild-list-view.hpp"
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
    list->addItem(new BdspWildListViewButton(csight::bdsp::read_wild_pokemon));
    list->addItem(new PartyListViewButton(csight::bdsp::read_party_pokemon));
    list->addItem(new DaycareViewButton());
    list->addItem(new UndergroundViewButton());
    list->addItem(new PokemonViewButton("Union Trade", csight::bdsp::read_other_player_union_trade_pokemon));
    list->addItem(new RoamerListViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    list->addItem(new RngViewButton("Main RNG", csight::bdsp::get_main_rng_tracker));
    list->addItem(new RngViewButton("Random Group 0", []() { return csight::bdsp::get_random_group_rng_tracker(0); }));
    list->addItem(new RngViewButton("Random Group 1", []() { return csight::bdsp::get_random_group_rng_tracker(1); }));

    list->addItem(new tsl::elm::CategoryHeader("Trainer Info"));
    auto trainer_info = csight::bdsp::read_trainer_info();
    list->addItem(new TrainerViewButton(trainer_info));

    frame->setContent(list);

    return frame;
  }
};
