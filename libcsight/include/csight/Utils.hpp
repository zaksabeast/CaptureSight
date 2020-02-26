#pragma once

#include <vector>
#include <string>
#include <switch.h>

namespace csight::utils {
  std::string convertNumToHexString(u32 num);
  std::string convertNumToHexString(u64 num);

  bool checkIfServiceIsRunning(const char* serviceName);

  template <typename T>
  T getIndex(std::vector<T> arr, size_t index) {
    if (index > arr.size()) {
      return arr[0];
    }

    return arr[index];
  }

  template <typename T>
  std::string joinNums(std::vector<T> nums, std::string separator) {
    if (nums.size() == 0) {
      return "";
    }

    std::string accumulator = std::to_string(nums[0]);

    for (u32 i = 1; i < nums.size(); i++) {
      accumulator += separator + std::to_string(nums[i]);
    }

    return accumulator;
  }

  template <typename T>
  bool waitingInterval(std::future<T>* toWait, int interval_ms) {
    return toWait->wait_for(std::chrono::milliseconds(interval_ms)) == std::future_status::timeout;
  }

  std::string getRaidShinyFrameText(u32 shinyFrame);
}  // namespace csight::utils