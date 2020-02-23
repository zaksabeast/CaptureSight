#include <functional>
#include <string>
#include <stratosphere.hpp>
#include <csight/core>
#include <ui/PokemonSprite.hpp>
#include <ui/PokemonSummaryLayout.hpp>
#include <ui/elements/Polygon.hpp>
#include <ui/elements/RoundedRectangle.hpp>
#include <ui/elements/Line.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>
#include <utils/Constants.hpp>

extern Settings gsets;
extern std::shared_ptr<I18N> i18n;

#define SCREEN_MARGIN_SIZE 100
#define SCREEN_LEFT_MARGIN SCREEN_MARGIN_SIZE
#define SCREEN_RIGHT_MARGIN SCREEN_MAX_WIDTH - SCREEN_MARGIN_SIZE

#define HEADER_BACKGROUND_HEIGHT 80
#define HEADER_FONT_SIZE 36
#define HEADER_TEXT_Y ((HEADER_BACKGROUND_HEIGHT - HEADER_FONT_SIZE) / 2)
#define SPECIES_TEXT_X SCREEN_LEFT_MARGIN
#define TITLE_TEXT_X (SPECIES_TEXT_X + 450)

// Used to pad entire content
#define TABLE_CONTENT_PADDING 25
// Used to pad individual items
#define TABLE_ITEM_PADDING 25
#define TABLE_ITEM_FONT_SIZE 25
#define TABLE_BORDER_RADIUS 5
#define getTableHeight(ITEM_COUNT) ((TABLE_CONTENT_PADDING * 2) + ((TABLE_ITEM_FONT_SIZE * ITEM_COUNT) + (TABLE_ITEM_PADDING * (ITEM_COUNT - 1))))
#define getTableItemX(BASE_X) (BASE_X + TABLE_CONTENT_PADDING)
#define getTableItemY(BASE_Y, ITEM_INDEX) ((ITEM_INDEX * (TABLE_ITEM_PADDING + TABLE_ITEM_FONT_SIZE)) + BASE_Y + TABLE_CONTENT_PADDING)
#define createTableItem(getTableItemY, ITEM_X, ITEM_REF, ITEM_INDEX, THEME)                            \
  ITEM_REF = pu::ui::elm::TextBlock::New(ITEM_X, getTableItemY(ITEM_INDEX), "", TABLE_ITEM_FONT_SIZE); \
  ITEM_REF->SetColor(THEME.text.light);

#define LABEL_PADDING 10
#define LABEL_FONT_SIZE TABLE_ITEM_FONT_SIZE
#define LABEL_HEIGHT ((LABEL_PADDING * 2) + LABEL_FONT_SIZE)
#define getLabelTextX(BASE_X) (BASE_X + LABEL_PADDING)

#define MOVE_TABLE_ITEM_COUNT 4
#define MOVE_TABLE_BASE_X TITLE_TEXT_X
#define MOVE_TABLE_BASE_Y 185
#define MOVE_TABLE_WIDTH 370
#define MOVE_TABLE_HEIGHT getTableHeight(MOVE_TABLE_ITEM_COUNT)
#define MOVE_TABLE_ITEM_X getTableItemX(MOVE_TABLE_BASE_X)
#define getMoveTableItemY(ITEM_INDEX) (getTableItemY(MOVE_TABLE_BASE_Y, ITEM_INDEX))
#define createMoveTableItem(ITEM_REF, ITEM_INDEX, THEME) createTableItem(getMoveTableItemY, MOVE_TABLE_ITEM_X, ITEM_REF, ITEM_INDEX, THEME)

#define MAIN_INFO_TABLE_ITEM_COUNT 3
#define MAIN_INFO_TABLE_BASE_X SPECIES_TEXT_X
#define MAIN_INFO_TABLE_BASE_Y 470
#define MAIN_INFO_TABLE_WIDTH 400
#define MAIN_INFO_TABLE_HEIGHT getTableHeight(MAIN_INFO_TABLE_ITEM_COUNT)
#define MAIN_INFO_TABLE_ITEM_X getTableItemX(MAIN_INFO_TABLE_BASE_X)
#define getMainInfoTableItemY(ITEM_INDEX) (getTableItemY(MAIN_INFO_TABLE_BASE_Y, ITEM_INDEX))
#define createMainInfoTableItem(ITEM_REF, ITEM_INDEX, THEME) \
  createTableItem(getMainInfoTableItemY, MAIN_INFO_TABLE_ITEM_X, ITEM_REF, ITEM_INDEX, THEME)

