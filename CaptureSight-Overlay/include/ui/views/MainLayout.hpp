#pragma once

#include <csight/core>
#include <tesla.hpp>
#include <ui/PokemonViewMode.hpp>

class MainLayout : public tsl::Gui {
 public:
  virtual tsl::elm::Element *createUI();
  void addNavigationButton(tsl::elm::List *container, std::string title, ViewMode viewMode);
  bool onMenuItemClick(ViewMode mode, s64 keys);
  void setMenuItemClickCallback(std::function<void(ViewMode)>);

 private:
  std::function<void(ViewMode)> m_menuItemClickCallback = [](ViewMode) {};
};
