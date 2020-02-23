#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <switch.h>
#include <utils/I18N.hpp>

std::string GetTranslationCode() {
  u64 languageCode = 0;
  SetLanguage language = SetLanguage_ENUS;
  setGetSystemLanguage(&languageCode);
  setMakeLanguage(languageCode, &language);
  switch (language) {
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
  this->LoadTranslations();
}

void I18N::LoadTranslations() {
  std::ifstream translations("romfs:/i18n/" + GetTranslationCode() + ".json");

  if (translations.good()) {
    translations >> m_translations;
  }

  translations.close();
}

std::string I18N::Translate(std::string word) {
  return m_translations["app"].value(word, word);
}

std::string I18N::Translate(std::string category, std::string word) {
  return m_translations.at(category).value(word, word);
}