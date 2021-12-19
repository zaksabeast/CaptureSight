#pragma once

#include "../utils/general.hpp"
#include <tesla.hpp>

class DetachableView : public tsl::Gui {
 public:
  DetachableView(std::string title) : m_title(title) {};
  ~DetachableView() {};

  virtual tsl::elm::Element *createUI() {
    auto frame = new tsl::elm::OverlayFrame(m_title, "Press \uE079 Up to attach/detach controls");
    auto list = new tsl::elm::List();
    this->setupList(list);
    frame->setContent(list);
    return frame;
  }

  virtual bool handleInput(u64 keysDown, u64 keysHeld, const HidTouchState &touchPos, HidAnalogStickState leftJoyStick,
                           HidAnalogStickState rightJoyStick) {
    if (utils::getIsAttached()) {
      if (keysDown & HidNpadButton_B) {
        return false;
      }

      this->handleInputIfAttached(keysDown, keysHeld, touchPos, leftJoyStick, rightJoyStick);
    }

    if (keysDown & HidNpadButton_Up) {
      utils::toggleAttached();
    }

    // This view stays open while the game accepts input,
    // so handling the input prevents odd visual effects
    return true;
  }

  virtual void setupList(tsl::elm::List *list) = 0;
  virtual void handleInputIfAttached(u64 keysDown, u64 keysHeld, const HidTouchState &touchPos, HidAnalogStickState leftJoyStick,
                                     HidAnalogStickState rightJoyStick) {};

 private:
  std::string m_title;
};
