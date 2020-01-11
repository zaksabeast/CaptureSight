#include <fstream>
#include <stdio.h>
#include <utils/Den.hpp>
#include <utils/RNG.hpp>
#include <stratosphere.hpp>
#include <utils/DenHashes.hpp>
#include <utils/Utils.hpp>

Den::Den(u8* data, u8 denId, bool isSword) {
  std::copy(data, data + this->size, this->data);
  this->denId = denId > DEN_LIST_SIZE ? DEN_LIST_SIZE : denId;
  auto denHash = this->GetDenHash(this->denId - 1, this->GetIsRare(), this->GetIsEvent());
  auto nests = isSword ? swordNests : shieldNests;
  auto nest = std::find_if(nests.begin(), nests.end(), [denHash](const RaidTemplateTable& nest) { return nest.hash == denHash; });
  auto spawn = this->FindSpawn(nest->templates);

  this->species = spawn.species;
  this->flawlessIVs = spawn.flawlessIVs;
}

Den::~Den() {
  delete[] this->data;
}

u64 Den::GetSeed() {
  return *(u64*)(this->data + 0x8);
}

u16 Den::GetShinyFrame() {
  u64 seed = this->GetSeed();
  u16 ShinyFrame = 0;
  while (ShinyFrame < 9999) {
    auto rng = rng::xoroshiro(seed);
    seed = rng.nextulong();   // Also advance for EC
    uint TID = rng.nextuint();
    uint PID = rng.nextuint();
    auto XOR = (TID & 0xFFFF) ^ (TID >> 16) ^ (PID & 0xFFFF) ^ (PID >> 16);
    if (XOR < 16)
      return ShinyFrame;
    else
      ShinyFrame++;
  }
  return ShinyFrame;
}

u8 Den::GetStars() {
  return *(u8*)(this->data + 0x10);
}

u8 Den::GetDisplayStars() {
  return this->GetStars() + 1;
}

u8 Den::GetRandRoll() {
  return *(u8*)(this->data + 0x11);
}

u8 Den::GetType() {
  return *(u8*)(this->data + 0x12);
}

bool Den::GetIsRare() {
  u8 type = this->GetType();
  return type > 0 && (type & 1) == 0;
}

u64 Den::GetDenHash(u8 denId, bool isRare, bool isEvent) {
  return isEvent ? eventHash : denHashes[denId][isRare];
}

u8 Den::GetFlagByte() {
  return *(u8*)(this->data + 0x13);
}

bool Den::GetHasWatts() {
  return (this->GetFlagByte() & 1) == 0;
}

bool Den::GetIsEvent() {
  return (this->GetFlagByte() >> 1) & 1;
}

bool Den::GetIsActive() {
  return this->GetType() > 0;
}

u8 Den::GetDenId() {
  return this->denId;
}

std::shared_ptr<RaidPokemon> Den::GetPKM() {
  return std::make_shared<RaidPokemon>(this->GetSeed(), this->flawlessIVs, this->species);
};

RaidTemplate Den::FindSpawn(std::vector<RaidTemplate> templates) {
  u32 probability = 0;
  u32 nestProbability = 0;
  auto stars = this->GetStars();
  auto randRoll = this->GetRandRoll();

  for (u32 index = 0; index < templates.size(); index++) {
    nestProbability = templates[index].probabilities[stars];
    probability += nestProbability;

    if (probability > randRoll) {
      return templates[index];
    }
  }

  return getLast(templates);
}
