#pragma once

#include <vector>
#include <pu/Plutonium>
#include <csight/core>

using namespace csight;

class PokemonListLayout : public pu::ui::Layout {
 public:
  PokemonListLayout();
  PU_SMART_CTOR(PokemonListLayout)

  void UpdateValues(std::vector<std::shared_ptr<PK8>> pk8s, std::function<std::string(u32)> GetTitle);
  void SetOnInputMenuItem(std::function<void(u32)> onInput);
  void SetSelectedIndex(u32 index);

 private:
  pu::ui::elm::Menu::Ref menu;
  std::function<void(u32)> onMenuItemInput;
  pu::ui::elm::MenuItem::Ref CreateMenuItem(std::shared_ptr<PK8> pk8, u32 slot, std::string title);
  void ClickMenuItem(u32 slot);
};