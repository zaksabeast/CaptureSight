#include <csight/core>
#include <tesla.hpp>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/RaidSearchLayout.hpp>

PokemonSummaryLayout::PokemonSummaryLayout(std::shared_ptr<csight::PK8> pkm) {
  this->pkm = pkm;
}

tsl::Element* PokemonSummaryLayout::createUI() {
  auto rootFrame = new tsl::element::Frame();
  auto bodyDrawer = new tsl::element::CustomDrawer(
      100, FB_WIDTH, 200, FB_WIDTH,
      std::bind(&PokemonSummaryLayout::AddBodyDrawer, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
  auto button = new tsl::element::ListItem("Find raid seed");

  button->setClickListener(std::bind(&PokemonSummaryLayout::FindRaidSeed, this, std::placeholders::_1));
  button->setPosition(20, 550);

  rootFrame->addElement(bodyDrawer);
  rootFrame->addElement(button);

  return rootFrame;
}

void PokemonSummaryLayout::AddBodyDrawer(u16 x, u16 y, tsl::Screen* screen) {
  std::string shiny = this->pkm->GetIsShiny() ? "Shiny " : "";
  std::string species = shiny + this->pkm->GetSpeciesString();
  std::string formattedIVs = "IVs: " + csight::utils::joinNums(this->pkm->GetIVs(), "/");
  std::string formattedEVs = "EVs: " + csight::utils::joinNums(this->pkm->GetEVs(), "/");
  std::string nature = "Nature: " + this->pkm->GetNatureString();
  std::string mintedNature = "Minted Nature: " + this->pkm->GetMintedNatureString();
  std::string friendshipLabel = this->pkm->GetIsEgg() ? "Egg cycles: " : "Friendship: ";
  std::string friendship = friendshipLabel + std::to_string(this->pkm->GetCurrentFriendship());
  std::string moves = "Moves:";
  std::string move0 = "- " + this->pkm->GetMoveString(0);
  std::string move1 = "- " + this->pkm->GetMoveString(1);
  std::string move2 = "- " + this->pkm->GetMoveString(2);
  std::string move3 = "- " + this->pkm->GetMoveString(3);
  std::string pidEd = "PID: " + csight::utils::convertNumToHexString(this->pkm->GetPID()) +
                      " EC: " + csight::utils::convertNumToHexString(this->pkm->GetEncryptionConstant());

  screen->drawString(species.c_str(), false, 20, 50, 34, tsl::a(0xFFFF));
  screen->drawString(formattedIVs.c_str(), false, 20, 100, 24, tsl::a(0xFFFF));
  screen->drawString(formattedEVs.c_str(), false, 20, 140, 24, tsl::a(0xFFFF));
  screen->drawString(nature.c_str(), false, 20, 180, 24, tsl::a(0xFFFF));
  screen->drawString(mintedNature.c_str(), false, 20, 220, 24, tsl::a(0xFFFF));
  screen->drawString(friendship.c_str(), false, 20, 260, 24, tsl::a(0xFFFF));
  screen->drawString(moves.c_str(), false, 20, 300, 24, tsl::a(0xFFFF));
  screen->drawString(move0.c_str(), false, 20, 340, 24, tsl::a(0xFFFF));
  screen->drawString(move1.c_str(), false, 20, 380, 24, tsl::a(0xFFFF));
  screen->drawString(move2.c_str(), false, 20, 420, 24, tsl::a(0xFFFF));
  screen->drawString(move3.c_str(), false, 20, 460, 24, tsl::a(0xFFFF));
  screen->drawString(pidEd.c_str(), false, 20, 500, 24, tsl::a(0xFFFF));
}

bool PokemonSummaryLayout::FindRaidSeed(s64 keys) {
  if (keys == KEY_A) {
    auto seedFuture = this->pkm->GetRaidSeedAsync();
    seedFuture.wait();
    this->seed = seedFuture.get();
    this->changeTo(new RaidSearchLayout(this->seed, 5));
    this->shouldSearchForSeed = false;
    return true;
  }

  return false;
}