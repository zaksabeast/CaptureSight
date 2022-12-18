#pragma once

#include "../../components/button.hpp"
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
  RaidSeedButton(std::string label, utils::ReadPokemonFn read_pk8) : Button(label) {
    this->onClick([this, read_pk8]() {
      auto pk8 = read_pk8();
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
    list->addItem(new PokemonViewButton("Wild", csight::swsh::read_wild_pokemon));
    list->addItem(new PokemonViewButton("Wild Legend", csight::swsh::read_wild_legend_pokemon));
    list->addItem(new PokemonViewButton("Trade", csight::swsh::read_trade_pokemon));
    list->addItem(new PokemonViewButton("Raid", csight::swsh::read_raid_pokemon));

    list->addItem(new tsl::elm::CategoryHeader("Raid seed"));
    list->addItem(new RaidSeedButton("Raid Pokemon", csight::swsh::read_raid_pokemon));
    list->addItem(new RaidSeedButton("Trade Pokemon", csight::swsh::read_trade_pokemon));

    frame->setContent(list);

    return frame;
  }
};

class WildTradeRaidViewButton : public Button {
 public:
  WildTradeRaidViewButton() : Button("Wild/Trade/Raid") { this->onClick(tsl::changeTo<WildTradeRaidView>); }
};
