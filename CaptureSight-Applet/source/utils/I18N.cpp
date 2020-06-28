#include <fstream>
#include <stdio.h>
#include <string>
#include <switch.h>
#include <utils/I18N.hpp>
#include <vector>

nlohmann::json g_translations;

std::string getTranslationCode() {
  u64 languageCode = 0;
  SetLanguage language = SetLanguage_ENUS;
  setGetSystemLanguage(&languageCode);
  setMakeLanguage(languageCode, &language);
  switch (language) {
    case SetLanguage_DE:
      return "de";
    case SetLanguage_FR:
    case SetLanguage_FRCA:
      return "fr";
    case SetLanguage_ZHCN:
    case SetLanguage_ZHHANS:
      return "chs";
    case SetLanguage_ZHTW:
    case SetLanguage_ZHHANT:
      return "cht";
    case SetLanguage_IT:
      return "it";
    case SetLanguage_ENUS:
    case SetLanguage_ENGB:
    default:
      return "en";
  }
}

I18N::I18N() {
  this->loadTranslations();
}

void I18N::loadTranslations() {
  std::ifstream translations("romfs:/i18n/" + getTranslationCode() + ".json");

  if (translations.good()) {
    translations >> g_translations;
  }

  translations.close();
}

std::string I18N::translate(std::string word) {
  return g_translations["app"].value(word, word);
}

std::string I18N::translate(std::string category, std::string word) {
  return g_translations.at(category).value(word, word);
}