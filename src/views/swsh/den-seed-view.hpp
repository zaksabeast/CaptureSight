#pragma once

#include "../../components/button.hpp"
#include "../detachable-view.hpp"
#include <csight-core.h>
#include <memory>
#include <string>
#include <tesla.hpp>

class DenSeedView : public DetachableView {
 public:
  DenSeedView(std::shared_ptr<csight::swsh::Den> den, size_t den_id) :
      DetachableView("Den " + std::to_string(den_id) + " Raid Seed"), m_den(den) { }

  virtual void setupList(tsl::elm::List *list) {
    list->addItem(new tsl::elm::CategoryHeader("Seed"));
    m_seed_item = new tsl::elm::ListItem("");
    list->addItem(m_seed_item);
  }

  virtual void update() {
    m_seed_item->setFocused(false);
    m_seed_item->setText(utils::num_to_hex(m_den->Seed()));
  }

 private:
  tsl::elm::ListItem *m_seed_item;
  tsl::elm::OverlayFrame *m_frame;
  std::shared_ptr<csight::swsh::Den> m_den;
};
