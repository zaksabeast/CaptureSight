#pragma once

#include <csight/core>
#include <tesla.hpp>

class PokemonSummaryLayout : public tsl::Gui {
 public:
  PokemonSummaryLayout(std::shared_ptr<csight::PK8>);
  virtual tsl::Element* createUI();
  void AddBodyDrawer(u16 x, u16 y, tsl::Screen* screen);
  bool FindRaidSeed(s64 keys);

 private:
  std::shared_ptr<csight::PK8> pkm;
  u64 seed = 0;
  bool shouldSearchForSeed = false;
};