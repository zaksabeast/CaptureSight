#include <csight/Game/SWSH/DenHashes.hpp>
#include <csight/Game/SWSH/RaidTemplateTables.hpp>
#include <vector>

namespace csight::game::swsh {
  RaidEncounterTable findRaidEncounterTable(std::vector<RaidEncounterTable> encounterTables, u32 denId, bool isRare) {
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
}
