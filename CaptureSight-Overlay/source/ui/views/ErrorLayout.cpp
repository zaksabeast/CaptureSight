#include <ui/views/ErrorLayout.hpp>

tsl::Element* ErrorLayout::createUI() {
  auto rootFrame = new tsl::element::Frame();
  auto header = new tsl::element::CustomDrawer(
      0, 0, 100, FB_WIDTH, [](u16 x, u16 y, tsl::Screen* screen) { screen->drawString("Error!", false, 20, 50, 30, tsl::a(0xFFFF)); });

  rootFrame->addElement(header);

  return rootFrame;
}
