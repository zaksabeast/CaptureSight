#pragma once

#include <tesla.hpp>

class RaidSearchLayout : public tsl::Gui {
 public:
  RaidSearchLayout(u64 seed, u32 flawlessIVs);
  virtual tsl::Element* createUI();
  void AddTitleBlock(u16 x, u16 y, tsl::Screen* screen);

 private:
  std::string m_title = "";
  u64 m_seed = 0;
  u32 m_flawlessIVs = 0;
};