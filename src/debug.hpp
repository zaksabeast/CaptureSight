#pragma once

#include <array>
#include <cstring>
#include <dmntcht.h>
#include <functional>

DmntCheatProcessMetadata g_metadata;

namespace dbg {
  Result Initialize() {
    dmntchtInitialize();
    return dmntchtGetCheatProcessMetadata(&g_metadata);
  }

  void Exit() { dmntchtExit(); }

  u64 GetCheatProcessTitleId() { return g_metadata.title_id; }

  std::array<u8, 32> GetCheatProcessBuildId() {
    std::array<u8, 32> build_id = { 0 };
    memcpy(build_id.data(), g_metadata.main_nso_build_id, 32);
    return build_id;
  }

  template <size_t const DATA_SIZE>
  std::array<u8, DATA_SIZE> ReadCheatProcessHeap(u64 offset) {
    std::array<u8, DATA_SIZE> result = { 0 };
    u64 address = g_metadata.heap_extents.base + offset;
    dmntchtReadCheatProcessMemory(address, (void *)result.data(), DATA_SIZE);
    return result;
  }
}
