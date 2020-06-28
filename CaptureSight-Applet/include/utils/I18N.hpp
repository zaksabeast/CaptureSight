#pragma once

#include <string>
#include <utils/json.hpp>
#include <vector>

std::string GetTranslationCode();

class I18N {
 public:
  I18N();
  void LoadTranslations();
  std::string Translate(std::string word);
  std::string Translate(std::string category, std::string word);

 private:
};
