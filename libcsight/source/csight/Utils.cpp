#include <algorithm>
#include <csight/Enums/Ability.hpp>
#include <csight/Enums/ShinyType.hpp>
#include <csight/Enums/Types.hpp>
#include <csight/Game/SWSH/DenHashes.hpp>
#include <csight/Game/SWSH/RaidTemplateTables.hpp>
#include <csight/Resources/Abilities.hpp>
#include <csight/Resources/Species.hpp>
#include <csight/Resources/Types.hpp>
#include <csight/Utils.hpp>
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

  std::string getSpeciesName(u32 species) { return getIndex(resources::SpeciesList, species); }

  std::string getTypeName(enums::PokemonType type) { return getIndex(resources::TypeNames, type); }

  std::string getShinyTypeString(enums::ShinyType type) {
    switch (type) {
      case enums::ShinyType::None:
        return "None";
      case enums::ShinyType::Star:
        return "Star";
      case enums::ShinyType::Square:
        return "Square";
      case enums::ShinyType::Any:
      default:
        return "Any";
    }
  }

  std::string getGenderString(enums::Gender gender) {
    switch (gender) {
      case enums::Gender::Male:
        return "Male";
      case enums::Gender::Female:
        return "Female";
      case enums::Gender::Genderless:
      default:
        return "Genderless";
    }
  }

  std::vector<enums::TypeMultiplier> calculateWeakness(enums::PokemonType type1, enums::PokemonType type2) {
    auto type1Weaknesses = weaknessChart[type1];
    auto type2Weaknesses = weaknessChart[type2];
    std::vector<enums::TypeMultiplier> result = {};

    for (u8 i = 0; i < type1Weaknesses.size(); i++) {
      auto type1Multiplier = type1Weaknesses[i];
      auto type2Multiplier = type2Weaknesses[i];
      auto multiplier = type1Multiplier * type2Multiplier;

      if (multiplier != 1) {
        result.push_back({ (enums::PokemonType)i, multiplier });
      }
    }

    return result;
  };

  std::string convertFloatWithPrecision(float num, u32 precision) {
    std::stringstream result;
    result << std::fixed << std::setprecision(precision) << num;

    return result.str();
  }

  std::string getAbilityString(enums::Ability ability) {
    switch (ability) {
      case enums::Ability::Hidden:
        return "H";
      case enums::Ability::Second:
        return "2";
      default:
      case enums::Ability::First:
        return "1";
    }
  }

  u32 getShinyValue(u32 value) { return (value >> 16) ^ (value & 0xFFFF); }

  enums::ShinyType getShinyType(u32 PID, u32 SIDTID) {
    u32 PSV = getShinyValue(PID);
    u32 TSV = getShinyValue(SIDTID);

    if (PSV == TSV) {
      return enums::ShinyType::Square;
    }

    if ((PSV ^ TSV) < 0x10) {
      return enums::ShinyType::Star;
    }

    return enums::ShinyType::None;
  }

  u16 getAbilityOfPokemon(u16 species, u8 form, enums::Ability ability) {
    auto speciesAbilities = getIndex(resources::pokemonAbilityMap, species);
    auto formAbilities = getIndex(speciesAbilities, form);

    switch (ability) {
      case enums::Ability::Second:
        return formAbilities[1];
      case enums::Ability::Hidden:
        return formAbilities[2];
      default:
      case enums::Ability::First:
        return formAbilities[0];
    }
  }

  std::pair<enums::PokemonType, enums::PokemonType> getPokemonTypes(u16 species, u16 form) {
    // Arceus and Silvally have the most forms with different types at 18
    std::vector<csight::enums::PokemonTypeSet> filteredList(18);

    // Some Pokemon have the same type regardless of form, such as all the Unown or Ash Hat/Cosplay Pikachu
    // so we find the species first, then filter by form.
    // A cleaner approach would be to have a more complete list of types per form.
    auto endIterator = std::copy_if(resources::pokemonTypeMap.begin(), resources::pokemonTypeMap.end(), filteredList.begin(),
                                    [species](auto type) { return type.species == species; });

    if (endIterator == resources::pokemonTypeMap.end()) {
      return std::make_pair(enums::PokemonType::NoType, enums::PokemonType::NoType);
    }

    filteredList.resize(std::distance(filteredList.begin(), endIterator));

    auto resultIterator = std::find_if(filteredList.begin(), filteredList.end(), [form](auto type) { return type.form == form; });
    auto result = resultIterator == filteredList.end() ? filteredList[0] : resultIterator[0];

    return std::make_pair(result.type1, result.type2);
  }
}
