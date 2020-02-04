#include <tesla.hpp>
#include <ui/MainApplication.hpp>

extern MainApplication* mainApp;

// This function will get called once on startup to load the overlay
tsl::Overlay* overlayLoad() {
  mainApp = new MainApplication();
  return mainApp;
}