#include <ui/MainApplication.hpp>
#include <ui/views/MainLayout.hpp>

tsl::elm::Element *MainLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame("Main Menu", "");
  auto menuList = new tsl::elm::List();

  auto wildTradeRaidItem = new tsl::elm::ListItem("Wild/Trade/Raid");
  wildTradeRaidItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, wild, std::placeholders::_1));
  menuList->addItem(wildTradeRaidItem);

  auto partyItem = new tsl::elm::ListItem("Party");
  partyItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, party, std::placeholders::_1));
  menuList->addItem(partyItem);

  auto boxItem = new tsl::elm::ListItem("Box");
  boxItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, box, std::placeholders::_1));
  menuList->addItem(boxItem);

  auto activeDenItem = new tsl::elm::ListItem("Active Dens");
  activeDenItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, activeDens, std::placeholders::_1));
  menuList->addItem(activeDenItem);

  auto allDenItem = new tsl::elm::ListItem("All Dens");
  allDenItem->setClickListener(std::bind(&MainLayout::OnMenuItemClick, this, allDens, std::placeholders::_1));
  menuList->addItem(allDenItem);

  rootFrame->setContent(menuList);

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
