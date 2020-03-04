#pragma once

#include <tesla.hpp>
#include <csight/core>
#include <ui/PokemonViewMode.hpp>
#include <ui/views/MainLayout.hpp>

class MainApplication : public tsl::Overlay {
 public:
  std::shared_ptr<csight::GameReader> GetGameReader();
  std::string GetPartyTitle(u32 slot);
  std::string GetWildTitle(u32 slot);
  std::string GetBoxTitle(u32 slot);
  void ChangeViewMode(ViewMode mode);
  virtual void initServices() override;
  virtual void exitServices() override;
  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override;

 private:
  std::shared_ptr<csight::GameReader> m_gameReader = std::make_shared<csight::GameReader>();
};