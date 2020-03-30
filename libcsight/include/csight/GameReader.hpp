#pragma once

#include <csight/PK8.hpp>
#include <csight/RaidDetails.hpp>
#include <dmntcht.h>
#include <stratosphere.hpp>
#include <switch.h>
#include <vector>

namespace csight {
  class GameReader : public raid::RaidDetails {
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
    u64 GetTitleId() override;

   private:
    bool m_isDebugServiceRunning = false;
    u64 m_partyOffset = 0x4298E8E0;
    u64 m_boxOffset = 0x4293D8B0;
    u64 m_wildOffset = 0x8D45C648;
    u64 m_raidOffset = 0x85C7AB08;
    u64 m_legendOffset = 0x85C74F88;
    u64 m_tradeOffset = 0x2E32206A;
    DmntCheatProcessMetadata m_metadata;

    Result ReadHeap(u64 address, void *buffer, size_t size) override;
    std::shared_ptr<PK8> ReadPK8(u64 offset);
    std::vector<std::shared_ptr<PK8>> ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon);
  };
}  // namespace csight
