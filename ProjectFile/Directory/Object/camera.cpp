#include "DxLib.h"
#include "Object/camera.hpp"

void Camera::initialize() noexcept
{
}

void Camera::update() noexcept
{
    SetCameraPositionAndTarget_UpVecY
       (VGet(position_.x + offset_.x, position_.y + offset_.y, position_.z + offset_.z),
        VGet(lookAt_.x, lookAt_.y, lookAt_.z));
}

void Camera::draw() const noexcept
{
}

void Camera::lastUpdate() noexcept
{
}

void Camera::setOffset(const VECTOR& offset) noexcept
{
    offset_ = offset;
}