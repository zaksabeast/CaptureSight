#include <algorithm>
#include <utils/PK8.hpp>
#include <utils/RNG.hpp>
#include <utils/CalculateRaidSeed.hpp>

PK8::PK8(u8* data) {
  std::copy(data, data + this->storedSize, this->data);

  if (this->CheckEncrypted()) {
    u8 shuffleValue = (this->GetEncryptionConstant() >> 13) & 31;
    this->Crypt();
    this->ShuffleArray(shuffleValue);
  }
}

PK8::~PK8() {
  delete[] this->data;
}

bool PK8::CheckEncrypted() {
  return *(u16*)(this->data + 0x70) != 0 && *(u16*)(this->data + 0xC0) != 0;
}

void PK8::Crypt(void) {
  u16* pkmWord;
  u32 seed = this->GetEncryptionConstant();

  for (u32 i = 8; i < this->storedSize; i += 2) {
    seed = rng::lcrng::advance(seed);
    pkmWord = (u16*)(this->data + i);
    *pkmWord = *pkmWord ^ (seed >> 16);
  }
}

u8 PK8::GetBlockPosition(u8 index) {
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

void PK8::ShuffleArray(u8 shuffleValue) {
  u8 index = shuffleValue * 4;
  u8 originalData[this->partySize];

  std::copy(this->data, this->data + this->partySize, originalData);

  for (u8 block = 0; block < 4; block++) {
    u8 offset = this->GetBlockPosition(index + block);
    std::copy(originalData + 8 + this->blockSize * offset, originalData + 8 + this->blockSize * offset + this->blockSize,
              this->data + 8 + this->blockSize * block);
  }
}

u32 PK8::GetEncryptionConstant() {
  return *(u32*)this->data;
}

u16 PK8::GetSpecies() {
  if (*(u16*)(this->data + 8) > 891) {
    return 0;
  }

  return *(u16*)(this->data + 8);
}

u32 PK8::GetIV32() {
  return *(u32*)(this->data + 0x8C);
}

s8 PK8::GetIV(u8 stat) {
  return (s8)((this->GetIV32() >> 5 * stat) & 0x1F);
}

std::vector<s8> PK8::GetIVs() {
  return {
      this->GetIV(0), this->GetIV(1), this->GetIV(2), this->GetIV(4), this->GetIV(5), this->GetIV(3),
  };
}

u8 PK8::GetEV(u8 stat) {
  return *(u8*)(this->data + 0x26 + stat);
}

std::vector<u8> PK8::GetEVs() {
  return {
      this->GetEV(0), this->GetEV(1), this->GetEV(2), this->GetEV(4), this->GetEV(5), this->GetEV(3),
  };
}

u16 PK8::GetTID() {
  return *(u16*)(this->data + 0xc);
}

u16 PK8::GetSID() {
  return *(u16*)(this->data + 0xe);
}

u32 PK8::GetPID() {
  return *(u32*)(this->data + 0x1c);
}

u32 PK8::GetPSV() {
  u32 pid = this->GetPID();
  return ((pid >> 16 ^ (pid & 0xFFFF)) >> 4);
}

u32 PK8::GetTSV() {
  return ((this->GetTID() ^ this->GetSID()) >> 4);
}

bool PK8::GetIsShiny() {
  return this->GetPSV() == this->GetTSV();
}

u16 PK8::GetMove(u8 slot) {
  return *(u16*)(this->data + 0x72 + (slot * 2));
}

std::vector<u16> PK8::GetMoves() {
  std::vector<u16> result;

  for (u8 i = 0; i < 4; i++) {
    result.push_back(this->GetMove(i));
  }

  return result;
}

u8 PK8::GetMovePP(u8 slot) {
  return *(u16*)(this->data + 0x7A + slot);
}

bool PK8::GetIsEgg() {
  return this->GetIsValid() && ((this->GetIV32() >> 30) & 1) == 1;
}

u8 PK8::GetNature() {
  return *(u8*)(this->data + 0x20);
}

u8 PK8::GetMintedNature() {
  return *(u8*)(this->data + 0x21);
}

u16 PK8::GetChecksum() {
  return *(u16*)(this->data + 0x6);
}

u16 PK8::CalculateChecksum() {
  u16 chk = 0;

  for (u32 i = 8; i < this->storedSize; i += 2) {
    chk += *(u16*)(this->data + i);
  }

  return chk;
}

bool PK8::GetHasValidChecksum() {
  return this->GetChecksum() == this->CalculateChecksum();
}

bool PK8::GetIsValid() {
  return this->GetSpecies() > 0 && this->GetHasValidChecksum();
}

u8 PK8::GetCurrentHandler() {
  return *(u8*)(this->data + 0xC4);
}

u8 PK8::GetHTFriendship() {
  return *(u8*)(this->data + 0xC8);
}

u8 PK8::GetOTFriendship() {
  return *(u8*)(this->data + 0x112);
}

u8 PK8::GetCurrentFriendship() {
  return this->GetCurrentHandler() == 0 ? this->GetOTFriendship() : this->GetHTFriendship();
}

ulong PK8::GetRaidSeed() {
  return raid::CalculateRaidSeed(this->GetEncryptionConstant(), this->GetPID(), this->GetIVs());
}