#define EXTRA_INFO_TABLE_ITEM_COUNT 3
#define EXTRA_INFO_TABLE_BASE_X TITLE_TEXT_X
#define EXTRA_INFO_TABLE_BASE_Y MAIN_INFO_TABLE_BASE_Y
#define EXTRA_INFO_TABLE_WIDTH (SCREEN_RIGHT_MARGIN - EXTRA_INFO_TABLE_BASE_X)
#define EXTRA_INFO_TABLE_HEIGHT getTableHeight(EXTRA_INFO_TABLE_ITEM_COUNT)
#define EXTRA_INFO_TABLE_ITEM_X getTableItemX(EXTRA_INFO_TABLE_BASE_X)
#define getExtraInfoTableItemY(ITEM_INDEX) (getTableItemY(EXTRA_INFO_TABLE_BASE_Y, ITEM_INDEX))
#define createExtraInfoTableItem(ITEM_REF, ITEM_INDEX, THEME) \
  createTableItem(getExtraInfoTableItemY, EXTRA_INFO_TABLE_ITEM_X, ITEM_REF, ITEM_INDEX, THEME)

#define STAT_LABEL_BASE_X SPECIES_TEXT_X
#define STAT_LABEL_BASE_Y (HEADER_BACKGROUND_HEIGHT + 20)
#define STAT_LABEL_WIDTH 400
#define STAT_LABEL_TEXT_X getLabelTextX(STAT_LABEL_BASE_X)
#define getStatLabelTextY(ITEM_INDEX) (STAT_LABEL_BASE_Y + LABEL_PADDING)
#define createStatLabelText(ITEM_REF, THEME) createTableItem(getStatLabelTextY, STAT_LABEL_TEXT_X, ITEM_REF, 0, THEME)

#define INSTRUCTION_LABEL_BASE_X TITLE_TEXT_X
#define INSTRUCTION_LABEL_BASE_Y (HEADER_BACKGROUND_HEIGHT + 20)
#define INSTRUCTION_LABEL_WIDTH EXTRA_INFO_TABLE_WIDTH
#define INSTRUCTION_LABEL_TEXT_X getLabelTextX(INSTRUCTION_LABEL_BASE_X)
#define getInstructionLabelTextY(ITEM_INDEX) (INSTRUCTION_LABEL_BASE_Y + LABEL_PADDING)
#define createInstructionLabelText(ITEM_REF, THEME) createTableItem(getInstructionLabelTextY, INSTRUCTION_LABEL_TEXT_X, ITEM_REF, 0, THEME)

#define SPECIES_SPRITE_X (MOVE_TABLE_BASE_X + MOVE_TABLE_WIDTH)
// Sprites have padding on top we don't care about
#define SPECIES_SPRITE_Y (MOVE_TABLE_BASE_Y - 50)

#define STAT_WHEEL_CENTER_X (SPECIES_TEXT_X + 176)
#define STAT_WHEEL_CENTER_Y 298
// Add 3 so 0 is slightly above the center of the wheel
#define scaleStatPoint(vertexX, stat, maxStat) ((vertexX * (stat + 4)) / (maxStat + 4))

