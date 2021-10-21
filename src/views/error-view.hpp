#pragma once

#include <tesla.hpp>

class ErrorView : public tsl::Gui {
 public:
  ErrorView(std::string error) : m_error(error) { }

  virtual tsl::elm::Element *createUI() {
    auto frame = new tsl::elm::OverlayFrame("Error", " ");

    auto drawer
        = new tsl::elm::CustomDrawer(std::bind(&ErrorView::addBodyDrawer, this, std::placeholders::_1, std::placeholders::_2,
                                               std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));

    frame->setContent(drawer);
    return frame;
  }

  void addBodyDrawer(tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) {
    screen->drawString(m_error.c_str(), false, 50, 160, 24, screen->a(0xFFFF));
  }

 private:
  std::string m_error;
};
