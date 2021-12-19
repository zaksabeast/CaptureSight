#pragma once

#include "../../components/button.hpp"
#include "../../constants.hpp"
#include "../../utils/general.hpp"
#include "../pokemon-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class RaidSeedButton : public Button {
 public:
  RaidSeedButton(std::string label, u64 offset) : Button(label) {
    this->onClick([this, offset]() {
      auto pk8 = utils::read_pkx(dbg::GetHeapAddress(offset));
      auto raid_seed = pk8->FindRaidSeed();
      std::string new_label = raid_seed.has_value() ? utils::num_to_hex(raid_seed.value()) : "None";
      this->setText(utils::num_to_hex(new_label));
    });
  }
};

class WildTradeRaidView : public tsl::Gui {
 public:
  WildTradeRaidView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Wild/Trade/Raid Pokemon", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Pokemon"));
    list->addItem(new PokemonViewButton("Wild", swsh::Pk8Offset::Wild));
    list->addItem(new PokemonViewButton("Wild Legend", swsh::Pk8Offset::WildLegend));
    list->addItem(new PokemonViewButton("Trade", swsh::Pk8Offset::Trade));
    list->addItem(new PokemonViewButton("Raid", swsh::Pk8Offset::Raid));

    list->addItem(new tsl::elm::CategoryHeader("Raid seed"));
    list->addItem(new RaidSeedButton("Raid Pokemon", swsh::Pk8Offset::Raid));
    list->addItem(new RaidSeedButton("Trade Pokemon", swsh::Pk8Offset::Trade));

    frame->setContent(list);

    return frame;
  }
};

class WildTradeRaidViewButton : public Button {
 public:
  WildTradeRaidViewButton() : Button("Wild/Trade/Raid") { this->onClick(tsl::changeTo<WildTradeRaidView>); }
};
