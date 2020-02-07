#include <tesla.hpp>
#include <ui/MainApplication.hpp>

extern MainApplication* mainApp;

tsl::Overlay* overlayLoad() {
  mainApp = new MainApplication();
  return mainApp;
}