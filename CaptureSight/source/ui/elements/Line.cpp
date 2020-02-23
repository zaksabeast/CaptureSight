#include <pu/Plutonium>
#include <ui/elements/Line.hpp>

Line::Line(s32 x1, s32 y1, s32 x2, s32 y2, pu::ui::Color LineColor) : pu::ui::elm::Element::Element() {
  this->x1 = x1;
  this->y1 = y1;
  this->x2 = x2;
  this->y2 = y2;
  this->clr = LineColor;
  this->renderer = pu::ui::render::GetMainRenderer();
}

s32 Line::GetX() {
  return this->x1;
}

s32 Line::GetY() {
  return this->y1;
}

s32 Line::GetWidth() {
  return 0;
}

s32 Line::GetHeight() {
  return 0;
}

void Line::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  lineRGBA(this->renderer, this->x1, this->y1, this->x2, this->y2, this->clr.R, this->clr.G, this->clr.B, this->clr.A);
  aalineRGBA(this->renderer, this->x1, this->y1, this->x2, this->y2, this->clr.R, this->clr.G, this->clr.B, this->clr.A);
}

void Line::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}
