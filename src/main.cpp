#define TESLA_INIT_IMPL

#include "./utils/debug.hpp"
#include "./utils/general.hpp"
#include "constants.hpp"
#include "views/bdsp/main-view.hpp"
#include "views/error-view.hpp"
#include "views/swsh/main-view.hpp"
#include <csight-core.h>
#include <dmntcht.h>
#include <memory>
#include <switch.h>
#include <tesla.hpp>

class MainOverlay : public tsl::Overlay {
 public:
  virtual void initServices() override { dbg::Initialize(); }
  virtual void exitServices() override { dbg::Exit(); }

  virtual std::unique_ptr<tsl::Gui> loadInitialGui() override {
    if (!utils::check_if_service_is_running("dmnt:cht")) {
      return initially<ErrorView>("dmnt:cht is not running!");
    }

    auto title_id = dbg::GetCheatProcessTitleId();
    auto build_id = dbg::GetCheatProcessBuildId();

    if (!dbg::HasCheatProcess()) {
      return initially<ErrorView>("No cheat process!\n\nIs a game running?\n\nIs something else\nusing dmnt:cht?");
    }

    if (title_id == SupportedGame::Sword) {
      std::array<u8, 8> supported_build_id = { 0xA3, 0xB7, 0x5B, 0xCD, 0x33, 0x11, 0x38, 0x5A };
      if (build_id == supported_build_id) {
        return initially<MainSwShView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    if (title_id == SupportedGame::Shield) {
      std::array<u8, 8> supported_build_id = { 0xA1, 0x68, 0x02, 0x62, 0x5E, 0x78, 0x26, 0xBF };
      if (build_id == supported_build_id) {
        return initially<MainSwShView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    if (title_id == SupportedGame::BrilliantDiamond) {
      std::array<u8, 8> supported_build_id = { 0xD9, 0xE9, 0x6F, 0xB9, 0x28, 0x78, 0xE3, 0x45 };
      if (build_id == supported_build_id) {
        return initially<MainBdSpView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    if (title_id == SupportedGame::ShiningPearl) {
      std::array<u8, 8> supported_build_id = { 0x3C, 0x70, 0xCA, 0xE1, 0x53, 0xDF, 0x0B, 0x4F };
      if (build_id == supported_build_id) {
        return initially<MainBdSpView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    return initially<ErrorView>("Unsupported game!\n\nTitle Id:\n" + utils::num_to_hex(title_id));
  }

  virtual void onShow() { utils::setIsAttached(true); }

  virtual void onHide() { utils::setIsAttached(false); }
};

int main(int argc, char **argv) {
  csight::init();
  return tsl::loop<MainOverlay>(argc, argv);
}