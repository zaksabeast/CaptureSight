#include <csight/GameReader.hpp>
#include <csight/TitleIds.hpp>
#include <csight/Utils.hpp>
#include <vector>

namespace csight {
  GameReader::GameReader(bool shouldUseSmallMemoryMode) : raid::RaidDetails::RaidDetails(shouldUseSmallMemoryMode) {
    m_isDebugServiceRunning = utils::checkIfServiceIsRunning("dmnt:cht");
  }

  Result GameReader::Attach() { return dmntchtGetCheatProcessMetadata(&m_metadata); }

  bool GameReader::GetIsPokemonRunning() {
    return (m_metadata.title_id == SWORD_TITLE_ID) || (m_metadata.title_id == SHIELD_TITLE_ID);
  }

  bool GameReader::GetIsServiceRunning() { return m_isDebugServiceRunning; }

  Result GameReader::ReadHeap(u64 offset, void *buffer, size_t size) {
    return dmntchtReadCheatProcessMemory(m_metadata.heap_extents.base + offset, buffer, size);
  }

  std::vector<std::shared_ptr<PK8>> GameReader::ReadParty() { return this->ReadPK8s(m_partyOffset, 6, 0x158); }

  std::vector<std::shared_ptr<PK8>> GameReader::ReadBoxes() { return this->ReadPK8s(m_boxOffset, 960, 0x158); }

  std::shared_ptr<PK8> GameReader::ReadWild() {
    auto pkm = this->ReadPK8(m_wildOffset);
    return pkm->GetIsValid() ? pkm : this->ReadPK8(m_legendOffset);
  }

  std::shared_ptr<PK8> GameReader::ReadRaid() { return this->ReadPK8(m_raidOffset); }

  std::shared_ptr<PK8> GameReader::ReadTrade() { return this->ReadPK8(m_tradeOffset); }

  u64 GameReader::GetTitleId() { return m_metadata.title_id; }

  std::shared_ptr<PK8> GameReader::ReadPK8(u64 offset) {
    u8 pkmBytes[0x148];

    this->ReadHeap(offset, pkmBytes, 0x148);
    auto pkm = std::make_shared<PK8>(pkmBytes);

    return pkm->GetIsValid() ? pkm : std::make_shared<PK8>();
  }

  std::vector<std::shared_ptr<PK8>> GameReader::ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon) {
    std::vector<std::shared_ptr<PK8>> pk8s;
    u32 size = bytesBetweenPokemon * amount;
    u8 *pkmBytes = new u8[size];

    this->ReadHeap(offset, pkmBytes, size);

    for (u32 i = 0; i < amount; i++) {
      pk8s.push_back(std::make_shared<PK8>(pkmBytes + (i * bytesBetweenPokemon)));
    }

    delete[] pkmBytes;

    return pk8s;
  }
}  // namespace csight