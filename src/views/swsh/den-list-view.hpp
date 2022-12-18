#pragma once

#include "../../components/button.hpp"
#include "../../utils/debug.hpp"
#include "../../utils/general.hpp"
#include "../pokemon-view.hpp"
#include "./den-seed-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <string>
#include <switch.h>
#include <tesla.hpp>

class DenListView : public tsl::Gui {
 public:
  DenListView(std::string title, csight::SwshDenType den_type, size_t count, bool filter_active) :
      m_title(title), m_den_type(den_type), m_count(count), m_filter_active(filter_active) { }

  virtual tsl::elm::Element *createUI() override {
    auto frame = new tsl::elm::OverlayFrame(m_title, " ");
    auto list = new tsl::elm::List();

    list->addItem(new tsl::elm::CategoryHeader("Dens"));

    for (size_t i = 0; i < m_count; i++) {
      bool is_sword = dbg::GetCheatProcessTitleId() == (u64)csight::SupportedGame::Sword;
      auto den = std::make_shared<csight::swsh::Den>(is_sword, i, m_den_type);

      if (!m_filter_active || den->IsActive()) {
        size_t den_id = i + 1;
        std::string label = std::to_string(den_id) + ", " + den->SpeciesString() + ", " + den->ShinyDetailsString();
        auto den_item = new Button(label);
        den_item->onClick([den, den_id]() { tsl::changeTo<DenSeedView>(den, den_id); });
        list->addItem(den_item);
      }
    }

    frame->setContent(list);

    return frame;
  }

 private:
  std::string m_title;
  csight::SwshDenType m_den_type;
  size_t m_count;
  bool m_filter_active;
};

class AllVanillaDenListViewButton : public Button {
 public:
  AllVanillaDenListViewButton() : Button("Vanilla All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("Vanilla All Dens", csight::SwshDenType::Vanilla, 100, false); });
  }
};

class ActiveVanillaDenListViewButton : public Button {
 public:
  ActiveVanillaDenListViewButton() : Button("Vanilla Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("Vanilla Active Dens", csight::SwshDenType::Vanilla, 100, true); });
  }
};

class AllIoADenListViewButton : public Button {
 public:
  AllIoADenListViewButton() : Button("IoA All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("IoA All Dens", csight::SwshDenType::IslandOfArmor, 90, false); });
  }
};

class ActiveIoADenListViewButton : public Button {
 public:
  ActiveIoADenListViewButton() : Button("IoA Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("IoA Active Dens", csight::SwshDenType::IslandOfArmor, 90, true); });
  }
};
class AllCTDenListViewButton : public Button {
 public:
  AllCTDenListViewButton() : Button("CT All Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("CT All Dens", csight::SwshDenType::CrownTundra, 86, false); });
  }
};

class ActiveCTDenListViewButton : public Button {
 public:
  ActiveCTDenListViewButton() : Button("CT Active Dens") {
    this->onClick([]() { tsl::changeTo<DenListView>("CT Active Dens", csight::SwshDenType::CrownTundra, 86, true); });
  }
};
