#include <stratosphere.hpp>
#include <ui/MainApplication.hpp>
#include <utils/Settings.hpp>
#include <utils/I18n.hpp>

MainApplication::Ref mainApp;
Settings gsets;
std::shared_ptr<I18N> i18n;

void MainApplication::OnLoad() {
  if (R_FAILED(dmntchtInitialize()))
    this->Close();
  if (R_FAILED(dmntchtForceOpenCheatProcess()))
    this->Close();

  this->save = std::make_unique<GameReader>();
  this->pkms = this->save->ReadParty();

  this->pokemonSummaryLayout = PokemonSummaryLayout::New();
  this->pokemonSummaryLayout->SetOnInput(std::bind(&MainApplication::OnInputPokemonSummaryLayout, this, std::placeholders::_1, std::placeholders::_2,
                                                   std::placeholders::_3, std::placeholders::_4));
  this->pokemonSummaryLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->mainMenuLayout = MainMenuLayout::New();
  this->mainMenuLayout->SetOnInputMenuItem(std::bind(&MainApplication::SetViewMode, this, std::placeholders::_1));
  this->mainMenuLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->pokemonListLayout = PokemonListLayout::New();
  this->pokemonListLayout->SetBackgroundColor(gsets.GetTheme().background.dark);
  this->SetOnInput(
      std::bind(&MainApplication::OnInput, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

  this->LoadLayout(this->mainMenuLayout);
}

void MainApplication::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_PLUS) {
    dmntchtExit();
    this->CloseWithFadeOut();
  } else if (Down & KEY_X) {
    this->LoadLayout(this->mainMenuLayout);
  }
}

void MainApplication::SetViewMode(PokemonViewMode viewMode) {
  switch (viewMode) {
    case wild:
      this->pokemonSummaryTitle = "Wild Pokemon";
      this->pkms = this->save->ReadWild();
      break;
    case box:
      this->pokemonSummaryTitle = "Box Pokemon";
      this->pkms = this->save->ReadBoxes();
      break;
    case party:
    default:
      this->pokemonSummaryTitle = "Party Pokemon";
      this->pkms = this->save->ReadParty();
      break;
  }

  this->slot = 0;
  this->maxSlot = this->pkms.size() - 1;
  this->pokemonListLayout->UpdateValues(this->pkms);
  this->LoadLayout(this->pokemonListLayout);
}

void MainApplication::OnInputPokemonSummaryLayout(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {
  if (Down & KEY_DLEFT) {
    this->DecreaseSlot();
  } else if (Down & KEY_DRIGHT) {
    this->IncreaseSlot();
  }

  if (Down) {
    this->pokemonSummaryLayout->UpdateValues(this->pokemonSummaryTitle, this->pkms[this->GetSlot()].get());
  }
}

void MainApplication::SetSlot(u32 newSlot) {
  this->slot = this->slot > this->maxSlot ? this->maxSlot : newSlot;
  this->pokemonSummaryLayout->UpdateValues(this->pokemonSummaryTitle, this->pkms[this->slot].get());
}

u32 MainApplication::GetSlot() {
  return this->slot;
}

void MainApplication::IncreaseSlot() {
  this->slot = this->slot >= this->maxSlot ? 0 : this->slot + 1;
}

void MainApplication::DecreaseSlot() {
  this->slot = this->slot <= 0 ? this->maxSlot : this->slot - 1;
}

PokemonSummaryLayout::Ref MainApplication::GetPokemonSummaryLayout() {
  return this->pokemonSummaryLayout;
}

MainMenuLayout::Ref MainApplication::GetMainMenuLayout() {
  return this->mainMenuLayout;
}

PokemonListLayout::Ref MainApplication::GetPokemonListLayout() {
  return this->pokemonListLayout;
}