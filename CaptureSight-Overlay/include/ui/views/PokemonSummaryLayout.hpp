#pragma once

#include <csight/core>
#include <tesla.hpp>

class PokemonSummaryLayout : public tsl::Gui {
 public:
  PokemonSummaryLayout(std::shared_ptr<csight::PK8>);
  virtual tsl::elm::Element* createUI();
  void AddBodyDrawer(tsl::gfx::Renderer* screen, u16 x, u16 y, u16 w, u16 h);

 private:
  std::shared_ptr<csight::PK8> m_pkm;
  u64 m_seed = 0;
};