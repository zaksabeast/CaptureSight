#include <sstream>
#include <ios>
#include <csight/Utils.hpp>

namespace csight::utils {
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

  std::string convertNumToHexString(u32 num) {
    std::stringstream hex;
    hex << std::hex << num;

    return hex.str();
  }

  std::string convertNumToHexString(u64 num) {
    std::stringstream hex;
    hex << std::hex << num;

    return hex.str();
  }
}  // namespace csight::utils