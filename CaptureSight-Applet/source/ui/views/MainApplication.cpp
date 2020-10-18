#include <borealis.hpp>
#include <csight/core>
#include <functional>
#include <memory>
#include <string>
#include <switch.h>
#include <ui/views/MainApplication.hpp>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/I18N.hpp>
#include <utils/Utils.hpp>
#include <vector>

extern std::shared_ptr<csight::game::swsh::SWSHGame> g_gameReader;

namespace ui {
  std::string getDenTitle(std::shared_ptr<csight::game::swsh::Den> den, std::shared_ptr<csight::pkm::RaidPokemon> pkm,
                          size_t index) {
    auto denName = den->getDenDisplayName();
    auto flawlessIVCount = std::to_string(pkm->getFlawlessIVCount());
    auto stars = std::to_string(den->getDisplayStars());
    auto shinyAdvance = std::to_string(den->getShinyAdvance());
    auto shinyType = I18N::translate(csight::utils::getShinyTypeString(den->getShinyType()));
    auto eventText = den->getIsEvent() ? ", " + I18N::translate("Event") : "";

    return denName + ", " + flawlessIVCount + "IV, " + stars + "★, " + I18N::translate("Shiny") + ": " + shinyAdvance + " ("
        + shinyType + ")" + eventText;
  }

  void addDensToView(brls::List *container, std::vector<std::shared_ptr<csight::game::swsh::Den>> denList) {
    for (size_t i = 0; i < denList.size(); i++) {
      auto den = denList[i];
      auto pkm = den->getPKM();
      auto title = getDenTitle(den, pkm, i);
      auto denItem = new brls::ListItem(title);

      denItem->setThumbnail(utils::getPokemonIconPath(pkm));
      denItem->getClickEvent()->subscribe([den, pkm](brls::View *view) {
        auto ability = I18N::translate("Ability") + ": " + pkm->getAbilityString() + " (" + pkm->getAbilitySlotString() + ")";
        auto displayIVs = I18N::translate("IVs") + ": " + pkm->getDisplayIVs();
        auto raidSeed = I18N::translate("Raid Seed") + ": " + csight::utils::convertNumToHexString(den->getSeed());

        brls::Dialog *dialog = new brls::Dialog(raidSeed + "\n" + ability + "\n" + displayIVs);

        dialog->addButton(I18N::translate("Continue"), [dialog](brls::View *view) { dialog->close(); });
        dialog->setCancelable(false);
        dialog->open();
      });

      container->addView(denItem);
    }
  }

  std::string getPokemonTitle(std::shared_ptr<csight::pkm::PKM> pkm) {
    auto shiny = pkm->getIsShiny() ? I18N::translate("Shiny") + " " : "";
    auto species = I18N::translate("species", pkm->getSpeciesString());
    auto displayIVs = pkm->getDisplayIVs();

    return shiny + species + ", " + displayIVs;
  }

  std::string getPokemonTitleIfValid(std::shared_ptr<csight::pkm::PKM> pkm) {
    return pkm->getIsValid() ? getPokemonTitle(pkm) : I18N::translate("None");
  }

  std::string getPartyTitle(std::shared_ptr<csight::pkm::PKM> pkm, size_t index) {
    return "[" + I18N::translate("Party") + " " + std::to_string(index + 1) + "] " + getPokemonTitleIfValid(pkm);
  }

  std::string getBoxTitle(std::shared_ptr<csight::pkm::PKM> pkm, size_t index) {
    return "[B" + std::to_string((index / 30) + 1) + "S" + std::to_string((index % 30) + 1) + "] " + getPokemonTitleIfValid(pkm);
  }

  std::string getMiscTitle(std::shared_ptr<csight::pkm::PKM> pkm, size_t index) {
    std::vector<std::string> MISC_TITLES = {
      "[" + I18N::translate("Wild") + "] ",
      "[" + I18N::translate("Raid") + "] ",
      "[" + I18N::translate("Trade") + "] ",
    };

    return MISC_TITLES[index] + getPokemonTitleIfValid(pkm);
  }

  void addPokemonToView(brls::List *container, std::vector<std::shared_ptr<csight::pkm::PK8>> pokemonList,
                        std::function<std::string(std::shared_ptr<csight::pkm::PK8>, size_t)> getTitle) {
    for (size_t i = 0; i < pokemonList.size(); i++) {
      auto pkm = pokemonList[i];
      auto title = getTitle(pkm, i);
      auto pokemonItem = new brls::ListItem(title);

      if (pkm->getIsValid()) {
        pokemonItem->setThumbnail(utils::getPokemonIconPath(pkm));
      }

      pokemonItem->getClickEvent()->subscribe(
          [pkm](brls::View *view) { brls::Application::pushView(new ui::PokemonSummaryView(pkm)); });
      container->addView(pokemonItem);
    }
  }

  MainView::MainView() {
    this->setTitle("CaptureSight");
    this->setIcon(BOREALIS_ASSET("icon/app.jpg"));

    m_partyPokemonList = new brls::List();
    auto partyPokemon = g_gameReader->readParty();
    addPokemonToView(m_partyPokemonList, partyPokemon, getPartyTitle);

    m_miscPokemonList = new brls::List();
    auto miscPokemon = std::vector<std::shared_ptr<csight::pkm::PK8>> {
      g_gameReader->readWild(),
      g_gameReader->readRaid(),
      g_gameReader->readTrade(),
    };
    addPokemonToView(m_miscPokemonList, miscPokemon, getMiscTitle);

    m_boxPokemonList = new brls::List();
    auto boxPokemon = g_gameReader->readBoxes();
    addPokemonToView(m_boxPokemonList, boxPokemon, getBoxTitle);

    std::string denTabHeader = I18N::translate("Press A to view raid seed");

    m_activeDenList = new brls::List();
    m_activeDenList->addView(new brls::Header(denTabHeader));
    auto activeDens = g_gameReader->readDens(false);
    addDensToView(m_activeDenList, activeDens);

    m_allDenList = new brls::List();
    m_allDenList->addView(new brls::Header(denTabHeader));
    auto allDens = g_gameReader->readDens(true);
    addDensToView(m_allDenList, allDens);

    this->addTranslatedTab("Misc Pokemon", m_miscPokemonList);
    this->addTranslatedTab("Party Pokemon", m_partyPokemonList);
    this->addTranslatedTab("Box Pokemon", m_boxPokemonList);
    this->addSeparator();
    this->addTranslatedTab("Active dens", m_activeDenList);
    this->addTranslatedTab("All dens", m_allDenList);
  }

  MainView::~MainView() { }

  void MainView::addTranslatedTab(std::string label, brls::View *view) { this->addTab(I18N::translate(label), view); }
}