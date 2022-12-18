#pragma once

#include "../party-list-view.hpp"
#include "../rng-view.hpp"
#include <csight-core.h>
#include <cstring>
#include <iomanip>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class MainSvView : public tsl::Gui {
 public:
  MainSvView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("CaptureSight", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    list->addItem(new PartyListViewButton(csight::sv::read_party_pokemon));

    list->addItem(new tsl::elm::CategoryHeader("Raid seed"));
    auto top_level_raid_seed = csight::sv::read_top_level_raid_seed();
    m_seed_list_item = new tsl::elm::ListItem(utils::num_to_hex(top_level_raid_seed));
    list->addItem(m_seed_list_item);

    frame->setContent(list);

    return frame;
  }

  virtual void update() override {
    auto top_level_raid_seed = csight::sv::read_top_level_raid_seed();
    m_seed_list_item->setText(utils::num_to_hex(top_level_raid_seed));
  }

  tsl::elm::ListItem *m_seed_list_item;
};
