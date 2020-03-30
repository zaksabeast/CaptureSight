
/*

    Plutonium library

    @file Rectangle.hpp
    @brief A Rectangle is an Element which simply draws a filled rectangle.
    @author XorTroll

    @copyright Plutonium project - an easy-to-use UI framework for Nintendo Switch homebrew

*/

// Modified to use border radius

#pragma once
#include <pu/Plutonium>

class RoundedRectangle : public pu::ui::elm::Element {
 public:
  RoundedRectangle(s32 X, s32 Y, s32 Width, s32 Height, pu::ui::Color RecColor, s32 BorderRadius = 0);
  PU_SMART_CTOR(RoundedRectangle)

  s32 GetX();
  void SetX(s32 X);
  s32 GetY();
  void SetY(s32 Y);
  s32 GetWidth();
  void SetWidth(s32 Width);
  s32 GetHeight();
  void SetHeight(s32 Height);
  s32 GetBorderRadius();
  void SetBorderRadius(s32 Radius);
  pu::ui::Color GetColor();
  void SetColor(pu::ui::Color RecColor);
  void OnRender(pu::ui::render::Renderer::Ref &Drawer, s32 X, s32 Y);
  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);

 private:
  s32 m_borderr;
  s32 m_x;
  s32 m_y;
  s32 m_w;
  s32 m_h;
  pu::ui::Color m_clr;
};