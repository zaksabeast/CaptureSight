#include <memory>
#include <stratosphere.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>
#include <utils/I18N.hpp>

MainApplication::Ref mainApp;
Settings gsets;
std::shared_ptr<I18N> i18n;

void MainApplication::OnLoad() {
  this->save = std::make_unique<GameReader>();
  bool isDebugServiceRunning = this->save->GetIsServiceRunning();

  this->warningLayout = WarningLayout::New();
  this->warningLayout->SetBackgroundColor(gsets.GetTheme().background.dark);

  if (!isDebugServiceRunning) {
    std::string warningTranslationKey = "Atmosphere's dmnt:cht is not running";
    std::string warningText = i18n->Translate(warningTranslationKey);
    this->warningLayout->SetWarningText(warningText);
    this->LoadLayout(this->warningLayout);
    return;
  }

  Result rc = this->save->Attach();

  if (R_FAILED(rc) || !this->save->GetIsPokemonRunning()) {
    std::string warningTranslationKey = "Please start a Pokemon game before running CaptureSight";
    std::string warningText = i18n->Translate(warningTranslationKey) + "\ndmnt:cht result: " + std::to_string(rc);
    this->warningLayout->SetWarningText(warningText);
    this->LoadLayout(this->warningLayout);
    return;
  }

  this->pokemonSummaryLayout = PokemonSummaryLayout::New();
  this->pokemonSummaryLayout->SetOnInput(std::bind(&MainApplication::OnInputPokemonSummaryLayout, this, std::placeholders::_1, std::placeholders::_2,
                                                   std::placeholders::_3, std::placeholders::_4));
  this->pokemonSummaryLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->mainMenuLayout = MainMenuLayout::New();
  this->mainMenuLayout->SetOnInputMenuItem(std::bind(&MainApplication::SetViewMode, this, std::placeholders::_1));
  this->mainMenuLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->pokemonListLayout = PokemonListLayout::New();
  this->pokemonListLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->pokemonListLayout->SetOnInputMenuItem(std::bind(&MainApplication::SelectPokemonSlot, this, std::placeholders::_1));
  this->denMenuLayout = DenMenuLayout::New();
  this->denMenuLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->SetOnInput(
      std::bind(&MainApplication::OnInput, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  this->LoadLayout(this->mainMenuLayout);
}

void MainApplication::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_PLUS) {
    dmntchtExit();
    this->CloseWithFadeOut();
  } else if (Down & KEY_X) {
    this->isShowingExtraDetail = !this->isShowingExtraDetail;
    this->RefreshSummaryLayout();
  } else if (Down & KEY_B) {
    this->LoadLayout(this->mainMenuLayout);
  } else if (Down & KEY_L) {
    this->DecreaseSlot(30);
  } else if (Down & KEY_R) {
    this->IncreaseSlot(30);
  }
}

void MainApplication::SelectPokemonSlot(u32 slot) {
  this->SetSlot(slot);
  this->LoadLayout(this->pokemonSummaryLayout);
}

void MainApplication::SetViewMode(ViewMode viewMode) {
  switch (viewMode) {
    case activeDens:
      this->dens = this->save->ReadDens(false);
      this->denMenuLayout->UpdateValues(this->dens);
      this->LoadLayout(this->denMenuLayout);
      return;
    case allDens:
      this->dens = this->save->ReadDens(true);
      this->denMenuLayout->UpdateValues(this->dens);
      this->LoadLayout(this->denMenuLayout);
      return;
    case wild:
      this->GetSummaryTitle = std::bind(&MainApplication::GetWildSummaryTitle, this, std::placeholders::_1);
      this->pkms = std::vector<std::shared_ptr<PK8>>{
          this->save->ReadWild(),
          this->save->ReadRaid(),
          this->save->ReadTrade(),
      };
      break;
    case box:
      this->GetSummaryTitle = std::bind(&MainApplication::GetBoxSummaryTitle, this, std::placeholders::_1);
      this->pkms = this->save->ReadBoxes();
      break;
    case party:
    default:
      this->GetSummaryTitle = std::bind(&MainApplication::GetPartySummaryTitle, this, std::placeholders::_1);
      this->pkms = this->save->ReadParty();
      break;
  }

  this->slot = 0;
  this->maxSlot = this->pkms.size() - 1;
  this->pokemonListLayout->UpdateValues(this->pkms, this->GetSummaryTitle);
  this->LoadLayout(this->pokemonListLayout);
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
  }
}

void MainApplication::RefreshSummaryLayout() {
  this->SetSlot(this->slot);
}

void MainApplication::SetSlot(u32 newSlot) {
  this->slot = this->slot > this->maxSlot ? this->maxSlot : newSlot;
  this->pokemonListLayout->SetSelectedIndex(this->slot);
  std::string summaryTitle = this->GetSummaryTitle(this->slot);
  this->pokemonSummaryLayout->UpdateValues(summaryTitle, this->pkms[this->slot].get(), this->isShowingExtraDetail);
}

u32 MainApplication::GetSlot() {
  return this->slot;
}

void MainApplication::IncreaseSlot(u32 slotIncrease) {
  u32 newSlot = this->slot + slotIncrease;
  u32 slot = newSlot >= this->maxSlot ? 0 : newSlot;
  this->SetSlot(slot);
}

void MainApplication::DecreaseSlot(u32 slotDecrease) {
  u32 newSlot = this->slot - slotDecrease;
  u32 slot = newSlot >= this->maxSlot ? this->maxSlot : newSlot;
  this->SetSlot(slot);
}
