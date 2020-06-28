#pragma once

#include <string>
#include <utils/json.hpp>
#include <vector>

std::string getTranslationCode();

class I18N {
 public:
  I18N();
  void loadTranslations();
  std::string translate(std::string word);
  std::string translate(std::string category, std::string word);

 private:
};
