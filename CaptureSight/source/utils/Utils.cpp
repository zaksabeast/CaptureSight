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

// Thanks to https://github.com/WerWolv/EdiZon/blob/44a30ce9ad2571f46c3e420faec44d573a27ebbc/source/helpers/util.c#L31-L42
bool checkIfServiceIsRunning(const char* serviceName) {
  Handle handle;
  SmServiceName service_name = smEncodeName(serviceName);
  bool running = R_FAILED(smRegisterService(&handle, service_name, false, 1));

  svcCloseHandle(handle);

  if (!running)
    smUnregisterService(service_name);

  return running;
}