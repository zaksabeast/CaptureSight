#pragma once

#include <csight/Gender.hpp>
#include <csight/RaidTemplateTables.hpp>
#include <csight/Shiny.hpp>
#include <csight/lookups/Types.hpp>
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

  csight::raid::RaidEncounterTable findRaidEncounterTable(std::vector<csight::raid::RaidEncounterTable> encounterTables,
                                                          u32 denId, bool isRare);

  std::string getTypeName(type::PokemonType type);

  std::string getShinyTypeString(shiny::ShinyType type);

  std::string getGenderString(Gender gender);

  std::vector<type::TypeMultiplier> calculateWeakness(type::PokemonType type1, type::PokemonType type2);

  std::string convertFloatWithPrecision(float num, u32 precision);
}  // namespace csight::utils