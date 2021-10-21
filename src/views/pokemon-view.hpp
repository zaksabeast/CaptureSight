#pragma once

#include "../components/button.hpp"
#include "../debug.hpp"
#include "../utils.hpp"
#include <csight-core.h>
#include <memory>
#include <tesla.hpp>
#include <vector>

class PokemonView : public tsl::Gui {
 public:
  PokemonView(std::shared_ptr<csight::Pkx> pkm) : m_pkm(pkm) {};
  ~PokemonView() {};

  virtual tsl::elm::Element *createUI() {
    auto frame = new tsl::elm::OverlayFrame(m_pkm->SpeciesString(), " ");

    auto drawer
        = new tsl::elm::CustomDrawer(std::bind(&PokemonView::addBodyDrawer, this, std::placeholders::_1, std::placeholders::_2,
                                               std::placeholders::_3, std::placeholders::_4, std::placeholders::_5));

    frame->setContent(drawer);
    return frame;
  }

  void addBodyDrawer(tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) {
    std::string shiny = m_pkm->IsShiny() ? "Shiny " : "";

    auto ivs = m_pkm->Ivs();
    std::vector<u8> ivs_vec = { ivs.hp, ivs.atk, ivs.def, ivs.spa, ivs.spd, ivs.spe };
    std::string formatted_ivs = "IVs: " + utils::join(ivs_vec, "/");

    auto evs = m_pkm->Evs();
    std::vector<u8> evs_vec = { evs.hp, evs.atk, evs.def, evs.spa, evs.spd, evs.spe };
    std::string formatted_evs = "EVs: " + utils::join(evs_vec, "/");

    std::string nature = "Nature: " + m_pkm->NatureString();
    std::string minted_nature = "Minted Nature: " + m_pkm->MintedNatureString();
    std::string ability = "Ability: " + m_pkm->AbilityString();

    std::string friendshipLabel = m_pkm->IsEgg() ? "Egg cycles: " : "Friendship: ";
    std::string friendship = friendshipLabel + std::to_string(m_pkm->CurrentFriendship());

    std::string move1 = "- " + m_pkm->Move1String();
    std::string move2 = "- " + m_pkm->Move2String();
    std::string move3 = "- " + m_pkm->Move3String();
    std::string move4 = "- " + m_pkm->Move4String();

    std::string pid_ec = "PID: " + utils::num_to_hex(m_pkm->Pid()) + " EC: " + utils::num_to_hex(m_pkm->EncryptionConstant());

    screen->drawString(formatted_ivs.c_str(), false, 50, 160, 24, screen->a(0xFFFF));
    screen->drawString(formatted_evs.c_str(), false, 50, 200, 24, screen->a(0xFFFF));
    screen->drawString(nature.c_str(), false, 50, 240, 24, screen->a(0xFFFF));
    screen->drawString(minted_nature.c_str(), false, 50, 280, 24, screen->a(0xFFFF));
    screen->drawString(friendship.c_str(), false, 50, 320, 24, screen->a(0xFFFF));
    screen->drawString(ability.c_str(), false, 50, 360, 24, screen->a(0xFFFF));
    screen->drawString("Moves:", false, 50, 400, 24, screen->a(0xFFFF));
    screen->drawString(move1.c_str(), false, 50, 440, 24, screen->a(0xFFFF));
    screen->drawString(move2.c_str(), false, 50, 480, 24, screen->a(0xFFFF));
    screen->drawString(move3.c_str(), false, 50, 520, 24, screen->a(0xFFFF));
    screen->drawString(move4.c_str(), false, 50, 560, 24, screen->a(0xFFFF));
    screen->drawString(pid_ec.c_str(), false, 50, 600, 24, screen->a(0xFFFF));
  }

 private:
  std::shared_ptr<csight::Pkx> m_pkm;
  u64 m_seed = 0;
};

class PokemonViewButton : public Button {
 public:
  PokemonViewButton(const std::string &text, u64 offset) : Button(text) {
    this->onClick([offset]() {
      auto pkm = utils::read_pkx(offset);
      tsl::changeTo<PokemonView>(pkm);
    });
  }
};
