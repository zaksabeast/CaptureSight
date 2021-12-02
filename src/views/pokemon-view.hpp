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
    m_frame = new tsl::elm::OverlayFrame("", "Press \uE0A2 X to toggle PID/EC");
    this->updateFrame();
    return m_frame;
  }

  virtual void update() { this->updateFrame(); }

  void addBodyDrawer(tsl::gfx::Renderer *screen, std::shared_ptr<csight::Pkx> pkm) {
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

    std::string tidsid = "TID: " + std::to_string(pkm->Tid()) + " SID: " + std::to_string(pkm->Sid());

    std::string pid_ec = m_hide_sensitive_info
        ? " "
        : "PID: " + utils::num_to_hex(pkm->Pid()) + " EC: " + utils::num_to_hex(pkm->EncryptionConstant());

    screen->drawString(formatted_ivs.c_str(), false, 50, 160, 24, screen->a(0xFFFF));
    screen->drawString(formatted_evs.c_str(), false, 50, 195, 24, screen->a(0xFFFF));
    screen->drawString(nature.c_str(), false, 50, 230, 24, screen->a(0xFFFF));
    screen->drawString(minted_nature.c_str(), false, 50, 265, 24, screen->a(0xFFFF));
    screen->drawString(friendship.c_str(), false, 50, 300, 24, screen->a(0xFFFF));
    screen->drawString(ability.c_str(), false, 50, 335, 24, screen->a(0xFFFF));
    screen->drawString("Moves:", false, 50, 370, 24, screen->a(0xFFFF));
    screen->drawString(move1.c_str(), false, 50, 405, 24, screen->a(0xFFFF));
    screen->drawString(move2.c_str(), false, 50, 440, 24, screen->a(0xFFFF));
    screen->drawString(move3.c_str(), false, 50, 475, 24, screen->a(0xFFFF));
    screen->drawString(move4.c_str(), false, 50, 510, 24, screen->a(0xFFFF));
    screen->drawString(tidsid.c_str(), false, 50, 545, 24, screen->a(0xFFFF));
    screen->drawString(pid_ec.c_str(), false, 50, 580, 24, screen->a(0xFFFF));
  }

  void updateFrame() {
    auto pkm = m_read_pkm();
    std::string shiny = pkm->IsShiny() ? "Shiny " : " ";
    m_frame->setTitle(shiny + pkm->SpeciesString());

    auto drawer = new tsl::elm::CustomDrawer(
        [this, pkm](tsl::gfx::Renderer *screen, u16 x, u16 y, u16 w, u16 h) { this->addBodyDrawer(screen, pkm); });

    m_frame->setContent(drawer);
  }

  virtual bool handleInput(u64 keysDown, u64 keysHeld, const HidTouchState &touchPos, HidAnalogStickState leftJoyStick,
                           HidAnalogStickState rightJoyStick) {
    if (keysDown & HidNpadButton_X) {
      m_hide_sensitive_info = !m_hide_sensitive_info;
      return true;
    }

    return false;
  }

 private:
  tsl::elm::OverlayFrame *m_frame;
  ReadPokemonFn m_read_pkm;
  u64 m_seed = 0;
  bool m_hide_sensitive_info = false;
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
