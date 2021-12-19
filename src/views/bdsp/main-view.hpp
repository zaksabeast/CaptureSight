#pragma once

#include "../../constants.hpp"
#include "../../utils/bdsp.hpp"
#include "../party-list-view.hpp"
#include "../pokemon-view.hpp"
#include "../rng-view.hpp"
#include "../trainer-view.hpp"
#include "./daycare-view.hpp"
#include "./roamer-view.hpp"
#include "./underground-view.hpp"
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
    list->addItem(new UndergroundViewButton());
    list->addItem(new PokemonViewButton("Union Trade", bdsp::utils::read_other_player_union_trade_pokemon));
    list->addItem(new RoamerListViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    auto main_rng_addr = dbg::ReadCheatProcessNso<u64>(bdsp::RngOffset::MainPtr);
    list->addItem(new XorshiftRngViewButton("Main RNG", main_rng_addr));
    auto rand_group_0_addr = bdsp::utils::get_random_group_state_addr(0);
    list->addItem(new LcrngViewButton("Random Group 0", rand_group_0_addr));
    auto rand_group_1_addr = bdsp::utils::get_random_group_state_addr(1);
    list->addItem(new LcrngViewButton("Random Group 1", rand_group_1_addr));

    list->addItem(new tsl::elm::CategoryHeader("Trainer Info"));
    auto trainer_info = bdsp::utils::read_trainer_info();
    list->addItem(new TrainerViewButton(trainer_info));

    frame->setContent(list);

    return frame;
  }
};
