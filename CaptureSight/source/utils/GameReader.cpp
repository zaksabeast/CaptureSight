#include <vector>
#include <utils/GameReader.hpp>
#include <utils/Utils.hpp>
#include <TitleIds.hpp>

GameReader::GameReader() {
  this->isDebugServiceRunning = checkIfServiceIsRunning("dmnt:cht");
}

Result GameReader::Attach() {
  Result rc = 0;

  dmntchtInitialize();
  rc = dmntchtForceOpenCheatProcess();

  if (R_FAILED(rc)) {
    return rc;
  }

  rc = dmntchtGetCheatProcessMetadata(&(this->metadata));

  return rc;
}

bool GameReader::GetIsPokemonRunning() {
  return (this->metadata.title_id == SWORD_TITLE_ID) || (this->metadata.title_id == SHIELD_TITLE_ID);
}

bool GameReader::GetIsServiceRunning() {
  return this->isDebugServiceRunning;
}

Result GameReader::ReadHeap(u64 offset, void* buffer, size_t size) {
  return dmntchtReadCheatProcessMemory(this->metadata.heap_extents.base + offset, buffer, size);
}

std::vector<std::shared_ptr<PK8>> GameReader::ReadParty() {
  return this->ReadPK8s(this->partyOffset, 6, 0x158);
}

std::vector<std::shared_ptr<PK8>> GameReader::ReadBoxes() {
  return this->ReadPK8s(this->boxOffset, 960, 0x158);
}

std::shared_ptr<PK8> GameReader::ReadWild() {
  auto pkm = this->ReadPK8(this->wildOffset);
  return pkm->GetIsValid() ? pkm : this->ReadPK8(this->legendOffset);
}

std::shared_ptr<PK8> GameReader::ReadRaid() {
  return this->ReadPK8(this->raidOffset);
}

std::shared_ptr<PK8> GameReader::ReadTrade() {
  return this->ReadPK8(this->tradeOffset);
}

u64 GameReader::GetTitleId() {
  return this->metadata.title_id;
}

std::shared_ptr<PK8> GameReader::ReadPK8(u64 offset) {
  u8 pkmBytes[0x148];

  this->ReadHeap(offset, pkmBytes, 0x148);
  return std::make_shared<PK8>(pkmBytes);
}

std::vector<std::shared_ptr<PK8>> GameReader::ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon) {
  std::vector<std::shared_ptr<PK8>> pk8s;
  u32 size = bytesBetweenPokemon * amount;
  u8* pkmBytes = new u8[size];

  this->ReadHeap(offset, pkmBytes, size);

  for (u32 i = 0; i < amount; i++) {
    pk8s.push_back(std::make_shared<PK8>(pkmBytes + (i * bytesBetweenPokemon)));
  }

  delete[] pkmBytes;

  return pk8s;
}
