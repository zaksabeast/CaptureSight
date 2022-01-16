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
}
