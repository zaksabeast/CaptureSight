#include <ui/MainLayout.hpp>
#include <ui/MainApplication.hpp>

extern MainApplication* mainApp;

tsl::Element* MainLayout::createUI() {
  auto rootFrame = new tsl::element::Frame();
  auto menuList = new tsl::element::List();
  auto subHeader = new tsl::element::CustomDrawer(
      100, FB_WIDTH, 200, FB_WIDTH, [](u16 x, u16 y, tsl::Screen* screen) { screen->drawString("Main Menu", false, 20, 100, 20, tsl::a(0xFFFF)); });

  auto wildTradeRaidItem = new tsl::element::ListItem("Wild/Trade/Raid");
  wildTradeRaidItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, wild, std::placeholders::_1));
  menuList->addItem(wildTradeRaidItem);

  auto partyItem = new tsl::element::ListItem("Party");
  partyItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, party, std::placeholders::_1));
  menuList->addItem(partyItem);

  auto boxItem = new tsl::element::ListItem("Box");
  boxItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, box, std::placeholders::_1));
  menuList->addItem(boxItem);

  auto activeDenItem = new tsl::element::ListItem("Active Dens");
  activeDenItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, activeDens, std::placeholders::_1));
  menuList->addItem(activeDenItem);

  rootFrame->addElement(subHeader);
  rootFrame->addElement(menuList);

  return rootFrame;
}

bool MainLayout::OnMenuItemClick(ViewMode mode, s64 keys) {
  if (keys == KEY_A) {
    m_menuItemClickCallback(mode);
    return true;
  }

  return false;
}

void MainLayout::SetMenuItemClickCallback(std::function<void(ViewMode)> callback) {
  m_menuItemClickCallback = callback;
}
