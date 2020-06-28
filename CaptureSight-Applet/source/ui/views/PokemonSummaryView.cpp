#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/I18N.hpp>
#include <utils/Utils.hpp>

extern std::shared_ptr<I18N> g_i18n;

#define ADD_BODY_ROW(table, label, valueTranslationCategory, value) \
  table->addRow(brls::TableRowType::BODY, g_i18n->Translate(label), g_i18n->Translate(valueTranslationCategory, value));

namespace ui {
  PokemonSummaryView::PokemonSummaryView(std::shared_ptr<csight::PK8> pkm) {
    this->setTitle(pkm->GetSpeciesString());
    this->setIcon(utils::getPokemonIconPath(pkm));

    m_raidSeedView = new brls::List();
    auto findRaidSeedButton = new brls::ListItem(g_i18n->Translate("Find raid seed"));
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
    ADD_BODY_ROW(m_miscTable, "Nature", "natures", pkm->GetNatureString());
    ADD_BODY_ROW(m_miscTable, "Minted Nature", "natures", pkm->GetMintedNatureString());
    ADD_BODY_ROW(m_miscTable, "Ability", "abilities", pkm->GetAbilityString());
    ADD_BODY_ROW(m_miscTable, "Friendship", "", std::to_string(pkm->GetCurrentFriendship()));
    ADD_BODY_ROW(m_miscTable, "EC", "", csight::utils::convertNumToHexString(pkm->GetEncryptionConstant()));
    ADD_BODY_ROW(m_miscTable, "PID", "", csight::utils::convertNumToHexString(pkm->GetPID()));

    m_ivTable = new brls::Table();
    m_ivTable->addRow(brls::TableRowType::HEADER, "IVs");
    ADD_BODY_ROW(m_ivTable, "HP", "", std::to_string(pkm->GetIV(0)));
    ADD_BODY_ROW(m_ivTable, "ATK", "", std::to_string(pkm->GetIV(1)));
    ADD_BODY_ROW(m_ivTable, "DEF", "", std::to_string(pkm->GetIV(2)));
    ADD_BODY_ROW(m_ivTable, "SPE", "", std::to_string(pkm->GetIV(4)));
    ADD_BODY_ROW(m_ivTable, "SPA", "", std::to_string(pkm->GetIV(5)));
    ADD_BODY_ROW(m_ivTable, "SPD", "", std::to_string(pkm->GetIV(3)));

    m_evTable = new brls::Table();
    m_evTable->addRow(brls::TableRowType::HEADER, "EVs");
    ADD_BODY_ROW(m_evTable, "HP", "", std::to_string(pkm->GetEV(0)));
    ADD_BODY_ROW(m_evTable, "ATK", "", std::to_string(pkm->GetEV(1)));
    ADD_BODY_ROW(m_evTable, "DEF", "", std::to_string(pkm->GetEV(2)));
    ADD_BODY_ROW(m_evTable, "SPE", "", std::to_string(pkm->GetEV(4)));
    ADD_BODY_ROW(m_evTable, "SPA", "", std::to_string(pkm->GetEV(5)));
    ADD_BODY_ROW(m_evTable, "SPD", "", std::to_string(pkm->GetEV(3)));

    m_moveTable = new brls::Table();
    m_moveTable->addRow(brls::TableRowType::HEADER, "Moves");
    ADD_BODY_ROW(m_moveTable, "Move 1", "moves", pkm->GetMoveString(0));
    ADD_BODY_ROW(m_moveTable, "Move 2", "moves", pkm->GetMoveString(1));
    ADD_BODY_ROW(m_moveTable, "Move 3", "moves", pkm->GetMoveString(2));
    ADD_BODY_ROW(m_moveTable, "Move 4", "moves", pkm->GetMoveString(3));

    auto weaknesses = pkm->GetWeaknesses();
    m_weaknessTable = new brls::Table();
    m_weaknessTable->addRow(brls::TableRowType::HEADER, "Weakness", "Multiplier");

    for (auto weakness : weaknesses) {
      ADD_BODY_ROW(m_weaknessTable, csight::utils::getTypeName(weakness.type), "types",
                   csight::utils::convertFloatWithPrecision(weakness.multiplier, 2));
    }

    this->AddTranslatedTab("Misc", m_miscTable);
    this->AddTranslatedTab("Raid Seed", m_raidSeedView);
    this->AddTranslatedTab("IVs", m_ivTable);
    this->AddTranslatedTab("EVs", m_evTable);
    this->AddTranslatedTab("Moves", m_moveTable);
    this->AddTranslatedTab("Weaknesses", m_weaknessTable);
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

    dialog->addButton(g_i18n->Translate("Continue"), [dialog](brls::View *view) { dialog->close(); });
    dialog->setCancelable(false);
    dialog->open();
  }

  void PokemonSummaryView::AddTranslatedTab(std::string label, brls::View *view) { this->addTab(g_i18n->Translate(label), view); }
}