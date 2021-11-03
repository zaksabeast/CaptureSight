#pragma once

#include "../../constants.hpp"
#include "../../views/party-list-view.hpp"
#include "../../views/swsh/den-list-view.hpp"
#include "../../views/swsh/rng-view.hpp"
#include "../../views/swsh/wild-trade-raid-view.hpp"
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
    list->addItem(new PartyListViewButton({
        swsh::Pk8Offset::Party + (0 * 0x158),
        swsh::Pk8Offset::Party + (1 * 0x158),
        swsh::Pk8Offset::Party + (2 * 0x158),
        swsh::Pk8Offset::Party + (3 * 0x158),
        swsh::Pk8Offset::Party + (4 * 0x158),
        swsh::Pk8Offset::Party + (5 * 0x158),
    }));

    list->addItem(new tsl::elm::CategoryHeader("Dens"));
    list->addItem(new AllVanillaDenListViewButton());
    list->addItem(new ActiveVanillaDenListViewButton());
    list->addItem(new AllIoADenListViewButton());
    list->addItem(new ActiveIoADenListViewButton());
    list->addItem(new AllCTDenListViewButton());
    list->addItem(new ActiveCTDenListViewButton());

    list->addItem(new tsl::elm::CategoryHeader("RNG"));
    list->addItem(new RngViewButton("Main RNG", swsh::RngOffset::Main));

    frame->setContent(list);

    return frame;
  }
};
