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
    GameReader(bool shouldUseSmallMemoryMode);
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
    u64 m_partyOffset = 0x450BE8C0;
    u64 m_boxOffset = 0x4506D890;
    u64 m_wildOffset = 0x8FEA3358;
    u64 m_raidOffset = 0x886C1BD8;
    u64 m_legendOffset = 0x85C74F88;
    u64 m_tradeOffset = 0xAF285F68;
    DmntCheatProcessMetadata m_metadata;

    Result ReadHeap(u64 address, void *buffer, size_t size) override;
    std::shared_ptr<PK8> ReadPK8(u64 offset);
    std::vector<std::shared_ptr<PK8>> ReadPK8s(u64 offset, u32 amount, u32 bytesBetweenPokemon);
  };
}  // namespace csight
