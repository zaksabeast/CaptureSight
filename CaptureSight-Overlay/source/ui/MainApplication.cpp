#include <functional>
#include <tesla.hpp>
#include <csight/core>
#include <ui/ErrorLayout.hpp>
#include <ui/MainApplication.hpp>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/PokemonListLayout.hpp>
#include <ui/DenMenuLayout.hpp>

MainApplication* mainApp;

tsl::Gui* MainApplication::onSetup() {
  smInitialize();
  dmntchtInitialize();
  dmntchtForceOpenCheatProcess();

  if (R_FAILED(this->gameReader->Attach()))
    return new ErrorLayout();

  this->mainLayout->SetMenuItemClickCallback(std::bind(&MainApplication::ChangeViewMode, this, std::placeholders::_1));

  return this->mainLayout;
}

void MainApplication::onDestroy() {
  dmntchtExit();
  smExit();
}

std::shared_ptr<csight::GameReader> MainApplication::GetGameReader() {
  return this->gameReader;
}

std::string MainApplication::GetPartyTitle(u32 slot) {
  return "P" + std::to_string(slot + 1);
}

std::string MainApplication::GetWildTitle(u32 slot) {
  if (slot == 0) {
    return "Wild";
  } else if (slot == 1) {
    return "Trade";
  }

  return "Raid";
}

std::string MainApplication::GetBoxTitle(u32 slot) {
  u32 box = (slot / 30) + 1;
  u32 boxSlot = (slot % 30) + 1;
  return "B" + std::to_string(box) + "S" + std::to_string(boxSlot);
}

void MainApplication::ChangeViewMode(ViewMode mode) {
  std::string guiTitle = "Party Pokemon";
  std::vector<std::shared_ptr<csight::PK8>> pkms;
  std::vector<std::shared_ptr<csight::Den>> dens;
  tsl::Gui* layout;
  std::function<std::string(u32)> getTitle = [](u32) { return ""; };

  switch (mode) {
    case activeDens:
      dens = this->gameReader->ReadDens(false);
      layout = new DenMenuLayout(dens, "Active Dens");
      this->mainLayout->changeTo(layout);
      return;
    case wild:
      guiTitle = "Wild/Trade/Party";
      pkms = {this->gameReader->ReadWild(), this->gameReader->ReadTrade(), this->gameReader->ReadRaid()};
      getTitle = std::bind(&MainApplication::GetWildTitle, this, std::placeholders::_1);
      break;
    case box:
      guiTitle = "Box";
      pkms = this->gameReader->ReadBoxes();
      getTitle = std::bind(&MainApplication::GetBoxTitle, this, std::placeholders::_1);
      break;
    case party:
    default:
      guiTitle = "Party Pokemon";
      pkms = this->gameReader->ReadParty();
      getTitle = std::bind(&MainApplication::GetPartyTitle, this, std::placeholders::_1);
      break;
  }

  layout = new PokemonListLayout(guiTitle, pkms, getTitle);
  this->mainLayout->changeTo(layout);
}
