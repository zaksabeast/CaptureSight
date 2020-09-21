#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <switch.h>
#include <ui/views/MainApplication.hpp>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/I18N.hpp>
#include <utils/Utils.hpp>
#include <vector>

extern std::shared_ptr<csight::game::swsh::SWSHGame> g_gameReader;

#define ADD_POKEMON_TO_VIEW(container, pokemonList, GET_TITLE)                                      \
  for (size_t i = 0; i < pokemonList.size(); i++) {                                                 \
    auto pkm = pokemonList[i];                                                                      \
    auto title = GET_TITLE(pkm, i);                                                                 \
    auto pokemonItem = new brls::ListItem(title);                                                   \
                                                                                                    \
    if (pkm->getIsValid()) {                                                                        \
      pokemonItem->setThumbnail(utils::getPokemonIconPath(pkm));                                    \
    }                                                                                               \
                                                                                                    \
    pokemonItem->getClickEvent()->subscribe(                                                        \
        [pkm](brls::View *view) { brls::Application::pushView(new ui::PokemonSummaryView(pkm)); }); \
    container->addView(pokemonItem);                                                                \
  }

#define ADD_DENS_TO_VIEW(container, denList, GET_TITLE)                                                                   \
  for (size_t i = 0; i < denList.size(); i++) {                                                                           \
    auto den = denList[i];                                                                                                \
    auto pkm = den->getPKM();                                                                                             \
    auto title = GET_TITLE(den, pkm, i);                                                                                  \
    auto denItem = new brls::ListItem(title);                                                                             \
                                                                                                                          \
    denItem->setThumbnail(utils::getPokemonIconPath(pkm));                                                                \
    denItem->getClickEvent()->subscribe([den](brls::View *view) {                                                         \
      brls::Dialog *dialog                                                                                                \
          = new brls::Dialog(I18N::translate("Raid Seed") + ": " + csight::utils::convertNumToHexString(den->getSeed())); \
      dialog->addButton(I18N::translate("Continue"), [dialog](brls::View *view) { dialog->close(); });                    \
      dialog->setCancelable(false);                                                                                       \
      dialog->open();                                                                                                     \
    });                                                                                                                   \
    container->addView(denItem);                                                                                          \
  }

#define GET_POKEMON_TITLE(pokemon)                                                                                               \
  (pokemon->getIsShiny() ? I18N::translate("Shiny") + " " : "") + I18N::translate("species", pokemon->getSpeciesString()) + ", " \
      + pokemon->getDisplayIVs()

#define GET_POKEMON_TITLE_IF_VALID(pokemon) (pokemon->getIsValid() ? GET_POKEMON_TITLE(pokemon) : I18N::translate("None"))

#define GET_PARTY_TITLE(pokemon, index) \
  "[" + I18N::translate("Party") + " " + std::to_string(index + 1) + "] " + GET_POKEMON_TITLE_IF_VALID(pokemon);

#define GET_BOX_TITLE(pokemon, index) \
  "[B" + std::to_string((index / 30) + 1) + "S" + std::to_string((index % 30) + 1) + "] " + GET_POKEMON_TITLE_IF_VALID(pokemon);

#define GET_MISC_TITLE(pokemon, index) m_miscTitles[index] + GET_POKEMON_TITLE_IF_VALID(pokemon);

#define GET_DEN_TITLE(den, pokemon, index)                                                                                      \
  den->getDenDisplayName() + ", " + std::to_string(pokemon->getFlawlessIVCount()) + "IV, "                                      \
      + std::to_string(den->getDisplayStars()) + "★, " + I18N::translate("Shiny") + ": "                                        \
      + std::to_string(den->getShinyAdvance()) + " (" + I18N::translate(csight::utils::getShinyTypeString(den->getShinyType())) \
      + ")" + (den->getIsEvent() ? ", " + I18N::translate("Event") : "")

namespace ui {
  MainView::MainView() {
    this->setTitle("CaptureSight");
    this->setIcon(BOREALIS_ASSET("icon/app.jpg"));

    m_miscTitles = {
      "[" + I18N::translate("Wild") + "] ",
      "[" + I18N::translate("Raid") + "] ",
      "[" + I18N::translate("Trade") + "] ",
    };

    m_partyPokemonList = new brls::List();
    auto partyPokemon = g_gameReader->readParty();
    ADD_POKEMON_TO_VIEW(m_partyPokemonList, partyPokemon, GET_PARTY_TITLE);

    m_miscPokemonList = new brls::List();
    auto miscPokemon = std::vector<std::shared_ptr<csight::pkm::PK8>> {
      g_gameReader->readWild(),
      g_gameReader->readRaid(),
      g_gameReader->readTrade(),
    };
    ADD_POKEMON_TO_VIEW(m_miscPokemonList, miscPokemon, GET_MISC_TITLE);

    m_boxPokemonList = new brls::List();
    auto boxPokemon = g_gameReader->readBoxes();
    ADD_POKEMON_TO_VIEW(m_boxPokemonList, boxPokemon, GET_BOX_TITLE);

    std::string denTabHeader = I18N::translate("Press A to view raid seed");

    m_activeDenList = new brls::List();
    m_activeDenList->addView(new brls::Header(denTabHeader));
    auto activeDens = g_gameReader->readDens(false);
    ADD_DENS_TO_VIEW(m_activeDenList, activeDens, GET_DEN_TITLE);

    m_allDenList = new brls::List();
    m_allDenList->addView(new brls::Header(denTabHeader));
    auto allDens = g_gameReader->readDens(true);
    ADD_DENS_TO_VIEW(m_allDenList, allDens, GET_DEN_TITLE);

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