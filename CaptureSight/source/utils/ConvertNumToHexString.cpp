#include <utils/ConvertNumToHexString.hpp>

std::string ConvertNumToHexString(u32 num) {
  std::stringstream hex;
  hex << std::hex << num;

  return hex.str();
}

std::string ConvertNumToHexString(u64 num) {
  std::stringstream hex;
  hex << std::hex << num;

  return hex.str();
}