PokemonSummaryLayout::PokemonSummaryLayout() : Layout::Layout() {
  auto theme = gsets.GetTheme();

  m_instructionLabelBackground = RoundedRectangle::New(INSTRUCTION_LABEL_BASE_X, INSTRUCTION_LABEL_BASE_Y, INSTRUCTION_LABEL_WIDTH, LABEL_HEIGHT,
                                                       theme.background.light, TABLE_BORDER_RADIUS);
  createInstructionLabelText(m_instructionsTextBlock, theme);

  m_spriteImage = pu::ui::elm::Image::New(SPECIES_SPRITE_X, SPECIES_SPRITE_Y, "");
  m_headerBackground = pu::ui::elm::Rectangle::New(0, 0, SCREEN_MAX_WIDTH, HEADER_BACKGROUND_HEIGHT, theme.background.light, 50);
  m_speciesNameTextBlock = pu::ui::elm::TextBlock::New(SPECIES_TEXT_X, HEADER_TEXT_Y, "", HEADER_FONT_SIZE);
  m_speciesNameTextBlock->SetColor(theme.text.light);
  m_titleTextBlock = pu::ui::elm::TextBlock::New(TITLE_TEXT_X, HEADER_TEXT_Y, "", HEADER_FONT_SIZE);
  m_titleTextBlock->SetColor(theme.text.light);

  SDL_Point hpPoint = {0, -100};
  SDL_Point atkPoint = {86, -50};
  SDL_Point defPoint = {86, 50};
  SDL_Point spePoint = {0, 100};
  SDL_Point spdPoint = {-86, 50};
  SDL_Point spaPoint = {-86, -50};
  std::vector<SDL_Point> points = {hpPoint, atkPoint, defPoint, spePoint, spdPoint, spaPoint};

  m_statLabelBackground =
      RoundedRectangle::New(STAT_LABEL_BASE_X, STAT_LABEL_BASE_Y, STAT_LABEL_WIDTH, LABEL_HEIGHT, theme.background.light, TABLE_BORDER_RADIUS);
  createStatLabelText(m_statTextBlock, theme);

  m_hpStatTextBlock = pu::ui::elm::TextBlock::New(hpPoint.x + STAT_WHEEL_CENTER_X - 30, hpPoint.y + STAT_WHEEL_CENTER_Y - 30, "", 20);
  m_hpStatTextBlock->SetColor(theme.text.light);
  m_atkStatTextBlock = pu::ui::elm::TextBlock::New(atkPoint.x + STAT_WHEEL_CENTER_X + 20, atkPoint.y + STAT_WHEEL_CENTER_Y - 20, "", 20);
  m_atkStatTextBlock->SetColor(theme.text.light);
  m_defStatTextBlock = pu::ui::elm::TextBlock::New(defPoint.x + STAT_WHEEL_CENTER_X + 20, defPoint.y + STAT_WHEEL_CENTER_Y, "", 20);
  m_defStatTextBlock->SetColor(theme.text.light);
  m_speStatTextBlock = pu::ui::elm::TextBlock::New(spePoint.x + STAT_WHEEL_CENTER_X - 40, spePoint.y + STAT_WHEEL_CENTER_Y + 10, "", 20);
  m_speStatTextBlock->SetColor(theme.text.light);
  m_spdStatTextBlock = pu::ui::elm::TextBlock::New(spdPoint.x + STAT_WHEEL_CENTER_X - 90, spdPoint.y + STAT_WHEEL_CENTER_Y, "", 20);
  m_spdStatTextBlock->SetColor(theme.text.light);
  m_spaStatTextBlock = pu::ui::elm::TextBlock::New(spaPoint.x + STAT_WHEEL_CENTER_X - 90, spaPoint.y + STAT_WHEEL_CENTER_Y - 20, "", 20);
  m_spaStatTextBlock->SetColor(theme.text.light);

  m_outerStatPolygon = Polygon::New(STAT_WHEEL_CENTER_X, STAT_WHEEL_CENTER_Y, theme.background.light);
  m_outerStatPolygon->SetPoints(points);
  m_innerStatPolygon = Polygon::New(STAT_WHEEL_CENTER_X, STAT_WHEEL_CENTER_Y, theme.primary.a90);
  m_innerStatPolygon->SetPoints(points);

  m_moveTableBackground =
      RoundedRectangle::New(MOVE_TABLE_BASE_X, MOVE_TABLE_BASE_Y, MOVE_TABLE_WIDTH, MOVE_TABLE_HEIGHT, theme.background.light, TABLE_BORDER_RADIUS);
  createMoveTableItem(m_move1TextBlock, 0, theme);
  createMoveTableItem(m_move2TextBlock, 1, theme);
  createMoveTableItem(m_move3TextBlock, 2, theme);
  createMoveTableItem(m_move4TextBlock, 3, theme);

  m_mainInfoTableBackground = RoundedRectangle::New(MAIN_INFO_TABLE_BASE_X, MAIN_INFO_TABLE_BASE_Y, MAIN_INFO_TABLE_WIDTH, MAIN_INFO_TABLE_HEIGHT,
                                                    theme.background.light, TABLE_BORDER_RADIUS);
  createMainInfoTableItem(m_natureTextBlock, 0, theme);
  createMainInfoTableItem(m_mintedNatureTextBlock, 1, theme);
  createMainInfoTableItem(m_abilityTextBlock, 2, theme);

  m_extraInfoTableBackground = RoundedRectangle::New(EXTRA_INFO_TABLE_BASE_X, EXTRA_INFO_TABLE_BASE_Y, EXTRA_INFO_TABLE_WIDTH,
                                                     EXTRA_INFO_TABLE_HEIGHT, theme.background.light, TABLE_BORDER_RADIUS);
  createExtraInfoTableItem(m_pidEcTextBlock, 0, theme);
  createExtraInfoTableItem(m_shinyInfoTextBlock, 1, theme);
  createExtraInfoTableItem(m_friendshipTextBlock, 2, theme);

  this->Add(m_outerStatPolygon);

  for (u32 i = 0; i < points.size(); i++) {
    auto point1 = points[i];
    u32 point2Index = i + 1 == points.size() ? 0 : i + 1;
    auto point2 = points[point2Index];
    auto innerLine =
        Line::New(point1.x + STAT_WHEEL_CENTER_X, point1.y + STAT_WHEEL_CENTER_Y, STAT_WHEEL_CENTER_X, STAT_WHEEL_CENTER_Y, theme.text.dark);
    auto borderLine = Line::New(point1.x + STAT_WHEEL_CENTER_X, point1.y + STAT_WHEEL_CENTER_Y, point2.x + STAT_WHEEL_CENTER_X,
                                point2.y + STAT_WHEEL_CENTER_Y, theme.text.dark);
    this->Add(innerLine);
    this->Add(borderLine);
  }

  this->Add(m_innerStatPolygon);
  this->Add(m_hpStatTextBlock);
  this->Add(m_atkStatTextBlock);
  this->Add(m_defStatTextBlock);
  this->Add(m_speStatTextBlock);
  this->Add(m_spdStatTextBlock);
  this->Add(m_spaStatTextBlock);
  this->Add(m_statLabelBackground);
  this->Add(m_statTextBlock);
  this->Add(m_headerBackground);
  this->Add(m_spriteImage);
  this->Add(m_speciesNameTextBlock);
  this->Add(m_titleTextBlock);
  this->Add(m_moveTableBackground);
  this->Add(m_move1TextBlock);
  this->Add(m_move2TextBlock);
  this->Add(m_move3TextBlock);
  this->Add(m_move4TextBlock);
  this->Add(m_mainInfoTableBackground);
  this->Add(m_natureTextBlock);
  this->Add(m_mintedNatureTextBlock);
  this->Add(m_abilityTextBlock);
  this->Add(m_extraInfoTableBackground);
  this->Add(m_pidEcTextBlock);
  this->Add(m_shinyInfoTextBlock);
  this->Add(m_friendshipTextBlock);
  this->Add(m_instructionLabelBackground);
  this->Add(m_instructionsTextBlock);
}

