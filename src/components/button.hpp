#pragma once

#include <functional>
#include <switch.h>
#include <tesla.hpp>

class Button : public tsl::elm::ListItem {
 public:
  Button(const std::string &text) : ListItem(text) { }

  void onClick(std::function<void(void)> func) {
    this->setClickListener([func](u64 keys) {
      if (keys & HidNpadButton_A) {
        func();
        return true;
      }
      return false;
    });
  }
};
