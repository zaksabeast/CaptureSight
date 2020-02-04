#pragma once

#include <vector>
#include <string>
#include <utils/json.hpp>

std::string GetTranslationCode();

class I18N {
 public:
  I18N();
  std::string Translate(std::string word);
  std::string Translate(std::string category, std::string word);

 private:
  nlohmann::json translations;
  void LoadTranslations();
};
