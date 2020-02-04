#pragma once

#include <tesla.hpp>

class RaidSearchLayout : public tsl::Gui {
 public:
  RaidSearchLayout(u64 seed, u32 flawlessIVs);
  virtual tsl::Element* createUI();
  void AddTitleBlock(u16 x, u16 y, tsl::Screen* screen);

 private:
  u64 seed = 0;
  u32 flawlessIVs = 0;
  std::string title = "";
};