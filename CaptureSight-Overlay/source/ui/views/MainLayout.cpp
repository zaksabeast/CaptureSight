#include <ui/MainApplication.hpp>
#include <ui/views/MainLayout.hpp>

tsl::elm::Element *MainLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame("Main Menu", "");
  auto menuList = new tsl::elm::List();

  auto wildTradeRaidItem = new tsl::elm::ListItem("Wild/Trade/Raid");
  wildTradeRaidItem->setClickListener(std::bind(&MainLayout::onMenuItemClick, this, wild, std::placeholders::_1));
  menuList->addItem(wildTradeRaidItem);

  auto partyItem = new tsl::elm::ListItem("Party");
  partyItem->setClickListener(std::bind(&MainLayout::onMenuItemClick, this, party, std::placeholders::_1));
  menuList->addItem(partyItem);

  auto activeDenItem = new tsl::elm::ListItem("Active Dens");
  activeDenItem->setClickListener(std::bind(&MainLayout::onMenuItemClick, this, activeDens, std::placeholders::_1));
  menuList->addItem(activeDenItem);

  auto allDenItem = new tsl::elm::ListItem("All Dens");
  allDenItem->setClickListener(std::bind(&MainLayout::onMenuItemClick, this, allDens, std::placeholders::_1));
  menuList->addItem(allDenItem);

  rootFrame->setContent(menuList);

  return rootFrame;
}

bool MainLayout::onMenuItemClick(ViewMode mode, s64 keys) {
  if (keys == KEY_A) {
    m_menuItemClickCallback(mode);
    return true;
  }

  return false;
}

void MainLayout::setMenuItemClickCallback(std::function<void(ViewMode)> callback) {
  m_menuItemClickCallback = callback;
}
