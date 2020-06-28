#pragma once

#include <string>
#include <utils/json.hpp>
#include <vector>

std::string getTranslationCode();

class I18N {
 public:
  I18N();
  static void loadTranslations();
  static std::string translate(std::string word);
  static std::string translate(std::string category, std::string word);
};
