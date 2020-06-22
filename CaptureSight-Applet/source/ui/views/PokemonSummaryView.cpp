#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/Utils.hpp>

namespace ui {
  PokemonSummaryView::PokemonSummaryView(std::shared_ptr<csight::PK8> pkm) {
    this->setTitle(pkm->GetSpeciesString());
    this->setIcon(utils::getPokemonIconPath(pkm));

    m_raidSeedView = new brls::List();
    auto findRaidSeedButton = new brls::ListItem("Find raid seed");
    findRaidSeedButton->getClickEvent()->subscribe(
        std::bind(&PokemonSummaryView::OnClickFindRaidSeed, this, pkm, std::placeholders::_1));
    m_raidSeedView->addView(findRaidSeedButton);
    m_raidSeedView->addView(
        new brls::Label(brls::LabelStyle::REGULAR,
                        "Note: This will take a lot of time and cannot be used on shiny or event Pokemon.  The "
                        "console will appear frozen while searching (this will be fixed in the future).",
                        true));

    m_miscTable = new brls::Table();
    m_miscTable->addRow(brls::TableRowType::HEADER, "Misc");
    m_miscTable->addRow(brls::TableRowType::BODY, "Nature", pkm->GetNatureString());
    m_miscTable->addRow(brls::TableRowType::BODY, "Minted Nature", pkm->GetMintedNatureString());
    m_miscTable->addRow(brls::TableRowType::BODY, "Ability", pkm->GetAbilityString());
    m_miscTable->addRow(brls::TableRowType::BODY, "Friendship", std::to_string(pkm->GetCurrentFriendship()));
    m_miscTable->addRow(brls::TableRowType::BODY, "EC", csight::utils::convertNumToHexString(pkm->GetEncryptionConstant()));
    m_miscTable->addRow(brls::TableRowType::BODY, "PID", csight::utils::convertNumToHexString(pkm->GetPID()));

    m_ivTable = new brls::Table();
    m_ivTable->addRow(brls::TableRowType::HEADER, "IVs");
    m_ivTable->addRow(brls::TableRowType::BODY, "HP", std::to_string(pkm->GetIV(0)));
    m_ivTable->addRow(brls::TableRowType::BODY, "ATK", std::to_string(pkm->GetIV(1)));
    m_ivTable->addRow(brls::TableRowType::BODY, "DEF", std::to_string(pkm->GetIV(2)));
    m_ivTable->addRow(brls::TableRowType::BODY, "SPE", std::to_string(pkm->GetIV(4)));
    m_ivTable->addRow(brls::TableRowType::BODY, "SPA", std::to_string(pkm->GetIV(5)));
    m_ivTable->addRow(brls::TableRowType::BODY, "SPD", std::to_string(pkm->GetIV(3)));

    m_evTable = new brls::Table();
    m_evTable->addRow(brls::TableRowType::HEADER, "EVs");
    m_evTable->addRow(brls::TableRowType::BODY, "HP", std::to_string(pkm->GetEV(0)));
    m_evTable->addRow(brls::TableRowType::BODY, "ATK", std::to_string(pkm->GetEV(1)));
    m_evTable->addRow(brls::TableRowType::BODY, "DEF", std::to_string(pkm->GetEV(2)));
    m_evTable->addRow(brls::TableRowType::BODY, "SPE", std::to_string(pkm->GetEV(4)));
    m_evTable->addRow(brls::TableRowType::BODY, "SPA", std::to_string(pkm->GetEV(5)));
    m_evTable->addRow(brls::TableRowType::BODY, "SPD", std::to_string(pkm->GetEV(3)));

    m_moveTable = new brls::Table();
    m_moveTable->addRow(brls::TableRowType::HEADER, "Moves");
    m_moveTable->addRow(brls::TableRowType::BODY, "Move 1", pkm->GetMoveString(0));
    m_moveTable->addRow(brls::TableRowType::BODY, "Move 2", pkm->GetMoveString(1));
    m_moveTable->addRow(brls::TableRowType::BODY, "Move 3", pkm->GetMoveString(2));
    m_moveTable->addRow(brls::TableRowType::BODY, "Move 4", pkm->GetMoveString(3));

    auto weaknesses = pkm->GetWeaknesses();
    m_weaknessTable = new brls::Table();
    m_weaknessTable->addRow(brls::TableRowType::HEADER, "Weakness", "Multiplier");

    for (auto weakness : weaknesses) {
      m_weaknessTable->addRow(brls::TableRowType::BODY, csight::utils::getTypeName(weakness.type),
                              csight::utils::convertFloatWithPrecision(weakness.multiplier, 2));
    }

    this->addTab("Misc", m_miscTable);
    this->addTab("Raid Seed", m_raidSeedView);
    this->addTab("IVs", m_ivTable);
    this->addTab("EVs", m_evTable);
    this->addTab("Moves", m_moveTable);
    this->addTab("Type Weakness", m_weaknessTable);
  }

  PokemonSummaryView::~PokemonSummaryView() {}

  void PokemonSummaryView::OnClickFindRaidSeed(std::shared_ptr<csight::PK8> pkm, brls::View *view) {
    auto seedFuture = pkm->GetRaidSeedAsync();

    // Show indicator here

    u64 seed = seedFuture.get();
    auto shinyDetails = csight::shiny::CalculateShinyDetails(seed, MAX_RAID_ADVANCES);

    brls::Dialog *dialog = new brls::Dialog("Seed found: " + csight::utils::convertNumToHexString(seed)
                                            + "\nAdvances to next shiny: " + std::to_string(shinyDetails->advances)
                                            + "\nShiny type: " + csight::utils::getShinyTypeString(shinyDetails->type));

    dialog->addButton("Continue", [dialog](brls::View *view) { dialog->close(); });
    dialog->setCancelable(false);
    dialog->open();
  }
}