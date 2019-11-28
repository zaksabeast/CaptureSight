#include <vector>
#include <utils/GameReader.hpp>

GameReader::GameReader() {
  dmntchtGetCheatProcessMetadata(&(this->metadata));
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

std::vector<std::shared_ptr<PK8>> GameReader::ReadWild() {
  return this->ReadPK8s(this->wildOffset, 1, 0x158);
}

std::vector<std::shared_ptr<PK8>> GameReader::ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon) {
  std::vector<std::shared_ptr<PK8>> pk8s;
  u32 size = 0x148 * amount;
  u8* pkmBytes = new u8[size];

  this->ReadHeap(offset, pkmBytes, size);

  for (u32 i = 0; i < amount; i++) {
    pk8s.push_back(std::make_shared<PK8>(pkmBytes + (i * bytesBetweenPokemon)));
  }

  delete[] pkmBytes;

  return pk8s;
}