#include <ui/MainApplication.hpp>
#include <ui/views/MainLayout.hpp>

tsl::elm::Element *MainLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame("Main Menu", "");
  auto menuList = new tsl::elm::List();

  addNavigationButton(menuList, "Wild/Trade/Raid", ViewMode::wild);
  addNavigationButton(menuList, "Party", ViewMode::party);
  addNavigationButton(menuList, "Vanilla Active Dens", ViewMode::vanillaActiveDens);
  addNavigationButton(menuList, "Vanilla All Dens", ViewMode::vanillaAllDens);
  addNavigationButton(menuList, "IoA Active Dens", ViewMode::ioaActiveDens);
  addNavigationButton(menuList, "IoA All Dens", ViewMode::ioaAllDens);
  addNavigationButton(menuList, "CT Active Dens", ViewMode::ctActiveDens);
  addNavigationButton(menuList, "CT All Dens", ViewMode::ctAllDens);

  rootFrame->setContent(menuList);

  return rootFrame;
}

void MainLayout::addNavigationButton(tsl::elm::List *container, std::string title, ViewMode viewMode) {
  auto navButton = new tsl::elm::ListItem(title);
  navButton->setClickListener(std::bind(&MainLayout::onMenuItemClick, this, viewMode, std::placeholders::_1));

  container->addItem(navButton);
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
