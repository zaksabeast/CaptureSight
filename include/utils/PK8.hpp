#pragma once

#include <switch.h>
#include <string>

class PK8 {
 public:
  PK8(u8* data);
  ~PK8();

  u32 blockSize = 80;
  u32 storedSize = 0x148;
  u32 partySize = 0x158;

  void Crypt();
  u8 GetBlockPosition(u8 index);
  void ShuffleArray(u8 shuffleValue);
  u32 GetEncryptionConstant();
  u16 GetSpecies();
  bool CheckEncrypted();
  u8 GetIV(u8 stat);
  std::string GetFormattedIVs();
  bool GetIsShiny();
  u32 GetTSV();
  u32 GetPSV();
  u32 GetPID();
  u16 GetSID();
  u16 GetTID();
  u16 GetMove(u8 slot);
  u8 GetMovePP(u8 slot);

 private:
  u8* data = new u8[0x148];
};