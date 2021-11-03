#pragma once

#include "../../components/button.hpp"
#include "../../debug.hpp"
#include "../../utils.hpp"
#include <csight-core.h>
#include <memory>
#include <tesla.hpp>
#include <vector>

class RngView : public tsl::Gui {
 public:
  RngView(std::string title, u64 rng_offset) : m_title(title), m_rng_offset(rng_offset) {
    auto rng_state = this->read_rng_state();
    m_rng = std::make_shared<csight::Xoroshiro>(rng_state[0], rng_state[1]);
  };
  ~RngView() {};

  virtual tsl::elm::Element *createUI() {
    auto frame = new tsl::elm::OverlayFrame(m_title, " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("States"));
    m_state0_list_item = new tsl::elm::ListItem("State 0");
    list->addItem(m_state0_list_item);
    m_state1_list_item = new tsl::elm::ListItem("State 1");
    list->addItem(m_state1_list_item);

    list->addItem(new tsl::elm::CategoryHeader("Advances"));
    m_advances_list_item = new tsl::elm::ListItem("0");
    list->addItem(m_advances_list_item);

    frame->setContent(list);
    return frame;
  }

  std::array<u64, 2> read_rng_state() {
    auto rng_state = dbg::ReadCheatProcessHeap<16>(m_rng_offset);
    u64 *rng_state_ptr = (u64 *)rng_state.data();

    return { rng_state_ptr[0], rng_state_ptr[1] };
  }

  virtual void update() override {
    auto rng_state = this->read_rng_state();
    m_state0_list_item->setText(utils::num_to_hex(rng_state[0]));
    m_state1_list_item->setText(utils::num_to_hex(rng_state[1]));

    m_advances += m_rng->AdvanceToState(rng_state[0], rng_state[1]);
    m_advances_list_item->setText(std::to_string(m_advances));
  }

 private:
  u64 m_advances = 0;
  std::string m_title;
  u64 m_rng_offset;
  tsl::elm::ListItem *m_state0_list_item;
  tsl::elm::ListItem *m_state1_list_item;
  tsl::elm::ListItem *m_advances_list_item;
  std::shared_ptr<csight::Xoroshiro> m_rng;
};

class RngViewButton : public Button {
 public:
  RngViewButton(const std::string title, u64 rng_offset) : Button(title) {
    this->onClick([title, rng_offset]() { tsl::changeTo<RngView>(title, rng_offset); });
  }
};
