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

    std::array<u8, 8> supported_diamond_build_id = { 0x35, 0xB9, 0xD8, 0x77, 0x9B, 0x19, 0x51, 0x41 };
    tryGameWithBuildId(MainBdSpView, SupportedGame::BrilliantDiamond, supported_diamond_build_id);

    std::array<u8, 8> supported_pearl_build_id = { 0xD7, 0x52, 0x46, 0xEC, 0x33, 0xC2, 0xF6, 0x4B };
    tryGameWithBuildId(MainBdSpView, SupportedGame::ShiningPearl, supported_pearl_build_id);

    std::array<u8, 8> supported_arceus_build_id = { 0xBE, 0xF2, 0x91, 0xF2, 0x63, 0x9F, 0x7A, 0xFE };
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
