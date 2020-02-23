#include <pu/Plutonium>
#include <ui/elements/RoundedRectangle.hpp>

RoundedRectangle::RoundedRectangle(s32 X, s32 Y, s32 Width, s32 Height, pu::ui::Color RecColor, s32 BorderRadius) : pu::ui::elm::Element::Element() {
  this->x = X;
  this->y = Y;
  this->w = Width;
  this->h = Height;
  this->clr = RecColor;
  this->borderr = BorderRadius;
}

s32 RoundedRectangle::GetX() {
  return this->x;
}

void RoundedRectangle::SetX(s32 X) {
  this->x = X;
}

s32 RoundedRectangle::GetY() {
  return this->y;
}

void RoundedRectangle::SetY(s32 Y) {
  this->y = Y;
}

s32 RoundedRectangle::GetWidth() {
  return this->w;
}

void RoundedRectangle::SetWidth(s32 Width) {
  this->w = Width;
}

s32 RoundedRectangle::GetHeight() {
  return this->h;
}

void RoundedRectangle::SetHeight(s32 Height) {
  this->h = Height;
}

s32 RoundedRectangle::GetBorderRadius() {
  return this->h;
}

void RoundedRectangle::SetBorderRadius(s32 Radius) {
  this->borderr = Radius;
}

pu::ui::Color RoundedRectangle::GetColor() {
  return this->clr;
}

void RoundedRectangle::SetColor(pu::ui::Color RecColor) {
  this->clr = RecColor;
}

void RoundedRectangle::OnRender(pu::ui::render::Renderer::Ref& Drawer, s32 X, s32 Y) {
  s32 rdx = X;
  s32 rdy = Y;
  Drawer->RenderRoundedRectangleFill(this->clr, rdx, rdy, this->w, this->h, this->borderr);
}

void RoundedRectangle::OnInput(u64 Down, u64 Up, u64 Held, pu::ui::Touch Pos) {}