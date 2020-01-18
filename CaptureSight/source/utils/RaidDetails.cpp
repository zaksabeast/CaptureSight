#include <utils/RaidDetails.hpp>
#include <TitleIds.hpp>

u8 GetDenReadId(u8 denId) {
  // Dens are zero-indexed in memory, but we omit 16 since it's for special encounters
  // This is for consistency with the PKHeX Raid Plugin and RaidFinder
  return denId > 16 ? denId : denId - 1;
}

std::shared_ptr<Den> RaidDetails::ReadDen(u8 denId) {
  u8* denBytes = new u8[0x18];
  u8 readId = GetDenReadId(denId);
  bool isPlayingSword = this->GetTitleId() == SWORD_TITLE_ID;

  this->ReadHeap(this->denOffset + (readId * 0x18), denBytes, 0x18);

  auto den = std::make_shared<Den>(denBytes, denId, isPlayingSword);

  delete[] denBytes;
  return den;
}

std::vector<std::shared_ptr<Den>> RaidDetails::ReadDens(bool shouldReadAllDens) {
  std::vector<std::shared_ptr<Den>> dens;

  // We don't treat den Ids as zero-indexed for consistency with the PKHeX Raid Plugin and RaidFinder
  for (u32 i = 1; i < 100; i++) {
    auto den = this->ReadDen(i);
    if (shouldReadAllDens || den->GetIsActive()) {
      dens.push_back(den);
    }
  }

  return dens;
}
