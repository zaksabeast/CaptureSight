#include <fstream>
#include <stdio.h>
#include <stratosphere.hpp>
#include <csight/Den.hpp>
#include <csight/RNG.hpp>
#include <csight/DenHashes.hpp>
#include <csight/Utils.hpp>
#include <csight/Config.hpp>

namespace csight::raid {
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
                               [denHash](const RaidEncounterTable& encounterTable) { return encounterTable.hash == denHash; });
      spawn = this->FindSpawn(nest->templates);
    }

    this->species = spawn.species;
    this->flawlessIVs = spawn.flawlessIVs;
    this->CalculateShinyDetails();
  }

  Den::~Den() { delete[] this->data; }

  u64 Den::GetSeed() { return *(u64*)(this->data + 0x8); }

  u16 Den::GetShinyFrame() { return this->shinyFrame; }

  std::string Den::GetShinyFrameText() { return utils::getRaidShinyFrameText(this->shinyFrame); }

  shiny::ShinyType Den::GetShineType() { return this->shineType; }

  void Den::CalculateShinyDetails() {
    u64 seed = this->GetSeed();
    u16 shinyFrame = 0;
    shiny::ShinyType shineType = shiny::None;

    while (shinyFrame < MAX_DEN_SHINY_FRAME) {
      auto rng = rng::xoroshiro(seed);
      seed = rng.nextulong();  // Also advance for EC
      u32 SIDTID = rng.nextuint();
      u32 PID = rng.nextuint();
      shineType = shiny::GetShinyType(PID, SIDTID);
      if (shineType > shiny::None)
        break;
      else
        shinyFrame++;
    }

    this->shinyFrame = shinyFrame;
    this->shineType = shineType;
  }

  u8 Den::GetStars() { return *(u8*)(this->data + 0x10); }

  u8 Den::GetDisplayStars() { return this->GetStars() + 1; }

  u8 Den::GetRandRoll() { return *(u8*)(this->data + 0x11); }

  u8 Den::GetType() { return *(u8*)(this->data + 0x12); }

  bool Den::GetIsRare() {
    u8 type = this->GetType();
    return type > 0 && (type & 1) == 0;
  }

  u8 Den::GetFlagByte() { return *(u8*)(this->data + 0x13); }

  bool Den::GetHasWatts() { return (this->GetFlagByte() & 1) == 0; }

  bool Den::GetIsEvent() { return (this->GetFlagByte() >> 1) & 1; }

  bool Den::GetIsActive() { return this->GetType() > 0; }

  u8 Den::GetDenId() { return this->denId; }

  u8 Den::GetDenDisplayId() { return this->denId + 1; }

  std::shared_ptr<RaidPokemon> Den::GetPKM() { return std::make_shared<RaidPokemon>(this->GetSeed(), this->flawlessIVs, this->species); };

  RaidEncounter Den::FindSpawn(std::vector<RaidEncounter> raidEncounters) {
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
}  // namespace csight::raid