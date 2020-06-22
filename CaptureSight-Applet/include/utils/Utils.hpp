#pragma once

#include <csight/core>
#include <memory>
#include <string>

namespace utils {
  std::string getPokemonIconPath(std::shared_ptr<csight::PKM> pkm);
}  // utils