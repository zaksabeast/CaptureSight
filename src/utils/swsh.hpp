#pragma once

#include "./debug.hpp"
#include "./general.hpp"
#include <csight-core.h>

namespace swsh {
  namespace utils {
    struct TrainerInfo {
      u16 sid;
      u16 tid;
    };

    std::shared_ptr<TrainerInfo> read_trainer_info() {
      u32 sidtid = dbg::ReadCheatProcessHeap<u32>(swsh::BlockOffset::MyStatus8 + swsh::MyStatus8Offset::SidTid);

      return std::make_shared<TrainerInfo>(TrainerInfo {
        sid : (u16)(sidtid >> 16),
        tid : (u16)sidtid,
      });
    }

    std::shared_ptr<csight::Pkx> read_party_pokemon(size_t index) {
      u64 address = dbg::GetHeapAddress(swsh::Pk8Offset::Party + (index * 0x158));
      return ::utils::read_pkx(address);
    }
  }
}
