#pragma once

#include <vector>
#include <switch.h>

namespace csight {
  bool checkIfServiceIsRunning(const char* serviceName);

  template <typename T>
  T getLast(std::vector<T> arr) {
    return arr[arr.size() - 1];
  }
}  // namespace csight