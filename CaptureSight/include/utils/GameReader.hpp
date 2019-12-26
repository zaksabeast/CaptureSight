#pragma once

#include <vector>
#include <switch.h>
#include <stratosphere.hpp>
#include <dmntcht.h>
#include <utils/PK8.hpp>
#include <utils/Den.hpp>

class GameReader : public RaidDetails {
 public:
  GameReader();
  Result Attach();
  bool GetIsPokemonRunning();
  bool GetIsServiceRunning();
  std::vector<std::shared_ptr<PK8>> ReadParty();
  std::vector<std::shared_ptr<PK8>> ReadBoxes();
  std::shared_ptr<PK8> ReadWild();
  std::shared_ptr<PK8> ReadRaid();
  std::shared_ptr<PK8> ReadTrade();

 private:
  bool isDebugServiceRunning = false;
  u64 partyOffset = 0x4298E8E0;
  u64 boxOffset = 0x4293D8B0;
  u64 wildOffset = 0x8D45C648;
  u64 raidOffset = 0x85C7AB08;
  u64 tradeOffset = 0x2E32206A;
  DmntCheatProcessMetadata metadata;
  Result ReadHeap(u64 address, void* buffer, size_t size) override;
  std::shared_ptr<PK8> ReadPK8(u64 offset);
  std::vector<std::shared_ptr<PK8>> ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon);
};
