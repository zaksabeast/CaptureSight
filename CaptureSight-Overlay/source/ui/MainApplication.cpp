#include <csight/core>
#include <functional>
#include <memory>
#include <tesla.hpp>
#include <ui/MainApplication.hpp>
#include <ui/views/DenMenuLayout.hpp>
#include <ui/views/ErrorLayout.hpp>
#include <ui/views/PokemonListLayout.hpp>
#include <ui/views/PokemonSummaryLayout.hpp>

std::unique_ptr<tsl::Gui> MainApplication::loadInitialGui() {
  m_gameReader = std::make_shared<csight::GameReader>();

  if (R_FAILED(m_gameReader->Attach()))
    return initially<ErrorLayout>();

  auto mainLayout = initially<MainLayout>();
  mainLayout->SetMenuItemClickCallback(std::bind(&MainApplication::ChangeViewMode, this, std::placeholders::_1));

  return mainLayout;
}

void MainApplication::initServices() {
  smInitialize();
  setInitialize();
  dmntchtInitialize();
  dmntchtForceOpenCheatProcess();
}

void MainApplication::exitServices() {
  dmntchtExit();
  setExit();
  smExit();
}

std::shared_ptr<csight::GameReader> MainApplication::GetGameReader() {
  return m_gameReader;
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
  std::vector<std::shared_ptr<csight::raid::Den>> dens;
  std::unique_ptr<tsl::Gui> layout;
  std::function<std::string(u32)> getTitle = [](u32) { return ""; };

  switch (mode) {
    case activeDens:
      dens = m_gameReader->ReadDens(false);
      tsl::changeTo<DenMenuLayout>(dens, "Active Dens");
      return;
    case allDens:
      dens = m_gameReader->ReadDens(true);
      tsl::changeTo<DenMenuLayout>(dens, "All Dens");
      return;
    case wild:
      guiTitle = "Wild/Trade/Party";
      pkms = { m_gameReader->ReadWild(), m_gameReader->ReadTrade(), m_gameReader->ReadRaid() };
      getTitle = std::bind(&MainApplication::GetWildTitle, this, std::placeholders::_1);
      break;
    case box:
      guiTitle = "Box";
      pkms = m_gameReader->ReadBoxes();
      getTitle = std::bind(&MainApplication::GetBoxTitle, this, std::placeholders::_1);
      break;
    case party:
    default:
      guiTitle = "Party Pokemon";
      pkms = m_gameReader->ReadParty();
      getTitle = std::bind(&MainApplication::GetPartyTitle, this, std::placeholders::_1);
      break;
  }

  tsl::changeTo<PokemonListLayout>(guiTitle, pkms, getTitle);
}
