#include <algorithm>
#include <csight/Enums/Types.hpp>
#include <csight/Game/SWSH/DmaxAdventure.hpp>
#include <csight/RNG/MersenneTwister.hpp>
#include <csight/RNG/RNG.hpp>
#include <csight/Utils.hpp>
#include <iostream>
#include <memory>
#include <numeric>
#include <stdint.h>
#include <switch.h>
#include <vector>

namespace csight::game::swsh {
  const std::vector<DmaxAdventureTemplate> DMAX_ADVENTURE_TEMPLATES
      = { { species : 2, altForm : 0, isBoss : false },   { species : 5, altForm : 0, isBoss : false },
          { species : 8, altForm : 0, isBoss : false },   { species : 12, altForm : 0, isBoss : false },
          { species : 26, altForm : 0, isBoss : false },  { species : 26, altForm : 1, isBoss : false },
          { species : 28, altForm : 0, isBoss : false },  { species : 28, altForm : 1, isBoss : false },
          { species : 31, altForm : 0, isBoss : false },  { species : 34, altForm : 0, isBoss : false },
          { species : 35, altForm : 0, isBoss : false },  { species : 737, altForm : 0, isBoss : false },
          { species : 743, altForm : 0, isBoss : false }, { species : 40, altForm : 0, isBoss : false },
          { species : 553, altForm : 0, isBoss : false }, { species : 45, altForm : 0, isBoss : false },
          { species : 51, altForm : 0, isBoss : false },  { species : 51, altForm : 1, isBoss : false },
          { species : 53, altForm : 0, isBoss : false },  { species : 53, altForm : 1, isBoss : false },
          { species : 55, altForm : 0, isBoss : false },  { species : 62, altForm : 0, isBoss : false },
          { species : 64, altForm : 0, isBoss : false },  { species : 67, altForm : 0, isBoss : false },
          { species : 745, altForm : 0, isBoss : false }, { species : 745, altForm : 1, isBoss : false },
          { species : 82, altForm : 0, isBoss : false },  { species : 752, altForm : 0, isBoss : false },
          { species : 754, altForm : 0, isBoss : false }, { species : 93, altForm : 0, isBoss : false },
          { species : 869, altForm : 0, isBoss : false }, { species : 99, altForm : 0, isBoss : false },
          { species : 105, altForm : 0, isBoss : false }, { species : 105, altForm : 1, isBoss : false },
          { species : 106, altForm : 0, isBoss : false }, { species : 107, altForm : 0, isBoss : false },
          { species : 108, altForm : 0, isBoss : false }, { species : 110, altForm : 0, isBoss : false },
          { species : 110, altForm : 1, isBoss : false }, { species : 112, altForm : 0, isBoss : false },
          { species : 113, altForm : 0, isBoss : false }, { species : 114, altForm : 0, isBoss : false },
          { species : 115, altForm : 0, isBoss : false }, { species : 117, altForm : 0, isBoss : false },
          { species : 119, altForm : 0, isBoss : false }, { species : 122, altForm : 0, isBoss : false },
          { species : 122, altForm : 1, isBoss : false }, { species : 123, altForm : 0, isBoss : false },
          { species : 124, altForm : 0, isBoss : false }, { species : 125, altForm : 0, isBoss : false },
          { species : 126, altForm : 0, isBoss : false }, { species : 756, altForm : 0, isBoss : false },
          { species : 128, altForm : 0, isBoss : false }, { species : 148, altForm : 0, isBoss : false },
          { species : 164, altForm : 0, isBoss : false }, { species : 171, altForm : 0, isBoss : false },
          { species : 176, altForm : 0, isBoss : false }, { species : 178, altForm : 0, isBoss : false },
          { species : 182, altForm : 0, isBoss : false }, { species : 184, altForm : 0, isBoss : false },
          { species : 185, altForm : 0, isBoss : false }, { species : 186, altForm : 0, isBoss : false },
          { species : 195, altForm : 0, isBoss : false }, { species : 206, altForm : 0, isBoss : false },
          { species : 211, altForm : 0, isBoss : false }, { species : 758, altForm : 0, isBoss : false },
          { species : 215, altForm : 0, isBoss : false }, { species : 221, altForm : 0, isBoss : false },
          { species : 760, altForm : 0, isBoss : false }, { species : 763, altForm : 0, isBoss : false },
          { species : 224, altForm : 0, isBoss : false }, { species : 226, altForm : 0, isBoss : false },
          { species : 227, altForm : 0, isBoss : false }, { species : 237, altForm : 0, isBoss : false },
          { species : 241, altForm : 0, isBoss : false }, { species : 764, altForm : 0, isBoss : false },
          { species : 264, altForm : 0, isBoss : false }, { species : 264, altForm : 1, isBoss : false },
          { species : 103, altForm : 0, isBoss : false }, { species : 405, altForm : 0, isBoss : false },
          { species : 279, altForm : 0, isBoss : false }, { species : 291, altForm : 0, isBoss : false },
          { species : 295, altForm : 0, isBoss : false }, { species : 770, altForm : 0, isBoss : false },
          { species : 771, altForm : 0, isBoss : false }, { species : 305, altForm : 0, isBoss : false },
          { species : 310, altForm : 0, isBoss : false }, { species : 315, altForm : 0, isBoss : false },
          { species : 319, altForm : 0, isBoss : false }, { species : 320, altForm : 0, isBoss : false },
          { species : 324, altForm : 0, isBoss : false }, { species : 862, altForm : 0, isBoss : false },
          { species : 334, altForm : 0, isBoss : false }, { species : 844, altForm : 0, isBoss : false },
          { species : 858, altForm : 0, isBoss : false }, { species : 340, altForm : 0, isBoss : false },
          { species : 342, altForm : 0, isBoss : false }, { species : 344, altForm : 0, isBoss : false },
          { species : 356, altForm : 0, isBoss : false }, { species : 359, altForm : 0, isBoss : false },
          { species : 362, altForm : 0, isBoss : false }, { species : 364, altForm : 0, isBoss : false },
          { species : 369, altForm : 0, isBoss : false }, { species : 132, altForm : 0, isBoss : false },
          { species : 375, altForm : 0, isBoss : false }, { species : 416, altForm : 0, isBoss : false },
          { species : 421, altForm : 0, isBoss : false }, { species : 423, altForm : 1, isBoss : false },
          { species : 426, altForm : 0, isBoss : false }, { species : 428, altForm : 0, isBoss : false },
          { species : 435, altForm : 0, isBoss : false }, { species : 537, altForm : 0, isBoss : false },
          { species : 452, altForm : 0, isBoss : false }, { species : 777, altForm : 0, isBoss : false },
          { species : 460, altForm : 0, isBoss : false }, { species : 478, altForm : 0, isBoss : false },
          { species : 479, altForm : 0, isBoss : false }, { species : 508, altForm : 0, isBoss : false },
          { species : 510, altForm : 0, isBoss : false }, { species : 518, altForm : 0, isBoss : false },
          { species : 521, altForm : 0, isBoss : false }, { species : 528, altForm : 0, isBoss : false },
          { species : 531, altForm : 0, isBoss : false }, { species : 533, altForm : 0, isBoss : false },
          { species : 536, altForm : 0, isBoss : false }, { species : 778, altForm : 0, isBoss : false },
          { species : 884, altForm : 0, isBoss : false }, { species : 545, altForm : 0, isBoss : false },
          { species : 547, altForm : 0, isBoss : false }, { species : 549, altForm : 0, isBoss : false },
          { species : 550, altForm : 0, isBoss : false }, { species : 550, altForm : 1, isBoss : false },
          { species : 828, altForm : 0, isBoss : false }, { species : 834, altForm : 0, isBoss : false },
          { species : 556, altForm : 0, isBoss : false }, { species : 558, altForm : 0, isBoss : false },
          { species : 830, altForm : 0, isBoss : false }, { species : 561, altForm : 0, isBoss : false },
          { species : 446, altForm : 0, isBoss : false }, { species : 855, altForm : 0, isBoss : false },
          { species : 569, altForm : 0, isBoss : false }, { species : 573, altForm : 0, isBoss : false },
          { species : 836, altForm : 0, isBoss : false }, { species : 820, altForm : 0, isBoss : false },
          { species : 583, altForm : 0, isBoss : false }, { species : 587, altForm : 0, isBoss : false },
          { species : 589, altForm : 0, isBoss : false }, { species : 591, altForm : 0, isBoss : false },
          { species : 593, altForm : 0, isBoss : false }, { species : 596, altForm : 0, isBoss : false },
          { species : 601, altForm : 0, isBoss : false }, { species : 606, altForm : 0, isBoss : false },
          { species : 608, altForm : 0, isBoss : false }, { species : 611, altForm : 0, isBoss : false },
          { species : 614, altForm : 0, isBoss : false }, { species : 615, altForm : 0, isBoss : false },
          { species : 617, altForm : 0, isBoss : false }, { species : 618, altForm : 0, isBoss : false },
          { species : 618, altForm : 1, isBoss : false }, { species : 621, altForm : 0, isBoss : false },
          { species : 623, altForm : 0, isBoss : false }, { species : 625, altForm : 0, isBoss : false },
          { species : 626, altForm : 0, isBoss : false }, { species : 631, altForm : 0, isBoss : false },
          { species : 632, altForm : 0, isBoss : false }, { species : 832, altForm : 0, isBoss : false },
          { species : 660, altForm : 0, isBoss : false }, { species : 663, altForm : 0, isBoss : false },
          { species : 675, altForm : 0, isBoss : false }, { species : 39, altForm : 0, isBoss : false },
          { species : 525, altForm : 0, isBoss : false }, { species : 680, altForm : 0, isBoss : false },
          { species : 687, altForm : 0, isBoss : false }, { species : 689, altForm : 0, isBoss : false },
          { species : 695, altForm : 0, isBoss : false }, { species : 702, altForm : 0, isBoss : false },
          { species : 851, altForm : 0, isBoss : false }, { species : 707, altForm : 0, isBoss : false },
          { species : 709, altForm : 0, isBoss : false }, { species : 711, altForm : 0, isBoss : false },
          { species : 847, altForm : 0, isBoss : false }, { species : 845, altForm : 0, isBoss : false },
          { species : 620, altForm : 0, isBoss : false }, { species : 870, altForm : 0, isBoss : false },
          { species : 701, altForm : 0, isBoss : false }, { species : 879, altForm : 0, isBoss : false },
          { species : 826, altForm : 0, isBoss : false }, { species : 838, altForm : 0, isBoss : false },
          { species : 877, altForm : 0, isBoss : false }, { species : 563, altForm : 0, isBoss : false },
          { species : 750, altForm : 0, isBoss : false }, { species : 863, altForm : 0, isBoss : false },
          { species : 871, altForm : 0, isBoss : false }, { species : 873, altForm : 0, isBoss : false },
          { species : 839, altForm : 0, isBoss : false }, { species : 853, altForm : 0, isBoss : false },
          { species : 861, altForm : 0, isBoss : false }, { species : 886, altForm : 0, isBoss : false },
          { species : 36, altForm : 0, isBoss : false },  { species : 44, altForm : 0, isBoss : false },
          { species : 137, altForm : 0, isBoss : false }, { species : 600, altForm : 0, isBoss : false },
          { species : 738, altForm : 0, isBoss : false }, { species : 254, altForm : 0, isBoss : false },
          { species : 257, altForm : 0, isBoss : false }, { species : 260, altForm : 0, isBoss : false },
          { species : 73, altForm : 0, isBoss : false },  { species : 80, altForm : 0, isBoss : false },
          { species : 121, altForm : 0, isBoss : false }, { species : 849, altForm : 0, isBoss : false },
          { species : 134, altForm : 0, isBoss : false }, { species : 135, altForm : 0, isBoss : false },
          { species : 136, altForm : 0, isBoss : false }, { species : 199, altForm : 0, isBoss : false },
          { species : 330, altForm : 0, isBoss : false }, { species : 346, altForm : 0, isBoss : false },
          { species : 348, altForm : 0, isBoss : false }, { species : 437, altForm : 0, isBoss : false },
          { species : 697, altForm : 0, isBoss : false }, { species : 253, altForm : 0, isBoss : false },
          { species : 256, altForm : 0, isBoss : false }, { species : 259, altForm : 0, isBoss : false },
          { species : 699, altForm : 0, isBoss : false }, { species : 765, altForm : 0, isBoss : false },
          { species : 766, altForm : 0, isBoss : false }, { species : 876, altForm : 0, isBoss : false },
          { species : 145, altForm : 0, isBoss : true },  { species : 146, altForm : 0, isBoss : true },
          { species : 144, altForm : 0, isBoss : true },  { species : 150, altForm : 0, isBoss : true },
          { species : 245, altForm : 0, isBoss : true },  { species : 244, altForm : 0, isBoss : true },
          { species : 243, altForm : 0, isBoss : true },  { species : 249, altForm : 0, isBoss : true },
          { species : 250, altForm : 0, isBoss : true },  { species : 380, altForm : 0, isBoss : true },
          { species : 381, altForm : 0, isBoss : true },  { species : 383, altForm : 0, isBoss : true },
          { species : 382, altForm : 0, isBoss : true },  { species : 384, altForm : 0, isBoss : true },
          { species : 480, altForm : 0, isBoss : true },  { species : 482, altForm : 0, isBoss : true },
          { species : 481, altForm : 0, isBoss : true },  { species : 483, altForm : 0, isBoss : true },
          { species : 484, altForm : 0, isBoss : true },  { species : 487, altForm : 0, isBoss : true },
          { species : 485, altForm : 0, isBoss : true },  { species : 488, altForm : 0, isBoss : true },
          { species : 641, altForm : 0, isBoss : true },  { species : 642, altForm : 0, isBoss : true },
          { species : 645, altForm : 0, isBoss : true },  { species : 643, altForm : 0, isBoss : true },
          { species : 644, altForm : 0, isBoss : true },  { species : 646, altForm : 0, isBoss : true },
          { species : 716, altForm : 0, isBoss : true },  { species : 717, altForm : 0, isBoss : true },
          { species : 718, altForm : 3, isBoss : true },  { species : 785, altForm : 0, isBoss : true },
          { species : 786, altForm : 0, isBoss : true },  { species : 787, altForm : 0, isBoss : true },
          { species : 788, altForm : 0, isBoss : true },  { species : 791, altForm : 0, isBoss : true },
          { species : 792, altForm : 0, isBoss : true },  { species : 800, altForm : 0, isBoss : true },
          { species : 793, altForm : 0, isBoss : true },  { species : 794, altForm : 0, isBoss : true },
          { species : 795, altForm : 0, isBoss : true },  { species : 796, altForm : 0, isBoss : true },
          { species : 798, altForm : 0, isBoss : true },  { species : 797, altForm : 0, isBoss : true },
          { species : 799, altForm : 0, isBoss : true },  { species : 806, altForm : 0, isBoss : true },
          { species : 805, altForm : 0, isBoss : true } };

