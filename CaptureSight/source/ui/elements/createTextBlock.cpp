#pragma once
#include <pu/Plutonium>
#include <string>
#include <utils/Settings.hpp>

extern Settings gsets;

pu::ui::elm::TextBlock::Ref createTextBlock(i32 x, i32 y, std::string text, u32 fontSize) {
  std::string fontName;

  switch (fontSize) {
    case 36:
      fontName = "DefaultFont@36";
      break;
    case 30:
      fontName = "DefaultFont@30";
      break;
    case 25:
      fontName = "DefaultFont@25";
      break;
    case 20:
      fontName = "DefaultFont@20";
      break;
  }

  auto textBlock = pu::ui::elm::TextBlock::New(x, y, text);
  textBlock->SetFont(fontName);
  textBlock->SetColor(gsets.GetTheme().text.light);

  return textBlock;
}