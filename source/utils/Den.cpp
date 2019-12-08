#include <utils/Den.hpp>

u8 Den::GetStars(u8 denId) {
  u8 stars = 0;

  this->ReadDenOffset(0x70 + denId * 0x18, &stars, 1);
  return stars;
}

u8 Den::GetRarity(u8 denId) {
  u8 rarity = 0;

  this->ReadDenOffset(0x72 + denId * 0x18, &rarity, 1);
  return rarity;
}

bool Den::GetWattFlag(u8 denId) {
  u8 wattFlag = 0;

  this->ReadDenOffset(0x73 + denId * 0x18, &wattFlag, 1);
  return wattFlag & 1;
}

Result Den::ReadDenOffset(u64 offset, void* buffer, size_t size) {
  return this->ReadHeap(this->denOffset + offset, buffer, size);
}