#include <utils/Den.hpp>
#include <stratosphere.hpp>

Den::Den(u8* data, u8 denId) {
  std::copy(data, data + this->size, this->data);
  this->denId = denId;
}

Den::~Den() {
  delete[] this->data;
}

u64 Den::GetSeed() {
  return *(u64*)(this->data + 0x8);
}

u8 Den::GetStars() {
  return *(u8*)(this->data + 0x10) + 1;
}

u8 Den::GetRandRoll() {
  return *(u8*)(this->data + 0x11);
}

u8 Den::GetType() {
  return *(u8*)(this->data + 0x12);
}

bool Den::GetIsActive() {
  return this->GetType() > 0;
}

u8 Den::GetDenId() {
  return this->denId;
}

std::shared_ptr<Den> RaidDetails::ReadDen(u8 denId) {
  u8* denBytes = new u8[0x18];

  this->ReadHeap(this->denOffset + (denId * 0x18), denBytes, 0x18);

  auto den = std::make_shared<Den>(denBytes, denId);

  delete[] denBytes;
  return den;
}

std::vector<std::shared_ptr<Den>> RaidDetails::ReadDens(bool shouldReadAllDens) {
  std::vector<std::shared_ptr<Den>> dens;

  for (u32 i = 0; i < 100; i++) {
    auto den = this->ReadDen(i);
    if (shouldReadAllDens || den->GetIsActive()) {
      dens.push_back(den);
    }
  }

  return dens;
}
