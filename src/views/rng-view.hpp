#pragma once

#include "../components/button.hpp"
#include "../utils/debug.hpp"
#include "../utils/general.hpp"
#include "./detachable-view.hpp"
#include <csight-core.h>
#include <memory>
#include <tesla.hpp>
#include <vector>

class RngView : public DetachableView {
 public:
  RngView(std::string title, std::shared_ptr<csight::RngTracker> rng_tracker) :
      DetachableView(title), m_title(title), m_rng_tracker(rng_tracker) {
    m_list_items.reserve(m_rng_tracker->GetStateCount());
  };
  ~RngView() {};

  virtual void setupList(tsl::elm::List *list) {
    m_state_header = new tsl::elm::CategoryHeader(this->getStateHeaderLabel());
    list->addItem(m_state_header);

    for (u32 i = 0; i < m_rng_tracker->GetStateCount(); i++) {
      auto state_item = new tsl::elm::ListItem("0");
      m_list_items.push_back(state_item);
      list->addItem(state_item);
    }

    list->addItem(new tsl::elm::CategoryHeader("Advances"));
    m_advances_list_item = new tsl::elm::ListItem("0");
    list->addItem(m_advances_list_item);
  }

  virtual void handleInputIfAttached(u64 keysDown, u64 keysHeld, const HidTouchState &touchPos, HidAnalogStickState leftJoyStick,
                                     HidAnalogStickState rightJoyStick) {
    if (keysDown & HidNpadButton_A) {
      m_update_view = !m_update_view;
    }
  }

  std::string formatState(u64 state) {
    switch (m_rng_tracker->GetStateItemSize()) {
      case sizeof(u32):
        return utils::num_to_hex((u32)state);
      default:
        return utils::num_to_hex(state);
    }
  }

  virtual void update() override {
    m_state_header->setText(this->getStateHeaderLabel());

    auto rng_state = m_rng_tracker->ReadState();
    m_advances += m_rng_tracker->GetAdvances();

    if (m_update_view) {
      for (u32 i = 0; i < m_rng_tracker->GetStateCount(); i++) {
        // The user can't control the view, so remove the highlight from list item
        m_list_items[i]->setFocused(false);
        m_list_items[i]->setText(formatState(rng_state[i]));
      }

      m_advances_list_item->setText(std::to_string(m_advances));
    }
  }

 private:
  std::string m_title;
  bool m_update_view = true;
  u64 m_advances = 0;
  tsl::elm::CategoryHeader *m_state_header;
  std::vector<tsl::elm::ListItem *> m_list_items;
  tsl::elm::ListItem *m_advances_list_item;
  std::shared_ptr<csight::RngTracker> m_rng_tracker;

  std::string getStateHeaderLabel() {
    if (m_update_view) {
      return "Current State (\uE0A0 A to pause updates)";
    }

    return "Current State (\uE0A0 A to unpause updates)";
  }
};

typedef std::function<std::shared_ptr<csight::RngTracker>(void)> GetRngTracker;

class RngViewButton : public Button {
 public:
  RngViewButton(const std::string title, GetRngTracker get_rng_tracker) : Button(title) {
    this->onClick([title, get_rng_tracker]() { tsl::changeTo<RngView>(title, get_rng_tracker()); });
  }
};
