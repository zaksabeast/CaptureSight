#pragma once

#include "../../components/button.hpp"
#include "../../constants.hpp"
#include "../../utils/general.hpp"
#include <algorithm>
#include <csight-core.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class SpawnView : public tsl::Gui {
 public:
  SpawnView(size_t start_index, size_t end_index) { m_spawns = csight::arceus::readActiveSpawns(start_index, end_index); }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Active Spawns", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Spawn list"));

    for (auto spawn : m_spawns) {
      std::string label = "Idx " + std::to_string(spawn->Index()) + " " + utils::num_to_hex(spawn->Seed());
      auto spawn_item = new tsl::elm::ListItem(label);
      list->addItem(spawn_item);
    }

    frame->setContent(list);

    return frame;
  }

 private:
  std::vector<std::shared_ptr<csight::arceus::Spawn>> m_spawns;
};

class SpawnViewButton : public Button {
 public:
  SpawnViewButton(std::string label, size_t start_index, size_t end_index) : Button(label) {
    this->onClick([start_index, end_index]() { tsl::changeTo<SpawnView>(start_index, end_index); });
  }
};
