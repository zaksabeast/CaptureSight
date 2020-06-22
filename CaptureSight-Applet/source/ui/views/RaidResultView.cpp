#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <ui/views/RaidResultView.hpp>
#include <utils/Utils.hpp>

namespace ui {
  RaidResultView::RaidResultView(std::shared_ptr<csight::raid::Den> den,
                                 std::shared_ptr<csight::raid::RaidSearchSettings> settings) :
      brls::AppletFrame(true, true) {
    std::string headerText
        = "Seed: " + csight::utils::convertNumToHexString(den->GetSeed()) + ", Shiny: " + std::to_string(den->GetShinyAdvance());

    this->setIcon(BOREALIS_ASSET("icon/app.jpg"));
    this->setTitle(headerText);

    m_resultList = new brls::List();

    m_resultList->addView(
        new brls::Label(brls::LabelStyle::REGULAR, "Advances being shown: " + std::to_string(settings->GetAdvancesToSearch())));

    csight::raid::calculateRaidPKMList(
        settings, std::bind(&RaidResultView::AddListItem, this, std::placeholders::_1, std::placeholders::_2));

    // Temporary workaround
    // borealis seems to get stuck when a label is the only thing in a tabbed list view
    if (m_filteredRaidCount == 0) {
      m_resultList->addView(new brls::ListItem("Empty"));
    }

    m_resultList->addView(new brls::Label(brls::LabelStyle::REGULAR, "End of filtered raids"));
    this->setContentView(m_resultList);
  }

  RaidResultView::~RaidResultView() {}

  void RaidResultView::AddListItem(std::shared_ptr<csight::raid::RaidPokemon> pkm, u32 advance) {
    std::string shinyText = pkm->GetShinyType() ? ", Shiny (" + csight::utils::getShinyTypeString(pkm->GetShinyType()) + ")" : "";
    auto listItemText = "Advance " + std::to_string(advance) + ": " + pkm->GetDisplayIVs()
        + ", Ability: " + pkm->GetAbilityString() + shinyText;
    auto listItem = new brls::ListItem(listItemText);

    m_resultList->addView(listItem);
    m_filteredRaidCount += 1;
  }
}