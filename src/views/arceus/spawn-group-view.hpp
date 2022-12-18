#pragma once

#include "../../components/button.hpp"
#include "../../utils/general.hpp"
#include <algorithm>
#include <csight-core.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class SpawnGroupView : public tsl::Gui {
 public:
  SpawnGroupView(size_t index) : m_spawn_group(std::make_shared<csight::arceus::SpawnGroup>(index)) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Group " + std::to_string(m_spawn_group->Index()), " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Seed"));
    list->addItem(new tsl::elm::ListItem(utils::num_to_hex(m_spawn_group->Seed())));

    list->addItem(new tsl::elm::CategoryHeader("Spawner list"));

    u32 spawn_pair_index = 0;
    for (auto spawn_pair_seeds : m_spawn_group->SpawnPairsSeeds()) {
      std::string base_label = "P" + std::to_string(spawn_pair_index);

      u32 seed_index = 0;
      for (auto seed : spawn_pair_seeds) {
        std::string label_0 = base_label + "[" + std::to_string(seed_index) + "] " + utils::num_to_hex(seed);
        list->addItem(new tsl::elm::ListItem(label_0));

        seed_index++;
      }

      spawn_pair_index++;
    }

    frame->setContent(list);

    return frame;
  }

 private:
  std::shared_ptr<csight::arceus::SpawnGroup> m_spawn_group;
};

class SpawnGroupViewButton : public Button {
 public:
  SpawnGroupViewButton(std::string label, size_t index) : Button(label) {
    this->onClick([index]() { tsl::changeTo<SpawnGroupView>(index); });
  }
};
