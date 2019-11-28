#pragma once

#include <pu/Plutonium>

struct ThemeColor {
  pu::ui::Color light;
  pu::ui::Color dark;
};

struct Theme {
  ThemeColor background;
  ThemeColor text;
  ThemeColor active;
};

class Settings {
 public:
  Theme GetTheme();

 private:
  Theme theme = {
      {pu::ui::Color::FromHex("#4d4d4d"), pu::ui::Color::FromHex("#3d3d3d")},
      {pu::ui::Color::FromHex("#ffffff"), pu::ui::Color::FromHex("#ebebeb")},
      {pu::ui::Color::FromHex("#9a9a9a"), pu::ui::Color::FromHex("#575757")},
  };
};