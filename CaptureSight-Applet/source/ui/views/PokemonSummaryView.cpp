#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <string>
#include <ui/views/PokemonSummaryView.hpp>
#include <utils/I18N.hpp>
#include <utils/Utils.hpp>

#define ADD_HEADER_ROW(table, label) table->addRow(brls::TableRowType::HEADER, I18N::translate(label));

#define ADD_BODY_ROW(table, label, valueTranslationCategory, value) \
  table->addRow(brls::TableRowType::BODY, I18N::translate(label), I18N::translate(valueTranslationCategory, value));

namespace ui {
  PokemonSummaryView::PokemonSummaryView(std::shared_ptr<csight::pkm::PK8> pkm) {
    this->setTitle(I18N::translate("species", pkm->getSpeciesString()));
    this->setIcon(utils::getPokemonIconPath(pkm));

    m_raidSeedView = new brls::List();
    auto findRaidSeedButton = new brls::ListItem(I18N::translate("Find raid seed"));
    findRaidSeedButton->getClickEvent()->subscribe(
        std::bind(&PokemonSummaryView::onClickFindRaidSeed, this, pkm, std::placeholders::_1));
    m_raidSeedView->addView(findRaidSeedButton);
    m_raidSeedView->addView(
        new brls::Label(brls::LabelStyle::REGULAR,
                        I18N::translate("Note: This will take a lot of time and cannot be used on shiny or event Pokemon.  The "
                                        "console will appear frozen while searching (this will be fixed in the future)."),
                        true));

    std::string friendshipTranslationKey = pkm->getIsEgg() ? "Egg cycles" : "Friendship";
    m_miscTable = new brls::Table();
    ADD_HEADER_ROW(m_miscTable, "Misc");
    ADD_BODY_ROW(m_miscTable, "Shiny type", "app", pkm->getShinyTypeString());
    ADD_BODY_ROW(m_miscTable, "Nature", "natures", pkm->getNatureString());
    ADD_BODY_ROW(m_miscTable, "Minted Nature", "natures", pkm->getMintedNatureString());
    ADD_BODY_ROW(m_miscTable, "Ability", "abilities", pkm->getAbilityString());
    ADD_BODY_ROW(m_miscTable, friendshipTranslationKey, "app", std::to_string(pkm->getCurrentFriendship()));
    ADD_BODY_ROW(m_miscTable, "EC", "app", csight::utils::convertNumToHexString(pkm->getEC()));
    ADD_BODY_ROW(m_miscTable, "PID", "app", csight::utils::convertNumToHexString(pkm->getPID()));
    ADD_BODY_ROW(m_miscTable, "OT Gender", "app", pkm->getOTGenderString());
    ADD_BODY_ROW(m_miscTable, "Alt Form", "app", std::to_string(pkm->getForm()));

    m_ivTable = new brls::Table();
    ADD_HEADER_ROW(m_ivTable, "IVs");
    ADD_BODY_ROW(m_ivTable, "HP", "app", std::to_string(pkm->getIV(0)));
    ADD_BODY_ROW(m_ivTable, "ATK", "app", std::to_string(pkm->getIV(1)));
    ADD_BODY_ROW(m_ivTable, "DEF", "app", std::to_string(pkm->getIV(2)));
    ADD_BODY_ROW(m_ivTable, "SPA", "app", std::to_string(pkm->getIV(4)));
    ADD_BODY_ROW(m_ivTable, "SPD", "app", std::to_string(pkm->getIV(5)));
    ADD_BODY_ROW(m_ivTable, "SPE", "app", std::to_string(pkm->getIV(3)));

    m_evTable = new brls::Table();
    ADD_HEADER_ROW(m_evTable, "EVs");
    ADD_BODY_ROW(m_evTable, "HP", "app", std::to_string(pkm->getEV(0)));
    ADD_BODY_ROW(m_evTable, "ATK", "app", std::to_string(pkm->getEV(1)));
    ADD_BODY_ROW(m_evTable, "DEF", "app", std::to_string(pkm->getEV(2)));
    ADD_BODY_ROW(m_evTable, "SPA", "app", std::to_string(pkm->getEV(4)));
    ADD_BODY_ROW(m_evTable, "SPD", "app", std::to_string(pkm->getEV(5)));
    ADD_BODY_ROW(m_evTable, "SPE", "app", std::to_string(pkm->getEV(3)));

    m_moveTable = new brls::Table();
    ADD_HEADER_ROW(m_moveTable, "Moves");
    ADD_BODY_ROW(m_moveTable, "Move 1", "moves", pkm->getMoveString(0));
    ADD_BODY_ROW(m_moveTable, "Move 2", "moves", pkm->getMoveString(1));
    ADD_BODY_ROW(m_moveTable, "Move 3", "moves", pkm->getMoveString(2));
    ADD_BODY_ROW(m_moveTable, "Move 4", "moves", pkm->getMoveString(3));

    auto weaknesses = pkm->getWeaknesses();
    m_weaknessTable = new brls::Table();
    m_weaknessTable->addRow(brls::TableRowType::HEADER, I18N::translate("Weakness"), I18N::translate("Multiplier"));

    for (auto weakness : weaknesses) {
      auto weaknessString = I18N::translate("types", csight::utils::getTypeName(weakness.type));
      auto weaknessMultiplier = csight::utils::convertFloatWithPrecision(weakness.multiplier, 2);
      m_weaknessTable->addRow(brls::TableRowType::BODY, weaknessString, weaknessMultiplier);
    }

    this->addTranslatedTab("Misc", m_miscTable);
    this->addTranslatedTab("Raid Seed", m_raidSeedView);
    this->addTranslatedTab("IVs", m_ivTable);
    this->addTranslatedTab("EVs", m_evTable);
    this->addTranslatedTab("Moves", m_moveTable);
    this->addTranslatedTab("Weaknesses", m_weaknessTable);
  }

  PokemonSummaryView::~PokemonSummaryView() { }

  void PokemonSummaryView::onClickFindRaidSeed(std::shared_ptr<csight::pkm::PK8> pkm, brls::View *view) {
    auto seedFuture = pkm->getRaidSeedAsync();

    // Show indicator here

    u64 seed = seedFuture.get();
    auto shinyDetails
        = csight::game::swsh::calculateShinyDetails(seed, MAX_RAID_ADVANCES, csight::game::swsh::ShinyRaidSetting::Random);

    brls::Dialog *dialog = new brls::Dialog(I18N::translate("Seed found") + ": " + csight::utils::convertNumToHexString(seed)
                                            + "\n" + I18N::translate("Advances to next shiny") + ": "
                                            + std::to_string(shinyDetails->advances) + "\n" + I18N::translate("Shiny type") + ": "
                                            + I18N::translate(csight::utils::getShinyTypeString(shinyDetails->type)));

    dialog->addButton(I18N::translate("Continue"), [dialog](brls::View *view) { dialog->close(); });
    dialog->setCancelable(false);
    dialog->open();
  }

  void PokemonSummaryView::addTranslatedTab(std::string label, brls::View *view) { this->addTab(I18N::translate(label), view); }
}