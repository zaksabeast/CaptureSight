#pragma once

#include <vector>
#include <pu/Plutonium>
#include <utils/PK8.hpp>

class PokemonListLayout : public pu::ui::Layout {
 public:
  PU_SMART_CTOR(PokemonListLayout)

  void UpdateValues(std::vector<std::shared_ptr<PK8>> pk8s, std::function<std::string(u32)> GetTitle);

 private:
  pu::ui::elm::Menu::Ref menu;
  std::vector<pu::ui::elm::MenuItem::Ref> menuItems;
  pu::ui::elm::MenuItem::Ref CreateMenuItem(std::shared_ptr<PK8> pk8, u32 slot, std::string title);
  void OnInputPokemonItem(u32 slot);
};