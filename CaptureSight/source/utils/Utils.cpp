#include <utils/Utils.hpp>

std::string joinNums(std::vector<u8> nums, std::string separator) {
  if (nums.size() == 0) {
    return "";
  }

  std::string accumulator = std::to_string(nums[0]);

  for (u32 i = 1; i < nums.size(); i++) {
    accumulator += separator + std::to_string(nums[i]);
  }

  return accumulator;
}