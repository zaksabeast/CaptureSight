#pragma once

#include <array>
#include <cstring>
#include <dmntcht.h>
#include <functional>

DmntCheatProcessMetadata g_metadata;

namespace dbg {
  Result Initialize() {
    dmntchtInitialize();
    dmntchtForceOpenCheatProcess();
    return dmntchtGetCheatProcessMetadata(&g_metadata);
  }

  void Exit() { dmntchtExit(); }

  u64 GetHeapAddress(u64 offset) { return g_metadata.heap_extents.base + offset; }

  u64 GetNsoAddress(u64 offset) { return g_metadata.main_nso_extents.base + offset; }

  u64 GetCheatProcessTitleId() { return g_metadata.title_id; }

  bool HasCheatProcess() {
    bool has_cheat_process = false;
    dmntchtHasCheatProcess(&has_cheat_process);
    return has_cheat_process;
  }

  std::array<u8, 8> GetCheatProcessBuildId() {
    std::array<u8, 8> build_id = { 0 };
    memcpy(build_id.data(), g_metadata.main_nso_build_id, 8);
    return build_id;
  }

  template <typename T, size_t const COUNT>
  std::array<T, COUNT> ReadCheatProcessArray(u64 address) {
    std::array<T, COUNT> result = { 0 };
    dmntchtReadCheatProcessMemory(address, (void *)result.data(), sizeof(T) * COUNT);
    return result;
  }

  template <size_t const DATA_SIZE>
  std::array<u8, DATA_SIZE> ReadCheatProcessHeapBytes(u64 offset) {
    u64 address = GetHeapAddress(offset);
    return ReadCheatProcessArray<u8, DATA_SIZE>(address);
  }

  template <typename T>
  T ReadCheatProcess(u64 address, T default_value = 0) {
    T result = default_value;
    dmntchtReadCheatProcessMemory(address, &result, sizeof(T));
    return result;
  }

  template <typename T>
  T ReadCheatProcessNso(u64 offset) {
    u64 address = GetNsoAddress(offset);
    return ReadCheatProcess<T>(address);
  }
}
