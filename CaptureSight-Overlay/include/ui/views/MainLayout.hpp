#pragma once

#include <csight/core>
#include <tesla.hpp>
#include <ui/PokemonViewMode.hpp>

class MainLayout : public tsl::Gui {
 public:
  virtual tsl::Element* createUI();
  bool OnMenuItemClick(ViewMode mode, s64 keys);
  void SetMenuItemClickCallback(std::function<void(ViewMode)>);
  tsl::element::Frame* GetRootFrame();

 private:
  std::function<void(ViewMode)> m_menuItemClickCallback = [](ViewMode) {};
};
