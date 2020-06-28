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

extern std::shared_ptr<csight::GameReader> g_gameReader;
extern std::shared_ptr<I18N> g_i18n;

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
  g_i18n->Translate("[Wild] "),
  g_i18n->Translate("[Raid] "),
  g_i18n->Translate("[Trade] "),
};

#define GET_POKEMON_TITLE(pokemon) \
  (pokemon->GetIsShiny() ? g_i18n->Translate("Shiny") + " " : "") + pokemon->GetSpeciesString() + ", " + pokemon->GetDisplayIVs()

#define GET_PARTY_TITLE(pokemon, index) \
  "[" + g_i18n->Translate("Party") + " " + std::to_string(index + 1) + "] " + GET_POKEMON_TITLE(pokemon);

#define GET_BOX_TITLE(pokemon, index) \
  "[B" + std::to_string((index / 30) + 1) + "S" + std::to_string((index % 30) + 1) + "] " + GET_POKEMON_TITLE(pokemon);

#define GET_MISC_TITLE(pokemon, index) miscTitles[index] + GET_POKEMON_TITLE(pokemon);

#define GET_DEN_TITLE(den, pokemon, index)                                                                           \
  den->GetDenDisplayName() + ", " + std::to_string(pokemon->GetFlawlessIVCount()) + "IV, "                           \
      + std::to_string(den->GetDisplayStars()) + "★, " + g_i18n->Translate("Shiny") + ": "                           \
      + std::to_string(den->GetShinyAdvance()) + " (" + csight::utils::getShinyTypeString(den->GetShinyType()) + ")" \
      + (den->GetIsEvent() ? ", " + g_i18n->Translate("Event") : "")

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

    this->AddTranslatedTab("Wild/Raid/Trade", m_miscPokemonList);
    this->AddTranslatedTab("Party Pokemon", m_partyPokemonList);
    this->AddTranslatedTab("Box Pokemon", m_boxPokemonList);
    this->addSeparator();
    this->AddTranslatedTab("Active dens", m_activeDenList);
    this->AddTranslatedTab("All dens", m_allDenList);
  }

  MainView::~MainView() {}

  void MainView::AddTranslatedTab(std::string label, brls::View *view) { this->addTab(g_i18n->Translate(label), view); }
}