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

  void GetCheatProcessMetadata(DmntCheatProcessMetadata *metadata) { *metadata = g_metadata; }

  u64 GetCheatProcessHeapBase() { return g_metadata.heap_extents.base; }

  u64 GetCheatProcessNsoBase() { return g_metadata.main_nso_extents.base; }

  u64 GetCheatProcessTitleId() { return g_metadata.title_id; }

  std::array<u8, 32> GetCheatProcessBuildId() {
    std::array<u8, 32> build_id = { 0 };
    memcpy(build_id.data(), g_metadata.main_nso_build_id, 32);
    return build_id;
  }

  template <size_t const DATA_SIZE>
  std::array<u8, DATA_SIZE> ReadCheatProcessNso(u64 offset) {
    std::array<u8, DATA_SIZE> result = { 0 };
    u64 address = GetCheatProcessNsoBase() + offset;
    dmntchtReadCheatProcessMemory(address, (void *)result.data(), DATA_SIZE);

    return result;
  }

  Result WriteCheatProcessNso(u64 offset, const void *buffer, size_t size) {
    u64 address = GetCheatProcessNsoBase() + offset;
    return dmntchtWriteCheatProcessMemory(address, buffer, size);
  }

  template <size_t const DATA_SIZE>
  std::array<u8, DATA_SIZE> ReadCheatProcessHeap(u64 offset) {
    std::array<u8, DATA_SIZE> result = { 0 };
    u64 address = GetCheatProcessHeapBase() + offset;
    dmntchtReadCheatProcessMemory(address, (void *)result.data(), DATA_SIZE);

    return result;
  }

  Result WriteCheatProcessHeap(u64 offset, const void *buffer, size_t size) {
    u64 address = GetCheatProcessHeapBase() + offset;
    return dmntchtWriteCheatProcessMemory(address, buffer, size);
  }

  Result PauseCheatProcess() { return dmntchtPauseCheatProcess(); }

  Result UnpauseCheatProcess() { return dmntchtResumeCheatProcess(); }
}
