#pragma once

#include <csight/core>
#include <tesla.hpp>

class DenMenuLayout : public tsl::Gui {
 public:
  DenMenuLayout(std::vector<std::shared_ptr<csight::raid::Den>> dens, std::string title);
  virtual tsl::elm::Element *createUI();
  bool OnClickDen(std::shared_ptr<csight::raid::Den> den, s64 keys);

 private:
  std::string m_title = "Den List";
  std::vector<std::shared_ptr<csight::raid::Den>> m_dens = {};
};