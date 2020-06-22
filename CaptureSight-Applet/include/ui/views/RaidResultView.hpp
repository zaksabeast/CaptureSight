#pragma once

#include <borealis.hpp>
#include <csight/core>
#include <memory>

namespace ui {
  class RaidResultView : public brls::AppletFrame {
   public:
    RaidResultView(std::shared_ptr<csight::raid::Den> den, std::shared_ptr<csight::raid::RaidSearchSettings> settings);
    virtual ~RaidResultView();

   private:
    u32 m_filteredRaidCount = 0;
    brls::List *m_resultList;

    void AddListItem(std::shared_ptr<csight::raid::RaidPokemon> pkm, u32 advance);
  };
}