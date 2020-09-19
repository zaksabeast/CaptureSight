#pragma once

#include <csight/Enums/Gender.hpp>
#include <csight/Enums/Types.hpp>
#include <csight/PKM/PKM.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight::pkm {
  class PK8 : public PKM {

   public:
    PK8();
    PK8(u8 *data);
    ~PK8();

    static const u32 StoredSize = 0x148;
    static const u32 PartySize = 0x158;

    void crypt();
    u8 getBlockPosition(u8 index);
    void shuffleArray(u8 shuffleValue);
    u32 getEC();
    u16 getSpecies();
    bool checkEncrypted();
    u32 getIV32();
    u8 getIV(u8 stat);
    std::vector<u8> getIVs();
    u8 getEV(u8 stat);
    std::vector<u8> getEVs();
    enums::Ability getAbility();
    u32 getPID();
    u32 getSIDTID();
    u16 getMove(u8 slot);
    std::string getMoveString(u8 slot);
    std::vector<u16> getMoves();
    std::vector<std::string> getMoveStrings(u8 slot);
    u8 getMovePP(u8 slot);
    u8 getNature();
    std::string getNatureString();
    u8 getMintedNature();
    std::string getMintedNatureString();
    u16 getChecksum();
    bool getHasValidChecksum();
    bool getIsEgg();
    bool getIsValid();
    u8 getCurrentHandler();
    u8 getHTFriendship();
    u8 getOTFriendship();
    u8 getCurrentFriendship();
    enums::Gender getOTGender();
    std::string getOTGenderString();
    u64 getRaidSeed();
    std::future<u64> getRaidSeedAsync();
    u16 getForm();

   private:
    u8 *m_data = new u8[0x148];
    u32 m_blockSize = 80;

    u16 calculateChecksum();
  };
}
