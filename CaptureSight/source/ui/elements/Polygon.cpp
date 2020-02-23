#include <pu/Plutonium>
#include <ui/elements/Polygon.hpp>

Polygon::Polygon(s32 _centerX, s32 _centerY, pu::ui::Color PolygonColor) : pu::ui::elm::Element::Element() {
  this->centerX = _centerX;
  this->centerY = _centerY;
  this->clr = PolygonColor;
  this->renderer = pu::ui::render::GetMainRenderer();
}

s32 Polygon::GetX() {
  return this->centerX;
}

s32 Polygon::GetY() {
  return this->centerY;
}

s32 Polygon::GetWidth() {
  return 0;
}

s32 Polygon::GetHeight() {
  return 0;
}

void Polygon::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  filledPolygonRGBA(this->renderer, this->pointsX.data(), this->pointsY.data(), this->pointsX.size(), this->clr.R, this->clr.G, this->clr.B,
                    this->clr.A);
  aapolygonRGBA(this->renderer, this->pointsX.data(), this->pointsY.data(), this->pointsX.size(), this->clr.R, this->clr.G, this->clr.B, this->clr.A);
}

void Polygon::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}

void Polygon::SetPoints(std::vector<SDL_Point> points) {
  this->pointsX.clear();
  this->pointsY.clear();

  for (auto point : points) {
    this->pointsX.push_back(point.x + this->centerX);
    this->pointsY.push_back(point.y + this->centerY);
  }
}