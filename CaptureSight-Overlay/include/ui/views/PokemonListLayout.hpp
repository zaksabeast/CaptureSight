#pragma once

#include <csight/core>
#include <functional>
#include <future>
#include <optional>
#include <tesla.hpp>

class PokemonListLayout : public tsl::Gui {
 public:
  PokemonListLayout(std::string title, std::vector<std::shared_ptr<csight::pkm::PK8>> pkms,
                    std::function<std::string(u32)> GetPKMTitle);
  virtual tsl::elm::Element *createUI();
  virtual void update() override;
  bool onClickPKM(tsl::elm::ListItem *button, std::string buttonText, std::shared_ptr<csight::pkm::PK8> pkm, s64 keys);

 private:
  std::string m_title = "Pokemon List";
  std::vector<std::shared_ptr<csight::pkm::PK8>> m_pkms = {};
  std::function<std::string(u32)> m_GetPKMTitle = [](u32) { return ""; };
  std::optional<tsl::elm::ListItem *> m_waitingButton;
  std::optional<std::string> m_waitingButtonText;
  std::optional<std::future<u64>> m_seedFuture;
  int m_seedCount = 0;
};