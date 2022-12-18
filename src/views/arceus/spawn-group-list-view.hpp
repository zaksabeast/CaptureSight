#pragma once

#include "../../components/button.hpp"
#include "./spawn-group-view.hpp"
#include <algorithm>
#include <csight-core.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class SpawnGroupListView : public tsl::Gui {
 public:
  SpawnGroupListView(bool active_groups) {
    if (active_groups) {
      m_count = csight::arceus_read_active_spawn_group_count();
    } else {
      m_count = csight::arceus_read_spawn_group_count();
    }
  }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Spawner Groups", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Spawner Group list"));

    for (size_t i = 0; i < m_count; i++) {
      std::string label = "Group " + std::to_string(i);
      list->addItem(new SpawnGroupViewButton(label, i));
    }

    frame->setContent(list);

    return frame;
  }

 private:
  size_t m_count;
};

class SpawnGroupListViewButton : public Button {
 public:
  SpawnGroupListViewButton(std::string button_label, bool active_groups) : Button(button_label) {
    this->onClick([active_groups]() { tsl::changeTo<SpawnGroupListView>(active_groups); });
  }
};
