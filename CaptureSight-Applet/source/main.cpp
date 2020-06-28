#include <borealis.hpp>
#include <csight/core>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <switch.h>
#include <ui/views/MainApplication.hpp>
#include <vector>

std::shared_ptr<csight::GameReader> g_gameReader;

int main(int argc, char *argv[]) {
  // Init the app
  setInitialize();
  dmntchtInitialize();
  dmntchtForceOpenCheatProcess();

  brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

  if (!brls::Application::init("CaptureSight")) {
    brls::Logger::error("Unable to init CaptureSight");
    return EXIT_FAILURE;
  }

  g_gameReader = std::make_shared<csight::GameReader>(false);
  bool isDebugServiceRunning = g_gameReader->GetIsServiceRunning();

  if (!isDebugServiceRunning) {
    brls::Application::crash("Atmosphere's dmnt:cht is not running");
  } else if (R_FAILED(g_gameReader->Attach()) || !g_gameReader->GetIsPokemonRunning()) {
    brls::Application::crash("Please start a Pokemon game before running CaptureSight");
  } else {
    brls::Application::pushView(new ui::MainView());
  }

  while (brls::Application::mainLoop())
    ;

  // Exit
  dmntchtExit();
  setExit();
  return EXIT_SUCCESS;
}
