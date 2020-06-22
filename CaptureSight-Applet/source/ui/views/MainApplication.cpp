#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <switch.h>
#include <ui/views/MainApplication.hpp>
#include <ui/views/PokemonSummaryView.hpp>
#include <ui/views/RaidResultView.hpp>
#include <utils/Utils.hpp>
#include <vector>

#define RAID_SEARCH_ADVANCES 2000
extern std::shared_ptr<csight::GameReader> g_gameReader;
extern std::shared_ptr<csight::raid::RaidSearchSettings> g_raidSearchSettings;

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

#define ADD_DENS_TO_VIEW(container, denList, GET_TITLE)                                                                \
  container->addView(new brls::Label(brls::LabelStyle::REGULAR, "Click \"A\" on a den to see upcoming raid results")); \
                                                                                                                       \
  for (size_t i = 0; i < denList.size(); i++) {                                                                        \
    auto den = denList[i];                                                                                             \
    auto pkm = den->GetPKM();                                                                                          \
    auto title = GET_TITLE(den, pkm, i);                                                                               \
    auto denItem = new brls::ListItem(title);                                                                          \
                                                                                                                       \
    denItem->setThumbnail(utils::getPokemonIconPath(pkm));                                                             \
    denItem->getClickEvent()->subscribe([den](brls::View *view) {                                                      \
      g_raidSearchSettings->SetSeed(den->GetSeed());                                                                   \
      g_raidSearchSettings->SetDenIndex(den->GetDenId());                                                              \
      brls::Application::pushView(new ui::RaidResultView(den, g_raidSearchSettings));                                  \
    });                                                                                                                \
    container->addView(denItem);                                                                                       \
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

    g_raidSearchSettings->SetAdvancesToSearch(RAID_SEARCH_ADVANCES);
    g_raidSearchSettings->SetIsRareDen(true);
    g_raidSearchSettings->SetSpawnIndex(0);

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

    m_raidSearchSettingsList = new brls::List();

    brls::SelectListItem *shinyFilter
        = new brls::SelectListItem("Shiny type", { "No filter", "Star", "Square", "Star or Square" });
    shinyFilter->getValueSelectedEvent()->subscribe(std::bind(&MainView::OnClickShinyRaidFilter, this, std::placeholders::_1));

    m_flawlessIVFilter = new brls::SelectListItem("Flawless IVs", { "0", "1", "2", "3", "4", "5", "6" });
    m_flawlessIVFilter->getValueSelectedEvent()->subscribe(
        std::bind(&MainView::OnClickFlawlessIVRaidFilter, this, std::placeholders::_1));

    m_abilityFilter = new brls::SelectListItem("Ability", { "Any", "1", "2", "H" });
    m_abilityFilter->getValueSelectedEvent()->subscribe(
        std::bind(&MainView::OnClickAbilityRaidFilter, this, std::placeholders::_1));

    m_raidSearchSettingsList->addView(new brls::Header("Pressing 'A' on a den will show upcoming advances with these filters"));
    m_raidSearchSettingsList->addView(shinyFilter);
    m_raidSearchSettingsList->addView(m_flawlessIVFilter);
    m_raidSearchSettingsList->addView(m_abilityFilter);
    m_raidSearchSettingsList->addView(new brls::Label(brls::LabelStyle::REGULAR, "Star count is currently hardcoded to 3", true));

    this->addTab("Wild/Raid/Trade", m_miscPokemonList);
    this->addTab("Party Pokemon", m_partyPokemonList);
    this->addTab("Box Pokemon", m_boxPokemonList);
    this->addSeparator();
    this->addTab("Raid Search settings", m_raidSearchSettingsList);
    this->addSeparator();
    this->addTab("Active dens", m_activeDenList);
    this->addTab("All dens", m_allDenList);
  }

  MainView::~MainView() {}

  void MainView::OnClickShinyRaidFilter(size_t selection) {
    csight::shiny::ShinyType filter;

    switch (selection) {
      case 1:
        filter = csight::shiny::ShinyType::Star;
        break;
      case 2:
        filter = csight::shiny::ShinyType::Square;
        break;
      case 3:
        filter = csight::shiny::ShinyType::Any;
        break;
      default:
        filter = csight::shiny::ShinyType::None;
        break;
    }

    g_raidSearchSettings->SetShinyTypeFilter(filter);
  }

  void MainView::OnClickFlawlessIVRaidFilter(size_t selection) { g_raidSearchSettings->SetFlawlessIVFilter((u8)selection); }

  void MainView::OnClickAbilityRaidFilter(size_t selection) {
    csight::ability::filter::AbilityFilter filter;

    switch (selection) {
      case 1:
        filter = csight::ability::filter::AbilityFilter::First;
        break;
      case 2:
        filter = csight::ability::filter::AbilityFilter::Second;
        break;
      case 3:
        filter = csight::ability::filter::AbilityFilter::Hidden;
        break;
      default:
        filter = csight::ability::filter::AbilityFilter::Any;
        break;
    }

    g_raidSearchSettings->SetAbilityFilter(filter);
  }
}