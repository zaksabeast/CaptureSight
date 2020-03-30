#pragma once

#include <tesla.hpp>

#define ADVANCES_TO_SEARCH 5000

class RaidSearchResultLayout : public tsl::Gui {
 public:
  RaidSearchResultLayout(u64 seed, u32 flawlessIVs);
  virtual tsl::elm::Element *createUI();
  void AddRaidMenuItem(tsl::elm::List *denList, std::shared_ptr<csight::raid::RaidPokemon> raid, u32 advance);

 private:
  u64 m_seed = 0;
  u8 m_flawlessIVs = 1;
  u32 m_firstShinyAdvance = ADVANCES_TO_SEARCH;
  // Assume shiny will be star in case no nearby shinies are found
  std::string m_firstShinyTypeText = " ★ ";
};