#include <memory>
#include <stratosphere.hpp>
#include <ui/MainApplication.hpp>
#include <utils/I18N.hpp>
#include <utils/Settings.hpp>

MainApplication::Ref mainApp;
Settings gsets;
std::shared_ptr<I18N> i18n;

#define SETUP_LAYOUT(Class, m_layout) \
  m_layout = Class::New();            \
  m_layout->SetBackgroundColor(gsets.GetTheme().background.dark);

void MainApplication::OnLoad() {
  // Change default font to load characters properly (chs cht ko)
  std::string language = GetTranslationCode();
  if (language.compare("chs") == 0 || language.compare("cht") == 0)
    pu::ui::render::SetDefaultFontFromShared(
        pu::ui::render::SharedFont::ChineseSimplified);  // ChineseTraditional doesn't work for cht!?

  m_gameReader = std::make_shared<csight::GameReader>();
  bool isDebugServiceRunning = m_gameReader->GetIsServiceRunning();

  m_warningLayout = WarningLayout::New();
  m_warningLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->SetOnInput(std::bind(&MainApplication::OnWarningInput, this, std::placeholders::_1, std::placeholders::_2,
                             std::placeholders::_3, std::placeholders::_4));

  if (!isDebugServiceRunning) {
    std::string warningTranslationKey = "Atmosphere's dmnt:cht is not running";
    std::string warningText = i18n->Translate(warningTranslationKey);
    m_warningLayout->SetWarningText(warningText);
    this->NavigateTo(m_warningLayout);
    return;
  }

  Result rc = m_gameReader->Attach();

  if (R_FAILED(rc) || !m_gameReader->GetIsPokemonRunning()) {
    std::string warningTranslationKey = "Please start a Pokemon game before running CaptureSight";
    std::string warningText = i18n->Translate(warningTranslationKey) + "\ndmnt:cht result: " + std::to_string(rc);
    m_warningLayout->SetWarningText(warningText);
    this->NavigateTo(m_warningLayout);
    return;
  }

  m_pkms = m_gameReader->ReadParty();
  m_dens = m_gameReader->ReadDens(false);

  m_versionTextBlock = pu::ui::elm::TextBlock::New(50, 50, CSIGHT_VERION, 25);
  m_versionTextBlock->SetColor(gsets.GetTheme().text.light);

  SETUP_LAYOUT(PokemonSummaryLayout, m_pokemonSummaryLayout);
  m_pokemonSummaryLayout->SetOnInput(std::bind(&MainApplication::OnInputPokemonSummaryLayout, this, std::placeholders::_1,
                                               std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  SETUP_LAYOUT(PokemonTypeLayout, m_pokemonTypeLayout);

  SETUP_LAYOUT(MainMenuLayout, m_mainMenuLayout);
  m_mainMenuLayout->SetOnInputMenuItem(std::bind(&MainApplication::SetViewMode, this, std::placeholders::_1));
  m_mainMenuLayout->Add(m_versionTextBlock);

  SETUP_LAYOUT(PokemonListLayout, m_pokemonListLayout);
  m_pokemonListLayout->SetOnInputMenuItem(std::bind(&MainApplication::SelectPokemonSlot, this, std::placeholders::_1));
  m_pokemonListLayout->UpdateValues(m_pkms, m_GetSummaryTitle);
  m_pokemonListLayout->SetOnInput(std::bind(&MainApplication::OnInputPokemonListLayout, this, std::placeholders::_1,
                                            std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  SETUP_LAYOUT(RaidSearchResultLayout, m_raidSearchResultLayout);
  m_raidSearchResultLayout->SetOnInput(std::bind(&MainApplication::OnInputRaidSearchResultLayout, this, std::placeholders::_1,
                                                 std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  SETUP_LAYOUT(DenMenuLayout, m_denMenuLayout);
  m_denMenuLayout->SetOnInputMenuItem(std::bind(&MainApplication::OnInputDenList, this, std::placeholders::_1));
  m_denMenuLayout->UpdateValues(m_dens);
  m_denMenuLayout->SetOnInput(std::bind(&MainApplication::OnInputDenMenuLayout, this, std::placeholders::_1,
                                        std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  SETUP_LAYOUT(RaidSearchSettingsLayout, m_raidSearchSettingsLayout);
  m_raidSearchSettingsLayout->SetOnInput(std::bind(&MainApplication::OnInputRaidSearchSettingsLayout, this, std::placeholders::_1,
                                                   std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
  m_raidSearchSettingsLayout->UpdateValues();
  m_raidSearchSettings->AddUpdateCallback(std::bind(&RaidSearchSettingsLayout::UpdateValues, m_raidSearchSettingsLayout));
  m_raidSearchSettings->AddUpdateCallback(std::bind(&RaidSearchResultLayout::UpdateValues, m_raidSearchResultLayout));

  this->SetOnInput(std::bind(&MainApplication::OnMainApplicationInput, this, std::placeholders::_1, std::placeholders::_2,
                             std::placeholders::_3, std::placeholders::_4));
  this->NavigateTo(m_mainMenuLayout);
}

void MainApplication::OnWarningInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_PLUS) {
    dmntchtExit();
    this->CloseWithFadeOut();
  }
}

void MainApplication::OnMainApplicationInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_PLUS) {
    dmntchtExit();
    this->CloseWithFadeOut();
  } else if (Down & KEY_X) {
    m_isShowingExtraDetail = !m_isShowingExtraDetail;
    this->RefreshSummaryLayout();
  } else if (Down & KEY_B) {
    this->NavigateBack();
  }
}

void MainApplication::OnInputDenList(u64 seed) {
  m_raidSearchSettings->SetSeed(seed);
  this->NavigateTo(m_raidSearchResultLayout);
}

void MainApplication::OnInputPokemonListLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_L) {
    this->DecreaseSlot(30);
  } else if (Down & KEY_R) {
    this->IncreaseSlot(30);
  } else if (Down & KEY_Y) {
    auto slot = m_pokemonListLayout->GetSelectedIndex();
    auto pkm = m_pkms[slot];
    this->ShowPKMTypeMatchUps(pkm);
  }
}

void MainApplication::OnInputDenMenuLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_Y) {
    auto slot = m_denMenuLayout->GetSelectedIndex();
    auto pkm = m_dens[slot]->GetPKM();
    this->ShowPKMTypeMatchUps(pkm);
  }
}

void MainApplication::ShowPKMTypeMatchUps(std::shared_ptr<csight::PKM> pkm) {
  auto weaknesses = pkm->GetWeaknesses();
  m_pokemonTypeLayout->SetTypeMatchUps(weaknesses);
  this->NavigateTo(m_pokemonTypeLayout);
}

void MainApplication::SelectPokemonSlot(u32 slot) {
  this->SetSlot(slot);
  this->NavigateTo(m_pokemonSummaryLayout);
}

void MainApplication::SetViewMode(ViewMode viewMode) {
  switch (viewMode) {
    case activeDens:
      m_dens = m_gameReader->ReadDens(false);
      m_denMenuLayout->UpdateValues(m_dens);
      this->NavigateTo(m_denMenuLayout);
      return;
    case allDens:
      m_dens = m_gameReader->ReadDens(true);
      m_denMenuLayout->UpdateValues(m_dens);
      this->NavigateTo(m_denMenuLayout);
      return;
    case wild:
      m_GetSummaryTitle = std::bind(&MainApplication::GetWildSummaryTitle, this, std::placeholders::_1);
      m_pkms = std::vector<std::shared_ptr<csight::PK8>> {
        m_gameReader->ReadWild(),
        m_gameReader->ReadRaid(),
        m_gameReader->ReadTrade(),
      };
      break;
    case box:
      m_GetSummaryTitle = std::bind(&MainApplication::GetBoxSummaryTitle, this, std::placeholders::_1);
      m_pkms = m_gameReader->ReadBoxes();
      break;
    case party:
    default:
      m_GetSummaryTitle = std::bind(&MainApplication::GetPartySummaryTitle, this, std::placeholders::_1);
      m_pkms = m_gameReader->ReadParty();
      break;
  }

  m_slot = 0;
  m_maxSlot = m_pkms.size() - 1;
  m_pokemonListLayout->UpdateValues(m_pkms, m_GetSummaryTitle);
  this->NavigateTo(m_pokemonListLayout);
}

void MainApplication::NavigateTo(std::shared_ptr<pu::ui::Layout> layout) {
  m_navigationHistory.push_back(layout);
  this->LoadLayout(layout);
}

void MainApplication::NavigateBack() {
  if (m_navigationHistory.size() > 1)
    m_navigationHistory.pop_back();

  this->LoadLayout(m_navigationHistory.back());
}

std::string MainApplication::GetWildSummaryTitle(u32 slot) {
  std::string translationKey;

  switch (slot) {
    case 0:
      translationKey = "Wild Pokemon";
      break;
    case 1:
      translationKey = "Raid Pokemon";
      break;
    case 2:
    default:
      translationKey = "Trade Pokemon";
      break;
  }

  return i18n->Translate(translationKey);
}

std::string MainApplication::GetBoxSummaryTitle(u32 slot) {
  u32 box = (slot / 30) + 1;
  u32 boxSlot = (slot % 30) + 1;
  return i18n->Translate("Box") + " " + std::to_string(box) + ", " + i18n->Translate("Slot") + " " + std::to_string(boxSlot);
}

std::string MainApplication::GetPartySummaryTitle(u32 slot) {
  return i18n->Translate("Party") + " " + std::to_string(slot + 1);
}

void MainApplication::OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_DLEFT) {
    this->DecreaseSlot(1);
  } else if (Down & KEY_DRIGHT) {
    this->IncreaseSlot(1);
  } else if (Down & KEY_Y) {
    auto seedFuture = m_pkms[m_slot]->GetRaidSeedAsync();
    while (csight::utils::waitingInterval(&seedFuture, 500)) {
      m_pokemonSummaryLayout->Tick();
      Application::CallForRender();
    }

    m_raidSearchSettings->SetSeed(seedFuture.get());
    this->NavigateTo(m_raidSearchResultLayout);
    // Resets state for when the user navigates back
    this->RefreshSummaryLayout();
  } else if (Down & KEY_A) {
    auto nextStatType = m_pokemonSummaryLayout->GetStatType() == statType::ivs ? statType::evs : statType::ivs;
    m_pokemonSummaryLayout->SetStatType(nextStatType);
    this->RefreshSummaryLayout();
  }
}

void MainApplication::OnInputRaidSearchResultLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_A) {
    this->NavigateTo(m_raidSearchSettingsLayout);
  }
}

void MainApplication::OnInputRaidSearchSettingsLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_A) {
    this->NavigateBack();
  }
}

void MainApplication::RefreshSummaryLayout() {
  this->SetSlot(m_slot);
}

void MainApplication::SetSlot(u32 newSlot) {
  m_slot = newSlot > m_maxSlot ? m_maxSlot : newSlot;
  m_pokemonListLayout->SetSelectedIndex(m_slot);
  std::string summaryTitle = m_GetSummaryTitle(m_slot);
  m_pokemonSummaryLayout->UpdateValues(summaryTitle, m_pkms[m_slot], m_isShowingExtraDetail);
}

u32 MainApplication::GetSlot() {
  return m_slot;
}

void MainApplication::IncreaseSlot(u32 slotIncrease) {
  u32 newSlot = m_slot + slotIncrease;
  u32 slot = newSlot > m_maxSlot ? 0 : newSlot;
  this->SetSlot(slot);
}

void MainApplication::DecreaseSlot(u32 slotDecrease) {
  u32 newSlot = m_slot - slotDecrease;
  u32 slot = newSlot >= m_maxSlot ? m_maxSlot : newSlot;
  this->SetSlot(slot);
}

std::shared_ptr<csight::GameReader> MainApplication::GetGameReader() {
  return m_gameReader;
}

std::shared_ptr<csight::raid::RaidSearchSettings> MainApplication::GetRaidSearchSettings() {
  return m_raidSearchSettings;
}