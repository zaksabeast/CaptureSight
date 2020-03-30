#include <csight/Config.hpp>
#include <csight/DenHashes.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <csight/Utils.hpp>
#include <csight/lookups/Species.hpp>
#include <ios>
#include <sstream>

namespace csight::utils {
  // Thanks to https://github.com/WerWolv/EdiZon/blob/44a30ce9ad2571f46c3e420faec44d573a27ebbc/source/helpers/util.c#L31-L42
  bool checkIfServiceIsRunning(const char *serviceName) {
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

  std::string getRaidShinyAdvanceText(u32 shinyAdvance, u32 maxAdvance) {
    std::string maxAdvanceString = maxAdvance >= 1000 ? std::to_string(maxAdvance / 1000) + "K+" : "<1K";
    return shinyAdvance == maxAdvance ? maxAdvanceString : std::to_string(shinyAdvance);
  }

  std::string getSpeciesName(u32 species) { return getIndex(SpeciesList, species); }

  csight::raid::RaidEncounterTable findRaidEncounterTable(std::vector<csight::raid::RaidEncounterTable> encounterTables,
                                                          u32 denId, bool isRare) {
    auto denHash = denId > DEN_LIST_SIZE ? denHashes[0][isRare] : denHashes[denId][isRare];
    auto nest = encounterTables[0];

    for (auto encounterTable : encounterTables) {
      if (encounterTable.hash == denHash) {
        nest = encounterTable;
        break;
      }
    }

    return nest;
  }
}  // namespace csight::utils