void PokemonSummaryLayout::UpdateValues(std::string title, std::shared_ptr<csight::PK8> pkm, bool isShowingExtraDetail) {
  std::string detailKey = isShowingExtraDetail ? "Hide detail (X)" : "More detail (X)";
  std::string instructions = i18n->Translate(detailKey) + ", " + i18n->Translate("Raid Searcher (Y)");
  std::string species = i18n->Translate("species", pkm->GetSpeciesString());
  std::string nature = i18n->Translate("Nature") + ": " + i18n->Translate("natures", pkm->GetNatureString());
  std::string mintedNature = i18n->Translate("Minted Nature") + ": " + i18n->Translate("natures", pkm->GetMintedNatureString());
  std::string ability = i18n->Translate("Ability") + ": " + i18n->Translate("abilities", pkm->GetAbilityString());
  std::string shinyTranslationKey = pkm->GetIsShiny() ? "Shiny" : "Not Shiny";
  std::string shiny = i18n->Translate("PSV") + " " + std::to_string(pkm->GetPSV()) + ", " + i18n->Translate("TSV") + " " +
                      std::to_string(pkm->GetTSV()) + ", " + i18n->Translate(shinyTranslationKey);
  std::string pidText = isShowingExtraDetail ? csight::utils::convertNumToHexString(pkm->GetPID()) : "———";
  std::string ecText = isShowingExtraDetail ? csight::utils::convertNumToHexString(pkm->GetEncryptionConstant()) : "———";
  std::string pidEc = i18n->Translate("PID") + ": " + pidText + ", " + i18n->Translate("EC") + ": " + ecText;
  std::string friendshipTranslationKey = pkm->GetIsEgg() ? "Egg cycles" : "Friendship";
  std::string friendship = i18n->Translate(friendshipTranslationKey) + ": " + std::to_string(pkm->GetCurrentFriendship());
  std::string statTypeText = i18n->Translate(m_statType == statType::ivs ? "IVs" : "EVs") + " - " + i18n->Translate("Switch (A)");

  s32 maxStat = m_statType == statType::ivs ? 31 : 255;
  auto stats = m_statType == statType::ivs ? pkm->GetIVs() : pkm->GetEVs();
  auto hp = stats[0];
  auto atk = stats[1];
  auto def = stats[2];
  auto spa = stats[3];
  auto spd = stats[4];
  auto spe = stats[5];

  std::vector<SDL_Point> innerIVPoints = {{0, scaleStatPoint(-100, hp, maxStat)},
                                          {scaleStatPoint(86, atk, maxStat), scaleStatPoint(-50, atk, maxStat)},
                                          {scaleStatPoint(86, def, maxStat), scaleStatPoint(50, def, maxStat)},
                                          {0, scaleStatPoint(100, spe, maxStat)},
                                          {scaleStatPoint(-86, spd, maxStat), scaleStatPoint(50, spd, maxStat)},
                                          {scaleStatPoint(-86, spa, maxStat), scaleStatPoint(-50, spa, maxStat)}};
  m_innerStatPolygon->SetPoints(innerIVPoints);

  setPokemonSprite(m_spriteImage, 4, pkm->GetSpecies(), pkm->GetIsEgg());
  m_instructionsTextBlock->SetText(instructions);
  m_speciesNameTextBlock->SetText(species);
  m_statTextBlock->SetText(statTypeText);
  m_hpStatTextBlock->SetText("HP: " + std::to_string(hp));
  m_atkStatTextBlock->SetText("ATK: " + std::to_string(atk));
  m_defStatTextBlock->SetText("DEF: " + std::to_string(def));
  m_speStatTextBlock->SetText("SPE: " + std::to_string(spe));
  m_spdStatTextBlock->SetText("SPD: " + std::to_string(spd));
  m_spaStatTextBlock->SetText("SPA: " + std::to_string(spa));
  m_titleTextBlock->SetText(title);
  m_shinyInfoTextBlock->SetText(shiny);
  m_move1TextBlock->SetText(i18n->Translate("moves", pkm->GetMoveString(0)));
  m_move2TextBlock->SetText(i18n->Translate("moves", pkm->GetMoveString(1)));
  m_move3TextBlock->SetText(i18n->Translate("moves", pkm->GetMoveString(2)));
  m_move4TextBlock->SetText(i18n->Translate("moves", pkm->GetMoveString(3)));
  m_natureTextBlock->SetText(nature);
  m_mintedNatureTextBlock->SetText(mintedNature);
  m_abilityTextBlock->SetText(ability);
  m_friendshipTextBlock->SetText(friendship);
  m_pidEcTextBlock->SetText(pidEc);
}

statType::StatType PokemonSummaryLayout::GetStatType() {
  return m_statType;
}

void PokemonSummaryLayout::SetStatType(statType::StatType _statType) {
  m_statType = _statType;
}