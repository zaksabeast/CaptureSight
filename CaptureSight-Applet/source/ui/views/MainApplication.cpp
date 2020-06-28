#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <switch.h>
#include <ui/views/MainApplication.hpp>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/Utils.hpp>
#include <vector>

extern std::shared_ptr<csight::GameReader> g_gameReader;

#define ADD_POKEMON_TO_VIEW(container, pokemonList, GET_TITLE)                                      \
  for (size_t i = 0; i < pokemonList.size(); i++) {                                                 \
    auto pkm = pokemonList[i];                                                                      \
    auto title = GET_TITLE(pkm, i);                                                                 \
    auto pokemonItem = new brls::ListItem(title);                                                   \
                                                                                                    \
    if (pkm->GetIsValid()) {                                                                        \
      pokemonItem->setThumbnail(utils::getPokemonIconPath(pkm));                                    \
    }                                                                                               \
                                                                                                    \
    pokemonItem->getClickEvent()->subscribe(                                                        \
        [pkm](brls::View *view) { brls::Application::pushView(new ui::PokemonSummaryView(pkm)); }); \
    container->addView(pokemonItem);                                                                \
  }

#define ADD_DENS_TO_VIEW(container, denList, GET_TITLE)    \
  for (size_t i = 0; i < denList.size(); i++) {            \
    auto den = denList[i];                                 \
    auto pkm = den->GetPKM();                              \
    auto title = GET_TITLE(den, pkm, i);                   \
    auto denItem = new brls::ListItem(title);              \
                                                           \
    denItem->setThumbnail(utils::getPokemonIconPath(pkm)); \
    container->addView(denItem);                           \
  }

std::vector<std::string> miscTitles = {
  "[Wild] ",
  "[Raid] ",
  "[Trade] ",
};

#define GET_POKEMON_TITLE(pokemon) \
  (pokemon->GetIsShiny() ? "Shiny " : "") + pokemon->GetSpeciesString() + ", " + pokemon->GetDisplayIVs()

#define GET_PARTY_TITLE(pokemon, index) "[Party " + std::to_string(index + 1) + "] " + GET_POKEMON_TITLE(pokemon);

#define GET_BOX_TITLE(pokemon, index) \
  "[B" + std::to_string((index / 30) + 1) + "S" + std::to_string((index % 30) + 1) + "] " + GET_POKEMON_TITLE(pokemon);

#define GET_MISC_TITLE(pokemon, index) miscTitles[index] + GET_POKEMON_TITLE(pokemon);

#define GET_DEN_TITLE(den, pokemon, index)                                                                    \
  den->GetDenDisplayName() + ", " + std::to_string(pokemon->GetFlawlessIVCount()) + "IV, "                    \
      + std::to_string(den->GetDisplayStars()) + "★, Shiny: " + std::to_string(den->GetShinyAdvance()) + " (" \
      + csight::utils::getShinyTypeString(den->GetShinyType()) + ")" + (den->GetIsEvent() ? ", Event" : "")

namespace ui {
  MainView::MainView() {
    this->setTitle("CaptureSight");
    this->setIcon(BOREALIS_ASSET("icon/app.jpg"));

    m_partyPokemonList = new brls::List();
    auto partyPokemon = g_gameReader->ReadParty();
    ADD_POKEMON_TO_VIEW(m_partyPokemonList, partyPokemon, GET_PARTY_TITLE);

    m_miscPokemonList = new brls::List();
    auto miscPokemon = std::vector<std::shared_ptr<csight::PK8>> {
      g_gameReader->ReadWild(),
      g_gameReader->ReadRaid(),
      g_gameReader->ReadTrade(),
    };
    ADD_POKEMON_TO_VIEW(m_miscPokemonList, miscPokemon, GET_MISC_TITLE);

    m_boxPokemonList = new brls::List();
    auto boxPokemon = g_gameReader->ReadBoxes();
    ADD_POKEMON_TO_VIEW(m_boxPokemonList, boxPokemon, GET_BOX_TITLE);

    m_activeDenList = new brls::List();
    auto activeDens = g_gameReader->ReadDens(false);
    ADD_DENS_TO_VIEW(m_activeDenList, activeDens, GET_DEN_TITLE);

    m_allDenList = new brls::List();
    auto allDens = g_gameReader->ReadDens(true);
    ADD_DENS_TO_VIEW(m_allDenList, allDens, GET_DEN_TITLE);

    this->addTab("Wild/Raid/Trade", m_miscPokemonList);
    this->addTab("Party Pokemon", m_partyPokemonList);
    this->addTab("Box Pokemon", m_boxPokemonList);
    this->addSeparator();
    this->addTab("Active dens", m_activeDenList);
    this->addTab("All dens", m_allDenList);
  }

  MainView::~MainView() {}
}