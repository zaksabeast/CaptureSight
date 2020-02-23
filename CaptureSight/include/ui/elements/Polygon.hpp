#pragma once
#include <vector>
#include <pu/Plutonium>

class Polygon : public pu::ui::elm::Element {
 public:
  Polygon(s32 _centerX, s32 _centerY, pu::ui::Color PolygonColor);
  PU_SMART_CTOR(Polygon)

  s32 GetX();
  s32 GetY();
  s32 GetWidth();
  s32 GetHeight();
  void OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y);
  void OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos);
  void SetPoints(std::vector<SDL_Point> points);

 private:
  s32 m_borderr;
  s32 m_centerX;
  s32 m_centerY;
  std::vector<s16> m_pointsX = {};
  std::vector<s16> m_pointsY = {};
  pu::ui::render::NativeRenderer m_renderer;
  pu::ui::Color m_clr;
};