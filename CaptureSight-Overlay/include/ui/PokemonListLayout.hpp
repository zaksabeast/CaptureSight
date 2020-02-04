#pragma once

#include <functional>
#include <csight/core>
#include <tesla.hpp>

class PokemonListLayout : public tsl::Gui {
 public:
  PokemonListLayout(std::string title, std::vector<std::shared_ptr<csight::PK8>> pkms, std::function<std::string(u32)> GetPKMTitle);
  virtual tsl::Element* createUI();
  void AddTitleBlock(u16 x, u16 y, tsl::Screen* screen);
  bool OnClickPKM(std::shared_ptr<csight::PK8> pkm, s64 keys);

 private:
  std::string title = "Pokemon List";
  std::vector<std::shared_ptr<csight::PK8>> pkms = {};
  std::function<std::string(u32)> GetPKMTitle = [](u32) { return ""; };
  std::function<void(std::shared_ptr<csight::PK8>)> SelectPKM = [](std::shared_ptr<csight::PK8>) {};
};