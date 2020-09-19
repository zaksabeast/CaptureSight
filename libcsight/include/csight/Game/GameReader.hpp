#pragma once

#include "../../../../Atmosphere-libs/libstratosphere/source/dmnt/dmntcht.h"
#include <csight/PKM/PKM.hpp>
#include <csight/TitleIds.hpp>
#include <csight/Utils.hpp>
#include <switch.h>
#include <vector>

namespace csight::game {
  template <class PKMType>
  class GameReader {
   public:
    GameReader(bool shouldUseSmallMemoryMode) { m_isDebugServiceRunning = utils::checkIfServiceIsRunning("dmnt:cht"); }

    Result attach() { return dmntchtGetCheatProcessMetadata(&m_metadata); }

    bool getIsPokemonRunning() { return (m_metadata.title_id == SWORD_TITLE_ID) || (m_metadata.title_id == SHIELD_TITLE_ID); }

    bool getIsServiceRunning() { return m_isDebugServiceRunning; }

    u64 getTitleId() { return m_metadata.title_id; }

    virtual std::vector<std::shared_ptr<PKMType>> readBoxes() = 0;
    virtual std::vector<std::shared_ptr<PKMType>> readParty() = 0;
    virtual std::shared_ptr<PKMType> readWild() = 0;
    virtual u32 getTrainerSIDTID() = 0;

   protected:
    Result readHeap(u64 offset, void *buffer, size_t size) {
      return dmntchtReadCheatProcessMemory(m_metadata.heap_extents.base + offset, buffer, size);
    }

    std::shared_ptr<PKMType> readPKM(u64 offset, u32 pkmSize) {
      u8 *pkmBytes = new u8[pkmSize];

      this->readHeap(offset, pkmBytes, pkmSize);
      auto pkm = std::make_shared<PKMType>(pkmBytes);

      delete[] pkmBytes;

      return pkm->getIsValid() ? pkm : std::make_shared<PKMType>();
    }

    std::vector<std::shared_ptr<PKMType>> readPKMs(u64 offset, u32 amount, u32 pkmSize) {
      std::vector<std::shared_ptr<PKMType>> pk8s;
      u32 size = pkmSize * amount;
      u8 *pkmBytes = new u8[size];

      this->readHeap(offset, pkmBytes, size);

      for (u32 i = 0; i < amount; i++) {
        pk8s.push_back(std::make_shared<PKMType>(pkmBytes + (i * pkmSize)));
      }

      delete[] pkmBytes;

      return pk8s;
    }

   private:
    bool m_isDebugServiceRunning = false;
    DmntCheatProcessMetadata m_metadata;
  };
}