  DmaxAdventureTemplate getTemplateFromPool(std::vector<u32> &pool, std::vector<DmaxAdventureTemplate> &previousResults) {
    DmaxAdventureTemplate result = DMAX_ADVENTURE_TEMPLATES[0];

    for (u32 i = 0; i < pool.size(); i++) {
      auto tableIndex = pool[i];
      result = DMAX_ADVENTURE_TEMPLATES[tableIndex];

      auto foundResult = std::find_if(previousResults.begin(), previousResults.end(), [result](auto previousResult) {
        return result.species == previousResult.species && result.altForm == previousResult.altForm;
      });
      bool previouslySelected = foundResult != previousResults.end();

      if (!result.isBoss && !previouslySelected) {
        break;
      }
    }

    return result;
  }

  std::vector<u32> createPokemonPool(u32 seed) {
    auto poolSize = DMAX_ADVENTURE_TEMPLATES.size();
    std::vector<u32> pool(poolSize);

    std::iota(pool.begin(), pool.end(), 0);

    auto mt = rng::MersenneTwister(seed);
    u32 maxRand = poolSize;

    for (u32 i = 0; i < poolSize; i++) {
      maxRand = maxRand - 1;

      u32 rand = mt.next(maxRand, 0x1ff) + i;

      if (rand != 0) {
        auto tmp = pool[i];
        pool[i] = pool[rand];
        pool[rand] = tmp;
      }
    }

    return pool;
  }

