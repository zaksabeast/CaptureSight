#pragma once

#include "./debug.hpp"
#include "./general.hpp"
#include <csight-core.h>

namespace swsh {
  namespace utils {
    std::shared_ptr<csight::Pkx> read_party_pokemon(size_t index) {
      u64 address = dbg::GetHeapAddress(swsh::Pk8Offset::Party + (index * 0x158));
      return ::utils::read_pkx(address);
    }
  }
}
