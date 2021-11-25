#pragma once

#include "../components/button.hpp"
#include "../utils/debug.hpp"
#include "../utils/general.hpp"
#include "./detachable-view.hpp"
#include <csight-core.h>
#include <memory>
#include <tesla.hpp>
#include <vector>

template <class Rng>
class RngView : public DetachableView {
 public:
  RngView(std::string title, u64 rng_address) : DetachableView(title), m_title(title), m_rng_address(rng_address) {
    auto rng_state = this->readRngState();
    m_rng = std::make_shared<Rng>(rng_state);
    m_list_items.reserve(Rng::StateCount);
  };
  ~RngView() {};

  virtual void setupList(tsl::elm::List *list) {
    m_state_header = new tsl::elm::CategoryHeader(this->getStateHeaderLabel());
    list->addItem(m_state_header);

    for (u32 i = 0; i < Rng::StateCount; i++) {
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

  typename Rng::State readRngState() {
    return dbg::ReadCheatProcessArray<typename Rng::StateItem, Rng::StateCount>(m_rng_address);
  }

  virtual void update() override {
    m_state_header->setText(this->getStateHeaderLabel());

    auto rng_state = this->readRngState();
    m_advances += m_rng->AdvanceToState(rng_state);

    if (m_update_view) {
      for (u32 i = 0; i < Rng::StateCount; i++) {
        // The user can't control the view, so remove the highlight from list item
        m_list_items[i]->setFocused(false);
        m_list_items[i]->setText(utils::num_to_hex(rng_state[i]));
      }

      m_advances_list_item->setText(std::to_string(m_advances));
    }
  }

 private:
  bool m_update_view = true;
  u64 m_advances = 0;
  std::string m_title;
  u64 m_rng_address;
  tsl::elm::CategoryHeader *m_state_header;
  std::vector<tsl::elm::ListItem *> m_list_items;
  tsl::elm::ListItem *m_advances_list_item;
  std::shared_ptr<Rng> m_rng;

  std::string getStateHeaderLabel() {
    if (m_update_view) {
      return "Current State (\uE0A0 A to pause updates)";
    }

    return "Current State (\uE0A0 A to unpause updates)";
  }
};

class XoroshiroRngViewButton : public Button {
 public:
  XoroshiroRngViewButton(const std::string title, u64 rng_offset) : Button(title) {
    this->onClick([title, rng_offset]() { tsl::changeTo<RngView<csight::Xoroshiro>>(title, rng_offset); });
  }
};

class XorshiftRngViewButton : public Button {
 public:
  XorshiftRngViewButton(const std::string title, u64 rng_offset) : Button(title) {
    this->onClick([title, rng_offset]() { tsl::changeTo<RngView<csight::Xorshift>>(title, rng_offset); });
  }
};

class LcrngViewButton : public Button {
 public:
  LcrngViewButton(const std::string title, u64 rng_offset) : Button(title) {
    this->onClick([title, rng_offset]() { tsl::changeTo<RngView<csight::Lcrng>>(title, rng_offset); });
  }
};
