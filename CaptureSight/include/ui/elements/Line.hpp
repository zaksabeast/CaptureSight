#pragma once
#include <pu/Plutonium>
#include <vector>

class Line : public pu::ui::elm::Element {
 public:
  Line(s32 x1, s32 y1, s32 x2, s32 y2, pu::ui::Color LineColor);
  PU_SMART_CTOR(Line)

  s32 GetX();
  s32 GetY();
  s32 GetWidth();
  s32 GetHeight();
  void OnRender(pu::ui::render::Renderer::Ref &Drawer, s32 X, s32 Y);
  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);

 private:
  s32 m_x1;
  s32 m_y1;
  s32 m_x2;
  s32 m_y2;
  pu::sdl2::Renderer m_renderer;
  pu::ui::Color m_clr;
};