#include <pu/Plutonium>
#include <ui/elements/RoundedRectangle.hpp>

RoundedRectangle::RoundedRectangle(s32 X, s32 Y, s32 Width, s32 Height, pu::ui::Color RecColor, s32 BorderRadius) : pu::ui::elm::Element::Element() {
  m_x = X;
  m_y = Y;
  m_w = Width;
  m_h = Height;
  m_clr = RecColor;
  m_borderr = BorderRadius;
}

s32 RoundedRectangle::GetX() {
  return m_x;
}

void RoundedRectangle::SetX(s32 X) {
  m_x = X;
}

s32 RoundedRectangle::GetY() {
  return m_y;
}

void RoundedRectangle::SetY(s32 Y) {
  m_y = Y;
}

s32 RoundedRectangle::GetWidth() {
  return m_w;
}

void RoundedRectangle::SetWidth(s32 Width) {
  m_w = Width;
}

s32 RoundedRectangle::GetHeight() {
  return m_h;
}

void RoundedRectangle::SetHeight(s32 Height) {
  m_h = Height;
}

s32 RoundedRectangle::GetBorderRadius() {
  return m_h;
}

void RoundedRectangle::SetBorderRadius(s32 Radius) {
  m_borderr = Radius;
}

pu::ui::Color RoundedRectangle::GetColor() {
  return m_clr;
}

void RoundedRectangle::SetColor(pu::ui::Color RecColor) {
  m_clr = RecColor;
}

void RoundedRectangle::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  Drawer->RenderRoundedRectangleFill(m_clr, X, Y, m_w, m_h, m_borderr);
}

void RoundedRectangle::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}