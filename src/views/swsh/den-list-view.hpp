#pragma once

#include "../../components/button.hpp"
#include "../../constants.hpp"
#include "../../utils/debug.hpp"
#include "../../utils/general.hpp"
#include "../pokemon-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class DenListView : public tsl::Gui {
 public:
  DenListView(std::string title, u64 mem_offset, size_t id_offset, size_t count, bool filter_active) :
      m_title(title), m_mem_offset(mem_offset), m_id_offset(id_offset), m_count(count), m_filter_active(filter_active) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame(m_title, " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Dens"));

    for (size_t i = 0; i < m_count; i++) {
      u64 offset = m_mem_offset + (i * csight::Den::Size);
      size_t den_id = i + m_id_offset;
      bool is_sword = dbg::GetCheatProcessTitleId() == SupportedGame::Sword;

      auto den_bytes = dbg::ReadCheatProcessHeapBytes<csight::Den::Size>(offset);
      auto den = csight::Den(den_bytes, den_id, is_sword);

      if (!m_filter_active || den.IsActive()) {
        std::string label = std::to_string(i + 1) + ", " + den.SpeciesString() + ", " + den.ShinyDetailsString();
        list->addItem(new tsl::elm::ListItem(label));
      }
    }

    frame->setContent(list);

    return frame;
  }

 private:
  std::string m_title;
  u64 m_mem_offset;
  size_t m_id_offset;
  size_t m_count;
  bool m_filter_active;
};

class AllVanillaDenListViewButton : public Button {
 public:
  AllVanillaDenListViewButton() : Button("Vanilla All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("Vanilla All Dens", swsh::DenOffset::Vanilla, 0, 100, false); });
  }
};

class ActiveVanillaDenListViewButton : public Button {
 public:
  ActiveVanillaDenListViewButton() : Button("Vanilla Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("Vanilla Active Dens", swsh::DenOffset::Vanilla, 0, 100, true); });
  }
};

class AllIoADenListViewButton : public Button {
 public:
  AllIoADenListViewButton() : Button("IoA All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("IoA All Dens", swsh::DenOffset::IslandOfArmor, 100, 90, false); });
  }
};

class ActiveIoADenListViewButton : public Button {
 public:
  ActiveIoADenListViewButton() : Button("IoA Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("IoA Active Dens", swsh::DenOffset::IslandOfArmor, 100, 90, true); });
  }
};

class AllCTDenListViewButton : public Button {
 public:
  AllCTDenListViewButton() : Button("CT All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("CT All Dens", swsh::DenOffset::CrownTundra, 190, 86, false); });
  }
};

class ActiveCTDenListViewButton : public Button {
 public:
  ActiveCTDenListViewButton() : Button("CT Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("CT Active Dens", swsh::DenOffset::CrownTundra, 190, 86, true); });
  }
};
