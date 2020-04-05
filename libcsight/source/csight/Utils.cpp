#include <csight/Config.hpp>
#include <csight/DenHashes.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <csight/Utils.hpp>
#include <csight/lookups/Species.hpp>
#include <csight/lookups/Types.hpp>
#include <iomanip>
#include <ios>
#include <sstream>

// clang-format off
std::vector<std::vector<float>> weaknessChart = {
                // Defense
/* Offsense */  { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1   },
                { 1,   1,   2,   1,   1,   1,   1,   1,   0,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1   },
                { 1,   1,   1,   2,   1,   1,   0.5, 0.5, 1,   1,   1,   1,   1,   1,   2,   1,   1,   0.5, 2   },
                { 1,   1,   0.5, 1,   1,   0,   2,   0.5, 1,   1,   1,   1,   0.5, 2,   1,   2,   1,   1,   1   },
                { 1,   1,   0.5, 1,   0.5, 2,   1,   0.5, 1,   1,   1,   1,   0.5, 1,   2,   1,   1,   1,   0.5 },
                { 1,   1,   1,   1,   0.5, 1,   0.5, 1,   1,   1,   1,   2,   2,   0,   1,   2,   1,   1,   1   },
                { 1,   0.5, 2,   0.5, 0.5, 2,   1,   1,   1,   2,   0.5, 2,   2,   1,   1,   1,   1,   1,   1   },
                { 1,   1,   0.5, 2,   1,   0.5, 2,   1,   1,   1,   2,   1,   0.5, 1,   1,   1,   1,   1,   1   },
                { 1,   0,   0,   1,   0.5, 1,   1,   0.5, 2,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1   },
                { 1,   0.5, 2,   0.5, 0,   2,   0.5, 0.5, 1,   0.5, 2,   1,   0.5, 1,   0.5, 0.5, 0.5, 1,   0.5 },
                { 1,   1,   1,   1,   1,   2,   2,   0.5, 1,   0.5, 0.5, 2,   0.5, 1,   1,   0.5, 1,   1,   0.5 },
                { 1,   1,   1,   1,   1,   1,   1,   1,   1,   0.5, 0.5, 0.5, 2,   2,   1,   0.5, 1,   1,   1   },
                { 1,   1,   1,   2,   2,   0.5, 1,   2,   1,   1,   2,   0.5, 0.5, 0.5, 1,   2,   1,   1,   1   },
                { 1,   1,   1,   0.5, 1,   2,   1,   1,   1,   0.5, 1,   1,   1,   0.5, 1,   1,   1,   1,   1   },
                { 1,   1,   0.5, 1,   1,   1,   1,   2,   2,   1,   1,   1,   1,   1,   0.5, 1,   1,   2,   1   },
                { 1,   1,   2,   1,   1,   1,   2,   1,   1,   2,   2,   1,   1,   1,   1,   0.5, 1,   1,   1   },
                { 1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   0.5, 0.5, 0.5, 0.5, 1,   2,   2,   1,   2   },
                { 1,   1,   2,   1,   1,   1,   1,   0.5, 0.5, 1,   1,   1,   1,   1,   0,   1,   1,   0.5, 2   },
                { 1,   1,   0.5, 1,   2,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   0,   0.5, 1   },
};
// clang-format on

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

  std::string getTypeName(type::PokemonType type) { return getIndex(type::TypeNames, type); }

  std::vector<type::TypeMultiplier> calculateWeakness(type::PokemonType type1, type::PokemonType type2) {
    auto type1Weaknesses = weaknessChart[type1];
    auto type2Weaknesses = weaknessChart[type2];
    std::vector<type::TypeMultiplier> result = {};

    for (u8 i = 0; i < type1Weaknesses.size(); i++) {
      auto type1Multiplier = type1Weaknesses[i];
      auto type2Multiplier = type2Weaknesses[i];
      auto multiplier = type1Multiplier * type2Multiplier;

      if (multiplier != 1) {
        result.push_back({ (type::PokemonType)i, multiplier });
      }
    }

    return result;
  };

  std::string convertFloatWithPrecision(float num, u32 precision) {
    std::stringstream result;
    result << std::fixed << std::setprecision(precision) << num;

    return result.str();
  }
}  // namespace csight::utils