#define TESLA_INIT_IMPL

#include "./utils/debug.hpp"
#include "./utils/general.hpp"
#include "constants.hpp"
#include "views/arceus/main-view.hpp"
#include "views/bdsp/main-view.hpp"
#include "views/error-view.hpp"
#include "views/swsh/main-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

#define tryGameWithBuildId(view, game, supported_build_id)   \
  if (title_id == game) {                                    \
    if (build_id == supported_build_id) {                    \
      return initially<view>();                              \
    }                                                        \
    return initially<ErrorView>("Unsupported game update!"); \
  }

class MainOverlay : public tsl::Overlay {
 public:
  virtual void initServices() override { dbg::Initialize(); }
  virtual void exitServices() override { dbg::Exit(); }

  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
    if (!utils::check_if_service_is_running("dmnt:cht")) {
      return initially<ErrorView>("dmnt:cht is not running!");
    }

    if (!dbg::HasCheatProcess()) {
      return initially<ErrorView>("No cheat process!\n\nIs a game running?\n\nIs something else\nusing dmnt:cht?");
    }

    auto title_id = dbg::GetCheatProcessTitleId();
    auto build_id = dbg::GetCheatProcessBuildId();

    std::array<u8, 8> supported_sword_build_id = { 0xA3, 0xB7, 0x5B, 0xCD, 0x33, 0x11, 0x38, 0x5A };
    tryGameWithBuildId(MainSwShView, SupportedGame::Sword, supported_sword_build_id);

    std::array<u8, 8> supported_shield_build_id = { 0xA1, 0x68, 0x02, 0x62, 0x5E, 0x78, 0x26, 0xBF };
    tryGameWithBuildId(MainSwShView, SupportedGame::Shield, supported_shield_build_id);

    std::array<u8, 8> supported_diamond_build_id = { 0x94, 0xCE, 0xAE, 0x32, 0x5C, 0x20, 0x5C, 0x4B };
    tryGameWithBuildId(MainBdSpView, SupportedGame::BrilliantDiamond, supported_diamond_build_id);

    std::array<u8, 8> supported_pearl_build_id = { 0x38, 0xF5, 0x9C, 0xBD, 0xA2, 0xEB, 0x9C, 0x44 };
    tryGameWithBuildId(MainBdSpView, SupportedGame::ShiningPearl, supported_pearl_build_id);

    std::array<u8, 8> supported_arceus_build_id = { 0xAE, 0xE8, 0xF1, 0x50, 0xDD, 0xA1, 0xB5, 0xA8 };
    tryGameWithBuildId(MainArceusView, SupportedGame::Arceus, supported_arceus_build_id);

    return initially<ErrorView>("Unsupported game!\n\nTitle Id:\n" + utils::num_to_hex(title_id));
  }

  virtual void onShow() { utils::setIsAttached(true); }

  virtual void onHide() { utils::setIsAttached(false); }
};

int main(int argc, char **argv) {
  csight::init();
  return tsl::loop<MainOverlay>(argc, argv);
}
