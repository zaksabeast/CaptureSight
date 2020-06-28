#pragma once

#include <csight/core>
#include <tesla.hpp>
#include <ui/PokemonViewMode.hpp>
#include <ui/views/MainLayout.hpp>

class MainApplication : public tsl::Overlay {
 public:
  std::shared_ptr<csight::GameReader> getGameReader();
  std::string getPartyTitle(u32 slot);
  std::string getWildTitle(u32 slot);
  std::string getBoxTitle(u32 slot);
  void changeViewMode(ViewMode mode);
  virtual void initServices() override;
  virtual void exitServices() override;
  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override;

 private:
  std::shared_ptr<csight::GameReader> m_gameReader;
};