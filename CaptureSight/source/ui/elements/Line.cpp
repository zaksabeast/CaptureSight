#include <pu/Plutonium>
#include <ui/elements/Line.hpp>

Line::Line(s32 x1, s32 y1, s32 x2, s32 y2, pu::ui::Color LineColor) : pu::ui::elm::Element::Element() {
  m_x1 = x1;
  m_y1 = y1;
  m_x2 = x2;
  m_y2 = y2;
  m_clr = LineColor;
  m_renderer = pu::ui::render::GetMainRenderer();
}

s32 Line::GetX() {
  return m_x1;
}

s32 Line::GetY() {
  return m_y1;
}

s32 Line::GetWidth() {
  return 0;
}

s32 Line::GetHeight() {
  return 0;
}

void Line::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  lineRGBA(m_renderer, m_x1, m_y1, m_x2, m_y2, m_clr.R, m_clr.G, m_clr.B, m_clr.A);
  aalineRGBA(m_renderer, m_x1, m_y1, m_x2, m_y2, m_clr.R, m_clr.G, m_clr.B, m_clr.A);
}

void Line::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}
