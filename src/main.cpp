#define TESLA_INIT_IMPL

#include "constants.hpp"
#include "debug.hpp"
#include "utils.hpp"
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

    if (title_id == SupportedGame::Sword) {
      std::array<u8, 32> supported_build_id = {
        0xA3, 0xB7, 0x5B, 0xCD, 0x33, 0x11, 0x38, 0x5A, 0xEE, 0xD6, 0x7F, 0xBE, 0xEB, 0x79, 0xCB, 0xB7,
        0xBF, 0x02, 0xF4, 0x71, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      };
      if (build_id == supported_build_id) {
        return initially<MainSwShView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    if (title_id == SupportedGame::Shield) {
      std::array<u8, 32> supported_build_id = {
        0xA1, 0x68, 0x02, 0x62, 0x5E, 0x78, 0x26, 0xBF, 0x83, 0xB6, 0xF9, 0x70, 0x8E, 0x47, 0x5B, 0x91,
        0x2A, 0x9A, 0xB7, 0xDF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      };
      if (build_id == supported_build_id) {
        return initially<MainSwShView>();
      }

      return initially<ErrorView>("Unsupported game update!");
    }

    return initially<ErrorView>("Unsupported game!");
  }

  virtual void onShow() { utils::setIsAttached(true); }

  virtual void onHide() { utils::setIsAttached(false); }
};

int main(int argc, char **argv) {
  csight::init();
  return tsl::loop<MainOverlay>(argc, argv);
}
