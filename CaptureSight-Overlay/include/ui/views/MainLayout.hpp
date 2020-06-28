#pragma once

#include <csight/core>
#include <tesla.hpp>
#include <ui/PokemonViewMode.hpp>

class MainLayout : public tsl::Gui {
 public:
  virtual tsl::elm::Element *createUI();
  bool onMenuItemClick(ViewMode mode, s64 keys);
  void setMenuItemClickCallback(std::function<void(ViewMode)>);

 private:
  std::function<void(ViewMode)> m_menuItemClickCallback = [](ViewMode) {};
};
