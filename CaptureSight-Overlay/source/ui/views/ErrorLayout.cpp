#include <ui/views/ErrorLayout.hpp>

tsl::elm::Element *ErrorLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame("", "");
  auto header = new tsl::elm::CustomDrawer([](tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) {
    screen->drawString("Error!", false, 20, 50, 30, screen->a(0xFFFF));
  });

  rootFrame->setContent(header);

  return rootFrame;
}
