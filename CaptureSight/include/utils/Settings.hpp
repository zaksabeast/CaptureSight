#pragma once

#include <pu/Plutonium>

struct ThemeColor {
  pu::ui::Color light;
  pu::ui::Color dark;
  pu::ui::Color a90;
};

struct Theme {
  ThemeColor background;
  ThemeColor text;
  ThemeColor active;
  ThemeColor primary;
};

class Settings {
 public:
  Theme GetTheme();

 private:
  Theme m_theme = { { pu::ui::Color::FromHex("#4d4d4d"), pu::ui::Color::FromHex("#3d3d3d"), pu::ui::Color::FromHex("#4d4d4de6") },
                    { pu::ui::Color::FromHex("#ffffff"), pu::ui::Color::FromHex("#bcbcbc"), pu::ui::Color::FromHex("#ffffffe6") },
                    { pu::ui::Color::FromHex("#9a9a9a"), pu::ui::Color::FromHex("#575757"), pu::ui::Color::FromHex("#9a9a9ae6") },
                    { pu::ui::Color::FromHex("#008bc7"), pu::ui::Color::FromHex("#002ec7"), pu::ui::Color::FromHex("#008bc7e6") } };
};