#pragma once

#include "../../components/button.hpp"
#include "../../constants.hpp"
#include "../../utils/debug.hpp"
#include "../../utils/swsh.hpp"
#include <tesla.hpp>

class TrainerView : public tsl::Gui {
 public:
  TrainerView() { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame("Trainer Info", " ");
    auto list = new tsl::elm::List();

    auto trainer_info = swsh::utils::read_trainer_info();

    list->addItem(new tsl::elm::CategoryHeader("TID"));
    list->addItem(new tsl::elm::ListItem(std::to_string(trainer_info->tid)));

    list->addItem(new tsl::elm::CategoryHeader("SID"));
    list->addItem(new tsl::elm::ListItem(std::to_string(trainer_info->sid)));

    frame->setContent(list);

    return frame;
  }
};

class TrainerViewButton : public Button {
 public:
  TrainerViewButton() : Button("Trainer Info") {
    this->onClick([]() { tsl::changeTo<TrainerView>(); });
  }
};
