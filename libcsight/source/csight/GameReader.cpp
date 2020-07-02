#include <csight/GameReader.hpp>
#include <csight/TitleIds.hpp>
#include <csight/Utils.hpp>
#include <vector>

namespace csight {
  GameReader::GameReader(bool shouldUseSmallMemoryMode) : raid::RaidDetails::RaidDetails(shouldUseSmallMemoryMode) {
    m_isDebugServiceRunning = utils::checkIfServiceIsRunning("dmnt:cht");
  }

  Result GameReader::attach() { return dmntchtGetCheatProcessMetadata(&m_metadata); }

  bool GameReader::getIsPokemonRunning() {
    return (m_metadata.title_id == SWORD_TITLE_ID) || (m_metadata.title_id == SHIELD_TITLE_ID);
  }

  bool GameReader::getIsServiceRunning() { return m_isDebugServiceRunning; }

  Result GameReader::readHeap(u64 offset, void *buffer, size_t size) {
    return dmntchtReadCheatProcessMemory(m_metadata.heap_extents.base + offset, buffer, size);
  }

  std::vector<std::shared_ptr<PK8>> GameReader::readParty() { return this->readPK8s(m_partyOffset, 6, 0x158); }

  std::vector<std::shared_ptr<PK8>> GameReader::readBoxes() { return this->readPK8s(m_boxOffset, 960, 0x158); }

  std::shared_ptr<PK8> GameReader::readWild() {
    auto pkm = this->readPK8(m_wildOffset);
    return pkm->getIsValid() ? pkm : this->readPK8(m_legendOffset);
  }

  std::shared_ptr<PK8> GameReader::readRaid() { return this->readPK8(m_raidOffset); }

  std::shared_ptr<PK8> GameReader::readTrade() { return this->readPK8(m_tradeOffset); }

  u64 GameReader::getTitleId() { return m_metadata.title_id; }

  std::shared_ptr<PK8> GameReader::readPK8(u64 offset) {
    u8 pkmBytes[0x148];

    this->readHeap(offset, pkmBytes, 0x148);
    auto pkm = std::make_shared<PK8>(pkmBytes);

    return pkm->getIsValid() ? pkm : std::make_shared<PK8>();
  }

  std::vector<std::shared_ptr<PK8>> GameReader::readPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon) {
    std::vector<std::shared_ptr<PK8>> pk8s;
    u32 size = bytesBetweenPokemon * amount;
    u8 *pkmBytes = new u8[size];

    this->readHeap(offset, pkmBytes, size);

    for (u32 i = 0; i < amount; i++) {
      pk8s.push_back(std::make_shared<PK8>(pkmBytes + (i * bytesBetweenPokemon)));
    }

    delete[] pkmBytes;

    return pk8s;
  }

  u32 GameReader::getTrainerSIDTID() {
    u32 sidtid = 0;

    this->readHeap(m_trainerBlockOffset + 0xA0, &sidtid, sizeof(u32));
    return sidtid;
  }
}  // namespace csight