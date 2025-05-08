#include "DxLib.h"
#include "Object/box.hpp"

void Box::initialize() noexcept
{
}

void Box::update() noexcept
{
}

void Box::draw() const noexcept
{
	drawVerticalSquare(position_.y);
	drawVerticalSquare(uniScale_);

	DrawLine3D(VGet(position_.x + rad_, 0.0f, position_.z + rad_),
			   VGet(position_.x + rad_, uniScale_, position_.z + rad_),
			   color_);

	DrawLine3D(VGet(position_.x - rad_, 0.0f, position_.z + rad_),
			   VGet(position_.x - rad_, uniScale_, position_.z + rad_),
			   color_);

	DrawLine3D(VGet(position_.x + rad_, 0.0f, position_.z - rad_),
		       VGet(position_.x + rad_, uniScale_, position_.z - rad_),
		       color_);

	DrawLine3D(VGet(position_.x - rad_, 0.0f, position_.z - rad_),
			   VGet(position_.x - rad_, uniScale_, position_.z - rad_),
			   color_);

}

void Box::lastUpdate() noexcept
{
}

void Box::setColor(VECTOR color) noexcept
{

}

void Box::drawVerticalSquare(float yAxis) const noexcept
{
	DrawLine3D(VGet(position_.x + rad_, yAxis, position_.z + rad_),
			   VGet(position_.x - rad_, yAxis, position_.z + rad_),
			   color_);

	DrawLine3D(VGet(position_.x - rad_, yAxis, position_.z + rad_),
			   VGet(position_.x - rad_, yAxis, position_.z - rad_),
			   color_);

	DrawLine3D(VGet(position_.x - rad_, yAxis, position_.z - rad_),
			   VGet(position_.x + rad_, yAxis, position_.z - rad_),
			   color_);

	DrawLine3D(VGet(position_.x + rad_, yAxis, position_.z - rad_),
			   VGet(position_.x + rad_, yAxis, position_.z + rad_),
			   color_);
}
