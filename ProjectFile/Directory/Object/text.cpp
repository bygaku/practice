#include "DxLib.h"
#include "Object/text.hpp"

void Text::initialize() noexcept
{
}

void Text::update() noexcept
{
}

void Text::draw() const noexcept
{
	SetFontSize(fontSize_);
	DrawFormatString(positionX_, positionY_, color_, str_.c_str());
	SetFontSize(20);
}

void Text::lastUpdate() noexcept
{
}

void Text::setText(std::string str) noexcept
{
	str_ = str;
}

void Text::setText(std::string str, VECTOR color) noexcept
{
	str_   = str;
	color_ = GetColor(static_cast<int>(color.x),
					  static_cast<int>(color.y),
					  static_cast<int>(color.z));
}