  void setTemplate(rng::xoroshiro *rng, std::vector<DmaxAdventureTemplate> &results) {
    auto pool = createPokemonPool(rng->next());
    auto result = getTemplateFromPool(pool, results);

    results.push_back(result);
  }

  void setEncounterTemplate(rng::xoroshiro *rng, std::vector<DmaxAdventureTemplate> &results) {
    setTemplate(rng, results);

    auto pokemon = results.back();
    auto types = utils::getPokemonTypes(pokemon.species, pokemon.altForm);

    // If the Pokemon has two types, the game chooses which type to display
    if (types.second != enums::PokemonType::NoType) {
      rng->next();
    }
  }

  std::shared_ptr<DmaxAdventure> generateDmaxAdventure(u64 seed, u8 npcCount) {
    auto rng = new rng::xoroshiro(seed);

    std::vector<DmaxAdventureTemplate> result;

    if (npcCount > 2) {
      rng->next(27);
    }

    for (u32 i = 0; i < 4; i++) {
      setTemplate(rng, result);
    }

    if (npcCount > 2) {
      rng->next(2);
    }

    setTemplate(rng, result);

    if (npcCount > 1) {
      rng->next(2);
    }

    setTemplate(rng, result);

    if (npcCount > 0) {
      rng->next(2);
    }

    rng->next(2);
    rng->next(9);

    for (u32 i = 0; i < 10; i++) {
      setEncounterTemplate(rng, result);
    }

    std::vector<DmaxAdventureTemplate> rentals(result.begin(), result.begin() + 6);
    std::vector<DmaxAdventureTemplate> encounters(result.begin() + 6, result.end());

    return std::make_shared<DmaxAdventure>(DmaxAdventure {
      rentals : rentals,
      encounters : encounters,
    });
  }
}