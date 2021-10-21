#pragma once

#include <csight-core.h>
#include <iomanip>
#include <memory>
#include <string>
#include <switch.h>

namespace utils {
  template <typename T>
  std::string num_to_hex(T num) {
    std::stringstream stream;
    stream << std::hex << num;
    return stream.str();
  }

  template <typename T>
  std::string join(std::vector<T> items, std::string separator) {
    if (items.size() == 0) {
      return "";
    }

    std::string accumulator = std::to_string(items[0]);

    for (u32 i = 1; i < items.size(); i++) {
      accumulator += separator + std::to_string(items[i]);
    }

    return accumulator;
  }

  // Thanks to https://github.com/WerWolv/EdiZon/blob/44a30ce9ad2571f46c3e420faec44d573a27ebbc/source/helpers/util.c#L31-L42
  bool check_if_service_is_running(const char *serviceName) {
    Handle handle;
    SmServiceName service_name = smEncodeName(serviceName);
    bool running = R_FAILED(smRegisterService(&handle, service_name, false, 1));

    svcCloseHandle(handle);

    if (!running)
      smUnregisterService(service_name);

    return running;
  }

  std::shared_ptr<csight::Pkx> read_pkx(u64 offset) {
    auto ek8 = dbg::ReadCheatProcessHeap<csight::Pk8::StoredSize>(offset);
    return std::make_shared<csight::Pk8>(ek8);
  }
}
