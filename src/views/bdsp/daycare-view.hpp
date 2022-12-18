#pragma once

#include "../../components/button.hpp"
#include "../detachable-view.hpp"
#include <csight-core.h>
#include <memory>
#include <string>
#include <tesla.hpp>

class DaycareView : public DetachableView {
 public:
  DaycareView() : DetachableView("Daycare View") { }

  virtual void setupList(tsl::elm::List *list) {
    list->addItem(new tsl::elm::CategoryHeader("Exists"));
    m_exits_item = new tsl::elm::ListItem("");
    list->addItem(m_exits_item);

    list->addItem(new tsl::elm::CategoryHeader("Seed"));
    m_seed_item = new tsl::elm::ListItem("");
    list->addItem(m_seed_item);

    list->addItem(new tsl::elm::CategoryHeader("Steps"));
    m_steps_item = new tsl::elm::ListItem("");
    list->addItem(m_steps_item);
  }

  virtual void update() {
    auto egg_details = csight::bdsp::read_egg_details();

    m_exits_item->setFocused(false);
    m_exits_item->setText(egg_details->exists ? "True" : "False");

    m_seed_item->setFocused(false);
    // Only the last 32 bits are used as the seed,
    // so that's all we'll show to the user
    m_seed_item->setText(utils::num_to_hex((u32)egg_details->seed));

    m_steps_item->setFocused(false);
    // Subtract from 180 so the numbers go backwards
    m_steps_item->setText(std::to_string(180 - egg_details->step_count));
  }

 private:
  tsl::elm::ListItem *m_exits_item;
  tsl::elm::ListItem *m_seed_item;
  tsl::elm::ListItem *m_steps_item;
  tsl::elm::OverlayFrame *m_frame;
};

class DaycareViewButton : public Button {
 public:
  DaycareViewButton() : Button("Daycare view") { this->onClick(tsl::changeTo<DaycareView>); }
};
