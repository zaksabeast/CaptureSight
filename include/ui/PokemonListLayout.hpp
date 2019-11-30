#pragma once

#include <vector>
#include <pu/Plutonium>
#include <utils/PK8.hpp>

class PokemonListLayout : public pu::ui::Layout {
 public:
  PokemonListLayout();
  PU_SMART_CTOR(PokemonListLayout)

  void UpdateValues(std::vector<std::shared_ptr<PK8>> pk8s);

 private:
  pu::ui::elm::Menu::Ref menu;
  std::vector<pu::ui::elm::MenuItem::Ref> menuItems;
  pu::ui::elm::MenuItem::Ref CreateMenuItem(PK8* pkm, u32 slot);
  void OnInputPokemonItem(u32 slot);
};