#include <algorithm>
#include <csight/CalculateRaidSeed.hpp>
#include <csight/Gender.hpp>
#include <csight/PK8.hpp>
#include <csight/PKM.hpp>
#include <csight/RNG.hpp>
#include <csight/Utils.hpp>
#include <csight/lookups/Abilities.hpp>
#include <csight/lookups/Moves.hpp>
#include <csight/lookups/Natures.hpp>
#include <csight/lookups/Types.hpp>
#include <future>

namespace csight {
  PK8::PK8() : PKM::PKM() {}
  PK8::PK8(u8 *data) : PKM::PKM() {
    std::copy(data, data + m_storedSize, m_data);

    if (this->checkEncrypted()) {
      u8 shuffleValue = (this->getEC() >> 13) & 31;
      this->crypt();
      this->shuffleArray(shuffleValue);
    }
  }

  PK8::~PK8() { delete[] m_data; }

  bool PK8::checkEncrypted() { return *(u16 *)(m_data + 0x70) != 0 && *(u16 *)(m_data + 0xC0) != 0; }

  void PK8::crypt(void) {
    u16 *pkmWord;
    u32 seed = this->getEC();

    for (u32 i = 8; i < m_storedSize; i += 2) {
      seed = rng::lcrng::advance(seed);
      pkmWord = (u16 *)(m_data + i);
      *pkmWord = *pkmWord ^ (seed >> 16);
    }
  }

  u8 PK8::getBlockPosition(u8 index) {
    // clang-format off
    static constexpr u8 blocks[128] = {
        0, 1, 2, 3,
        0, 1, 3, 2,
        0, 2, 1, 3,
        0, 3, 1, 2,
        0, 2, 3, 1,
        0, 3, 2, 1,
        1, 0, 2, 3,
        1, 0, 3, 2,
        2, 0, 1, 3,
        3, 0, 1, 2,
        2, 0, 3, 1,
        3, 0, 2, 1,
        1, 2, 0, 3,
        1, 3, 0, 2,
        2, 1, 0, 3,
        3, 1, 0, 2,
        2, 3, 0, 1,
        3, 2, 0, 1,
        1, 2, 3, 0,
        1, 3, 2, 0,
        2, 1, 3, 0,
        3, 1, 2, 0,
        2, 3, 1, 0,
        3, 2, 1, 0,

        // duplicates of 0-7 to eliminate modulus
        0, 1, 2, 3,
        0, 1, 3, 2,
        0, 2, 1, 3,
        0, 3, 1, 2,
        0, 2, 3, 1,
        0, 3, 2, 1,
        1, 0, 2, 3,
        1, 0, 3, 2,
    };
    // clang-format on

    return blocks[index];
  }

  void PK8::shuffleArray(u8 shuffleValue) {
    u8 index = shuffleValue * 4;
    u8 originalData[m_partySize];

    std::copy(m_data, m_data + m_partySize, originalData);

    for (u8 block = 0; block < 4; block++) {
      u8 offset = this->getBlockPosition(index + block);
      std::copy(originalData + 8 + m_blockSize * offset, originalData + 8 + m_blockSize * offset + m_blockSize,
                m_data + 8 + m_blockSize * block);
    }
  }

  u32 PK8::getEC() { return *(u32 *)m_data; }

  u16 PK8::getSpecies() {
    if (*(u16 *)(m_data + 8) > 891) {
      return 0;
    }

    return *(u16 *)(m_data + 8);
  }

  u32 PK8::getIV32() { return *(u32 *)(m_data + 0x8C); }

  u8 PK8::getIV(u8 stat) { return (u8)((this->getIV32() >> 5 * stat) & 0x1F); }

  std::vector<u8> PK8::getIVs() {
    return {
      this->getIV(0), this->getIV(1), this->getIV(2), this->getIV(4), this->getIV(5), this->getIV(3),
    };
  }

  u8 PK8::getEV(u8 stat) { return *(u8 *)(m_data + 0x26 + stat); }

  std::vector<u8> PK8::getEVs() {
    return {
      this->getEV(0), this->getEV(1), this->getEV(2), this->getEV(4), this->getEV(5), this->getEV(3),
    };
  }

  u32 PK8::getSIDTID() { return *(u32 *)(m_data + 0xc); }

  u32 PK8::getPID() { return *(u32 *)(m_data + 0x1c); }

  u16 PK8::getMove(u8 slot) { return *(u16 *)(m_data + 0x72 + (slot * 2)); }

  std::string PK8::getMoveString(u8 slot) { return utils::getIndex(MovesList, this->getMove(slot)); }

  std::vector<u16> PK8::getMoves() {
    std::vector<u16> result;

    for (u8 i = 0; i < 4; i++) {
      result.push_back(this->getMove(i));
    }

    return result;
  }

  std::vector<std::string> PK8::getMoveStrings(u8 slot) {
    std::vector<std::string> result;

    for (u8 i = 0; i < 4; i++) {
      result.push_back(this->getMoveString(i));
    }

    return result;
  }

  u8 PK8::getMovePP(u8 slot) { return *(u16 *)(m_data + 0x7A + slot); }

  bool PK8::getIsEgg() { return this->getIsValid() && ((this->getIV32() >> 30) & 1) == 1; }

  ability::Ability PK8::getAbility() { return (ability::Ability) * (u8 *)(m_data + 0x14); }

  u8 PK8::getNature() { return *(u8 *)(m_data + 0x20); }

  std::string PK8::getNatureString() { return utils::getIndex(NatureList, this->getNature()); }

  u8 PK8::getMintedNature() { return *(u8 *)(m_data + 0x21); }

  std::string PK8::getMintedNatureString() { return utils::getIndex(NatureList, this->getMintedNature()); }

  u16 PK8::getChecksum() { return *(u16 *)(m_data + 0x6); }

  u16 PK8::calculateChecksum() {
    u16 chk = 0;

    for (u32 i = 8; i < m_storedSize; i += 2) {
      chk += *(u16 *)(m_data + i);
    }

    return chk;
  }

  bool PK8::getHasValidChecksum() { return this->getChecksum() == this->calculateChecksum(); }

  bool PK8::getIsValid() { return this->getSpecies() > 0 && this->getHasValidChecksum(); }

  u8 PK8::getCurrentHandler() { return *(u8 *)(m_data + 0xC4); }

  u8 PK8::getHTFriendship() { return *(u8 *)(m_data + 0xC8); }

  u8 PK8::getOTFriendship() { return *(u8 *)(m_data + 0x112); }

  u8 PK8::getCurrentFriendship() { return this->getCurrentHandler() == 0 ? this->getOTFriendship() : this->getHTFriendship(); }

  Gender PK8::getOTGender() {
    u8 genderByte = *(u8 *)(m_data + 0x125) >> 7;
    return genderByte < 2 ? (Gender)genderByte : Gender::Genderless;
  }

  std::string PK8::getOTGenderString() { return utils::getGenderString(this->getOTGender()); }

  u64 PK8::getRaidSeed() { return raid::calculateRaidSeed(this->getEC(), this->getPID(), this->getIVs()); }

  std::future<u64> PK8::getRaidSeedAsync() { return raid::calculateRaidSeedAsync(this->getEC(), this->getPID(), this->getIVs()); }

  // Currently stubbed
  u16 PK8::getForm() { return *(u16 *)(m_data + 0x24); }
}  // namespace csight