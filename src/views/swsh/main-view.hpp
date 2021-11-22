#pragma once

#include "../../constants.hpp"
#include "../../utils/swsh.hpp"
#include "../party-list-view.hpp"
#include "../rng-view.hpp"
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
    list->addItem(new PartyListViewButton(swsh::utils::read_party_pokemon));

    list->addItem(new tsl::elm::CategoryHeader("Dens"));
    list->addItem(new AllVanillaDenListViewButton());
    list->addItem(new ActiveVanillaDenListViewButton());
    list->addItem(new AllIoADenListViewButton());
    list->addItem(new ActiveIoADenListViewButton());
    list->addItem(new AllCTDenListViewButton());
    list->addItem(new ActiveCTDenListViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    auto rng_address = dbg::GetHeapAddress(swsh::RngOffset::Main);
    list->addItem(new XoroshiroRngViewButton("Main RNG", rng_address));

    frame->setContent(list);

    return frame;
  }
};
