#pragma once

#include <csight/core>
#include <tesla.hpp>

class DenMenuLayout : public tsl::Gui {
 public:
  DenMenuLayout(std::vector<std::shared_ptr<csight::raid::Den>> dens, std::string title);
  virtual tsl::elm::Element *createUI();

 private:
  std::string m_title = "Den List";
  std::vector<std::shared_ptr<csight::raid::Den>> m_dens = {};
};