#include <csight/core>
#include <tesla.hpp>
#include <ui/views/PokemonSummaryLayout.hpp>

PokemonSummaryLayout::PokemonSummaryLayout(std::shared_ptr<csight::PK8> pkm) {
  m_pkm = pkm;
}

tsl::elm::Element *PokemonSummaryLayout::createUI() {
  auto rootFrame = new tsl::elm::OverlayFrame(m_pkm->getSpeciesString(), "");
  auto bodyDrawer = new tsl::elm::CustomDrawer(std::bind(&PokemonSummaryLayout::addBodyDrawer, this, std::placeholders::_1,
                                                         std::placeholders::_2, std::placeholders::_3, std::placeholders::_4,
                                                         std::placeholders::_5));

  rootFrame->setContent(bodyDrawer);
  return rootFrame;
}

void PokemonSummaryLayout::addBodyDrawer(tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) {
  std::string shiny = m_pkm->getIsShiny() ? "Shiny " : "";
  std::string formattedIVs = "IVs: " + csight::utils::joinNums(m_pkm->getIVs(), "/");
  std::string formattedEVs = "EVs: " + csight::utils::joinNums(m_pkm->getEVs(), "/");
  std::string nature = "Nature: " + m_pkm->getNatureString();
  std::string mintedNature = "Minted Nature: " + m_pkm->getMintedNatureString();
  std::string ability = "Ability: " + m_pkm->getAbilityString();
  std::string friendshipLabel = m_pkm->getIsEgg() ? "Egg cycles: " : "Friendship: ";
  std::string friendship = friendshipLabel + std::to_string(m_pkm->getCurrentFriendship());
  std::string moves = "Moves:";
  std::string move0 = "- " + m_pkm->getMoveString(0);
  std::string move1 = "- " + m_pkm->getMoveString(1);
  std::string move2 = "- " + m_pkm->getMoveString(2);
  std::string move3 = "- " + m_pkm->getMoveString(3);
  std::string pidEd = "PID: " + csight::utils::convertNumToHexString(m_pkm->getPID())
      + " EC: " + csight::utils::convertNumToHexString(m_pkm->getEncryptionConstant());

  screen->drawString(formattedIVs.c_str(), false, 50, 160, 24, screen->a(0xFFFF));
  screen->drawString(formattedEVs.c_str(), false, 50, 200, 24, screen->a(0xFFFF));
  screen->drawString(nature.c_str(), false, 50, 240, 24, screen->a(0xFFFF));
  screen->drawString(mintedNature.c_str(), false, 50, 280, 24, screen->a(0xFFFF));
  screen->drawString(friendship.c_str(), false, 50, 320, 24, screen->a(0xFFFF));
  screen->drawString(ability.c_str(), false, 50, 360, 24, screen->a(0xFFFF));
  screen->drawString(moves.c_str(), false, 50, 400, 24, screen->a(0xFFFF));
  screen->drawString(move0.c_str(), false, 50, 440, 24, screen->a(0xFFFF));
  screen->drawString(move1.c_str(), false, 50, 480, 24, screen->a(0xFFFF));
  screen->drawString(move2.c_str(), false, 50, 520, 24, screen->a(0xFFFF));
  screen->drawString(move3.c_str(), false, 50, 560, 24, screen->a(0xFFFF));
  screen->drawString(pidEd.c_str(), false, 50, 600, 24, screen->a(0xFFFF));
}
