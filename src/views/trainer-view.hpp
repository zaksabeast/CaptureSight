#pragma once

#include "../components/button.hpp"
#include "../utils/debug.hpp"
#include <memory>
#include <tesla.hpp>

class TrainerView : public tsl::Gui {
 public:
  TrainerView(std::shared_ptr<csight::TrainerInfo> trainer_info) : m_trainer_info(trainer_info) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Trainer Info", " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("TID"));
    list->addItem(new tsl::elm::ListItem(std::to_string(m_trainer_info->tid)));

    list->addItem(new tsl::elm::CategoryHeader("SID"));
    list->addItem(new tsl::elm::ListItem(std::to_string(m_trainer_info->sid)));

    frame->setContent(list);

    return frame;
  }

 private:
  std::shared_ptr<csight::TrainerInfo> m_trainer_info;
};

class TrainerViewButton : public Button {
 public:
  TrainerViewButton(std::shared_ptr<csight::TrainerInfo> trainer_info) : Button("Trainer Info") {
    this->onClick([trainer_info]() { tsl::changeTo<TrainerView>(trainer_info); });
  }
};
