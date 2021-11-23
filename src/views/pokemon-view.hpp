#pragma once

#include "../components/button.hpp"
#include "../utils/debug.hpp"
#include "../utils/general.hpp"
#include <csight-core.h>
#include <functional>
#include <memory>
#include <tesla.hpp>
#include <vector>

typedef std::function<std::shared_ptr<csight::Pkx>()> ReadPokemonFn;

class PokemonView : public tsl::Gui {
 public:
  PokemonView(ReadPokemonFn read_pkm) : m_read_pkm(read_pkm) {};
  ~PokemonView() {};

  virtual tsl::elm::Element *createUI() {
    m_frame = new tsl::elm::OverlayFrame("", " ");
    this->updateFrame();
    return m_frame;
  }

  virtual void update() { this->updateFrame(); }

  void addBodyDrawer(tsl::gfx::Renderer *screen, std::shared_ptr<csight::Pkx> pkm) {
    std::string shiny = pkm->IsShiny() ? "Shiny " : "";

    auto ivs = pkm->Ivs();
    std::vector<u8> ivs_vec = { ivs.hp, ivs.atk, ivs.def, ivs.spa, ivs.spd, ivs.spe };
    std::string formatted_ivs = "IVs: " + utils::join(ivs_vec, "/");

    auto evs = pkm->Evs();
    std::vector<u8> evs_vec = { evs.hp, evs.atk, evs.def, evs.spa, evs.spd, evs.spe };
    std::string formatted_evs = "EVs: " + utils::join(evs_vec, "/");

    std::string nature = "Nature: " + pkm->NatureString();
    std::string minted_nature = "Minted Nature: " + pkm->MintedNatureString();
    std::string ability = "Ability: " + pkm->AbilityString();

    std::string friendshipLabel = pkm->IsEgg() ? "Egg cycles: " : "Friendship: ";
    std::string friendship = friendshipLabel + std::to_string(pkm->CurrentFriendship());

    std::string move1 = "- " + pkm->Move1String();
    std::string move2 = "- " + pkm->Move2String();
    std::string move3 = "- " + pkm->Move3String();
    std::string move4 = "- " + pkm->Move4String();

    std::string pid_ec = "PID: " + utils::num_to_hex(pkm->Pid()) + " EC: " + utils::num_to_hex(pkm->EncryptionConstant());

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

  void updateFrame() {
    auto pkm = m_read_pkm();
    m_frame->setTitle(pkm->SpeciesString());

    auto drawer = new tsl::elm::CustomDrawer(
        [this, pkm](tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) { this->addBodyDrawer(screen, pkm); });

    m_frame->setContent(drawer);
  }

 private:
  tsl::elm::OverlayFrame *m_frame;
  ReadPokemonFn m_read_pkm;
  u64 m_seed = 0;
};

class PokemonViewButton : public Button {
 public:
  PokemonViewButton(const std::string &text, u64 offset) : Button(text) {
    this->onClick([offset]() {
      tsl::changeTo<PokemonView>([offset]() {
        u64 address = dbg::GetHeapAddress(offset);
        return utils::read_pkx(address);
      });
    });
  }

  PokemonViewButton(const std::string &text, ReadPokemonFn get_pkx) : Button(text) {
    this->onClick([get_pkx]() { tsl::changeTo<PokemonView>(get_pkx); });
  }

  PokemonViewButton(const std::string &text, std::shared_ptr<csight::Pkx> pkx) : Button(text) {
    this->onClick([pkx]() { tsl::changeTo<PokemonView>([pkx]() { return pkx; }); });
  }
};
