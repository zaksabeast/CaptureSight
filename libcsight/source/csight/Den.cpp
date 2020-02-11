#include <fstream>
#include <stdio.h>
#include <stratosphere.hpp>
#include <csight/Den.hpp>
#include <csight/RNG.hpp>
#include <csight/DenHashes.hpp>
#include <csight/Utils.hpp>

namespace csight {
  namespace raid {
    // Pass the den encounter tables to use since its responsibility is to parse the den data, not read/choose encounter tables
    Den::Den(u8* data, u8 denId, std::vector<RaidEncounterTable> encounterTables, std::shared_ptr<RaidEncounterTable> eventEncounterTable) {
      std::copy(data, data + this->size, this->data);

      this->denId = denId > DEN_LIST_SIZE ? DEN_LIST_SIZE : denId;
      RaidEncounter spawn;

      if (this->GetIsEvent()) {
        spawn = this->FindSpawn(eventEncounterTable->templates);
      } else {
        auto isRare = this->GetIsRare();
        auto denHash = denHashes[denId][isRare];
        auto nest = std::find_if(encounterTables.begin(), encounterTables.end(),
                                 [denHash](const raid::RaidEncounterTable& encounterTable) { return encounterTable.hash == denHash; });
        spawn = this->FindSpawn(nest->templates);
      }

      this->species = spawn.species;
      this->flawlessIVs = spawn.flawlessIVs;
    }

    Den::~Den() { delete[] this->data; }

    u64 Den::GetSeed() { return *(u64*)(this->data + 0x8); }

    u16 Den::GetShinyFrame() {
      u64 seed = this->GetSeed();
      u16 ShinyFrame = 0;
      while (ShinyFrame < 9999) {
        auto rng = rng::xoroshiro(seed);
        seed = rng.nextulong();  // Also advance for EC
        u32 TID = rng.nextuint();
        u32 PID = rng.nextuint();
        auto XOR = (TID & 0xFFFF) ^ (TID >> 16) ^ (PID & 0xFFFF) ^ (PID >> 16);
        if (XOR < 16)
          return ShinyFrame;
        else
          ShinyFrame++;
      }
      return ShinyFrame;
    }

    u8 Den::GetStars() { return *(u8*)(this->data + 0x10); }

    u8 Den::GetDisplayStars() { return this->GetStars() + 1; }

    u8 Den::GetRandRoll() { return *(u8*)(this->data + 0x11); }

    u8 Den::GetType() { return *(u8*)(this->data + 0x12); }

    bool Den::GetIsRare() {
      u8 type = this->GetType();
      return type > 0 && (type & 1) == 0;
    }

    u64 Den::GetDenHash(u8 denId, bool isRare, bool isEvent) { return isEvent ? eventHash : denHashes[denId][isRare]; }

    u8 Den::GetFlagByte() { return *(u8*)(this->data + 0x13); }

    bool Den::GetHasWatts() { return (this->GetFlagByte() & 1) == 0; }

    bool Den::GetIsEvent() { return (this->GetFlagByte() >> 1) & 1; }

    bool Den::GetIsActive() { return this->GetType() > 0; }

    u8 Den::GetDenId() { return this->denId; }

    std::shared_ptr<raid::RaidPokemon> Den::GetPKM() {
      return std::make_shared<raid::RaidPokemon>(this->GetSeed(), this->flawlessIVs, this->species);
    };

    raid::RaidEncounter Den::FindSpawn(std::vector<raid::RaidEncounter> raidEncounters) {
      u32 userProbability = 0;
      auto stars = this->GetStars();
      auto randRoll = this->GetRandRoll();

      for (auto raidEncounter : raidEncounters) {
        auto nestProbability = raidEncounter.probabilities[stars];
        userProbability += nestProbability;

        if (userProbability > randRoll) {
          return raidEncounter;
        }
      }

      return {species : 0, flawlessIVs : 1, probabilities : {0, 0, 0, 0, 0}};
    }
  }  // namespace raid
}  // namespace csight