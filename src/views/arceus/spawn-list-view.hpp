#pragma once

#include "../../components/button.hpp"
#include "../../constants.hpp"
#include "./spawn-view.hpp"
#include <algorithm>
#include <csight-core.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class SpawnListView : public tsl::Gui {
 public:
  SpawnListView() { m_count = csight::arceus::arceus_read_spawn_count(); }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Active Spawns", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Spawn list"));

    size_t step = 100;
    for (size_t i = 0; i < m_count; i += step) {
      size_t end_count = i + std::min(m_count - i, step);
      std::string label = "Spawns " + std::to_string(i) + " - " + std::to_string(end_count);
      list->addItem(new SpawnViewButton(label, i, i + step));
    }

    frame->setContent(list);

    return frame;
  }

 private:
  size_t m_count;
};

class SpawnListViewButton : public Button {
 public:
  SpawnListViewButton() : Button("Active Spawns") {
    this->onClick([]() { tsl::changeTo<SpawnListView>(); });
  }
};
