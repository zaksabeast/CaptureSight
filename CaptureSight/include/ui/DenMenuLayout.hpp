#pragma once

#include <vector>
#include <pu/Plutonium>
#include <utils/Den.hpp>

class DenMenuLayout : public pu::ui::Layout {
 public:
  PU_SMART_CTOR(DenMenuLayout)

  void UpdateValues(std::vector<std::shared_ptr<Den>> dens);

 private:
  pu::ui::elm::Menu::Ref menu;
};