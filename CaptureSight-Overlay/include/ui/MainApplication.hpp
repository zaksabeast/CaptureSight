#pragma once

#include <tesla.hpp>
#include <csight/core>
#include <ui/PokemonViewMode.hpp>
#include <ui/MainLayout.hpp>

class MainApplication : public tsl::Overlay {
 public:
  tsl::Gui* onSetup();
  void onDestroy();
  std::shared_ptr<csight::GameReader> GetGameReader();
  std::string GetPartyTitle(u32 slot);
  std::string GetWildTitle(u32 slot);
  std::string GetBoxTitle(u32 slot);
  void ChangeViewMode(ViewMode mode);

 private:
  MainLayout* mainLayout = new MainLayout();
  std::shared_ptr<csight::GameReader> gameReader = std::make_shared<csight::GameReader>();
};