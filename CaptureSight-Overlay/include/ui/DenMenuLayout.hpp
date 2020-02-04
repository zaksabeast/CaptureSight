#pragma once

#include <csight/core>
#include <tesla.hpp>

class DenMenuLayout : public tsl::Gui {
 public:
  DenMenuLayout(std::vector<std::shared_ptr<csight::Den>> dens, std::string title);
  virtual tsl::Element* createUI();
  void AddTitleBlock(u16 x, u16 y, tsl::Screen* screen);
  bool OnClickDen(std::shared_ptr<csight::Den> den, s64 keys);

 private:
  std::string title = "Den List";
  std::vector<std::shared_ptr<csight::Den>> dens = {};
};