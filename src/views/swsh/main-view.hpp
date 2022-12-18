#pragma once

#include "../party-list-view.hpp"
#include "../rng-view.hpp"
#include "../trainer-view.hpp"
#include "./den-list-view.hpp"
#include "./wild-trade-raid-view.hpp"
#include <csight-core.h>
#include <cstring>
#include <iomanip>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class MainSwShView : public tsl::Gui {
 public:
  MainSwShView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("CaptureSight", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    list->addItem(new WildTradeRaidViewButton());
    list->addItem(new PartyListViewButton(csight::swsh::read_party_pokemon));

    list->addItem(new tsl::elm::CategoryHeader("Dens"));
    list->addItem(new AllVanillaDenListViewButton());
    list->addItem(new ActiveVanillaDenListViewButton());
    list->addItem(new AllIoADenListViewButton());
    list->addItem(new ActiveIoADenListViewButton());
    list->addItem(new AllCTDenListViewButton());
    list->addItem(new ActiveCTDenListViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    list->addItem(new RngViewButton("Main RNG", csight::swsh::get_main_rng_tracker));

    list->addItem(new tsl::elm::CategoryHeader("Trainer Info"));
    auto trainer_info = csight::swsh::read_trainer_info();
    list->addItem(new TrainerViewButton(trainer_info));

    frame->setContent(list);

    return frame;
  }
};
