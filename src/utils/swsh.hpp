#pragma once

#include "./debug.hpp"
#include "./general.hpp"
#include <csight-core.h>

namespace swsh {
  namespace utils {
    std::shared_ptr<::utils::TrainerInfo> read_trainer_info() {
      u32 sidtid = dbg::ReadCheatProcessHeap<u32>(swsh::BlockOffset::MyStatus8 + swsh::MyStatus8Offset::SidTid);
      return ::utils::get_trainer_info(sidtid);
    }

    std::shared_ptr<csight::Pkx> read_party_pokemon(size_t index) {
      u64 address = dbg::GetHeapAddress(swsh::Pk8Offset::Party + (index * 0x158));
      return ::utils::read_pkx(address);
    }
  }
}
