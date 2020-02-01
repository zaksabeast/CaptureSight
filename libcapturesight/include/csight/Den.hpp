#pragma once

#include <memory>
#include <vector>
#include <switch.h>
#include <stratosphere.hpp>
#include <csight/RaidPokemon.hpp>
#include <csight/RaidTemplateTables.hpp>

namespace csight {
  class Den {
   public:
    Den(u8* data, u8 denId, bool isSword);
    ~Den();
    u64 GetSeed();
    u16 GetShinyFrame();
    u8 GetStars();
    u8 GetDisplayStars();
    u8 GetRandRoll();
    u8 GetType();
    u8 GetFlagByte();
    bool GetHasWatts();
    bool GetIsEvent();
    bool GetIsActive();
    u8 GetDenId();
    bool GetIsRare();
    u64 GetDenHash(u8 denId, bool isRare, bool isEvent);
    std::shared_ptr<raid::RaidPokemon> GetPKM();

   private:
    u8 size = 0x18;
    u8* data = new u8[0x18];
    u8 denId = 0;
    u16 species = 0;
    u8 flawlessIVs = 0;
    raid::RaidTemplate FindSpawn(std::vector<raid::RaidTemplate> templates);
  };
}  // namespace csight
