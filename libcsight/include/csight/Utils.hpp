#pragma once

#include <csight/Enums/Ability.hpp>
#include <csight/Enums/Gender.hpp>
#include <csight/Enums/ShinyType.hpp>
#include <csight/Enums/Types.hpp>
#include <future>
#include <string>
#include <switch.h>
#include <vector>

namespace csight::utils {
  std::string convertNumToHexString(u32 num);
  std::string convertNumToHexString(u64 num);

  bool checkIfServiceIsRunning(const char *serviceName);

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
  bool waitingInterval(std::future<T> *toWait, int interval_ms) {
    return toWait->wait_for(std::chrono::milliseconds(interval_ms)) == std::future_status::timeout;
  }

  std::string getRaidShinyAdvanceText(u32 shinyAdvance, u32 maxAdvance);

  std::string getSpeciesName(u32 species);

  std::string getTypeName(enums::PokemonType type);

  std::string getShinyTypeString(enums::ShinyType type);

  std::string getGenderString(enums::Gender gender);

  std::vector<enums::TypeMultiplier> calculateWeakness(enums::PokemonType type1, enums::PokemonType type2);

  std::string convertFloatWithPrecision(float num, u32 precision);

  std::string getAbilityString(enums::Ability ability);

  u32 getShinyValue(u32 value);

  enums::ShinyType getShinyType(u32 PID, u32 SIDTID);

  u16 getAbilityOfPokemon(u16 species, u8 form, enums::Ability ability);
}
