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
  m_gameReader = std::make_shared<csight::game::swsh::SWSHGame>();

  if (R_FAILED(m_gameReader->attach()))
    return initially<ErrorLayout>();

  auto mainLayout = initially<MainLayout>();
  mainLayout->setMenuItemClickCallback(std::bind(&MainApplication::changeViewMode, this, std::placeholders::_1));

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

std::shared_ptr<csight::game::swsh::SWSHGame> MainApplication::getGameReader() {
  return m_gameReader;
}

std::string MainApplication::getPartyTitle(u32 slot) {
  return "P" + std::to_string(slot + 1);
}

std::string MainApplication::getWildTitle(u32 slot) {
  if (slot == 0) {
    return "Wild";
  } else if (slot == 1) {
    return "Trade";
  }

  return "Raid";
}

std::string MainApplication::getBoxTitle(u32 slot) {
  u32 box = (slot / 30) + 1;
  u32 boxSlot = (slot % 30) + 1;
  return "B" + std::to_string(box) + "S" + std::to_string(boxSlot);
}

void MainApplication::changeViewMode(ViewMode mode) {
  std::string guiTitle = "Party Pokemon";
  std::vector<std::shared_ptr<csight::pkm::PK8>> pkms;
  std::vector<std::shared_ptr<csight::game::swsh::Den>> dens;
  std::unique_ptr<tsl::Gui> layout;
  std::function<std::string(u32)> getTitle = [](u32) { return ""; };

  switch (mode) {
    case vanillaActiveDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::Vanilla, true);
      tsl::changeTo<DenMenuLayout>(dens, "Vanilla Active Dens");
      return;
    case vanillaAllDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::Vanilla, false);
      tsl::changeTo<DenMenuLayout>(dens, "Vanilla All Dens");
      return;
    case ioaActiveDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::IsleOfArmor, true);
      tsl::changeTo<DenMenuLayout>(dens, "IoA Active Dens");
      return;
    case ioaAllDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::IsleOfArmor, false);
      tsl::changeTo<DenMenuLayout>(dens, "IoA All Dens");
      return;
    case ctActiveDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::CrownTundra, true);
      tsl::changeTo<DenMenuLayout>(dens, "CT Active Dens");
      return;
    case ctAllDens:
      dens = m_gameReader->readDens(csight::game::swsh::DenType::CrownTundra, false);
      tsl::changeTo<DenMenuLayout>(dens, "CT All Dens");
      return;
    case wild:
      guiTitle = "Wild/Trade/Party";
      pkms = { m_gameReader->readWild(), m_gameReader->readTrade(), m_gameReader->readRaid() };
      getTitle = std::bind(&MainApplication::getWildTitle, this, std::placeholders::_1);
      break;
    case party:
    default:
      guiTitle = "Party Pokemon";
      pkms = m_gameReader->readParty();
      getTitle = std::bind(&MainApplication::getPartyTitle, this, std::placeholders::_1);
      break;
  }

  tsl::changeTo<PokemonListLayout>(guiTitle, pkms, getTitle);
}
