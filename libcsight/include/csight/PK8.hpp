#pragma once

#include <csight/PKM.hpp>
#include <csight/lookups/Types.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight {
  class PK8 : public PKM {
   public:
    PK8(u8 *data);
    ~PK8();

    void Crypt();
    u8 GetBlockPosition(u8 index);
    void ShuffleArray(u8 shuffleValue);
    u32 GetEncryptionConstant();
    u16 GetSpecies();
    std::string GetSpeciesString();
    bool CheckEncrypted();
    u32 GetIV32();
    u8 GetIV(u8 stat);
    std::vector<u8> GetIVs();
    u8 GetEV(u8 stat);
    std::vector<u8> GetEVs();
    bool GetIsShiny();
    ability::Ability GetAbility();
    std::string GetAbilityString();
    u32 GetTSV();
    u32 GetPID();
    u16 GetSID();
    u16 GetTID();
    u16 GetMove(u8 slot);
    std::string GetMoveString(u8 slot);
    std::vector<u16> GetMoves();
    std::vector<std::string> GetMoveStrings(u8 slot);
    u8 GetMovePP(u8 slot);
    u8 GetNature();
    std::string GetNatureString();
    u8 GetMintedNature();
    std::string GetMintedNatureString();
    u16 GetChecksum();
    bool GetHasValidChecksum();
    bool GetIsEgg();
    bool GetIsValid();
    u8 GetCurrentHandler();
    u8 GetHTFriendship();
    u8 GetOTFriendship();
    u8 GetCurrentFriendship();
    u64 GetRaidSeed();
    std::future<u64> GetRaidSeedAsync();
    u8 GetForm();

   private:
    u8 *m_data = new u8[0x148];
    u32 m_blockSize = 80;
    u32 m_storedSize = 0x148;
    u32 m_partySize = 0x158;

    u16 CalculateChecksum();
  };
}  // namespace csight