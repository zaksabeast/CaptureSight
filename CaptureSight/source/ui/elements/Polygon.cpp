#include <pu/Plutonium>
#include <ui/elements/Polygon.hpp>

Polygon::Polygon(s32 _centerX, s32 _centerY, pu::ui::Color PolygonColor) : pu::ui::elm::Element::Element() {
  m_centerX = _centerX;
  m_centerY = _centerY;
  m_clr = PolygonColor;
  m_renderer = pu::ui::render::GetMainRenderer();
}

s32 Polygon::GetX() {
  return m_centerX;
}

s32 Polygon::GetY() {
  return m_centerY;
}

s32 Polygon::GetWidth() {
  return 0;
}

s32 Polygon::GetHeight() {
  return 0;
}

void Polygon::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  filledPolygonRGBA(m_renderer, m_pointsX.data(), m_pointsY.data(), m_pointsX.size(), m_clr.R, m_clr.G, m_clr.B, m_clr.A);
  aapolygonRGBA(m_renderer, m_pointsX.data(), m_pointsY.data(), m_pointsX.size(), m_clr.R, m_clr.G, m_clr.B, m_clr.A);
}

void Polygon::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}

void Polygon::SetPoints(std::vector<SDL_Point> points) {
  m_pointsX.clear();
  m_pointsY.clear();

  for (auto point : points) {
    m_pointsX.push_back(point.x + m_centerX);
    m_pointsY.push_back(point.y + m_centerY);
  }
}