#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Data/window_data.hpp"
#include "Initializer/window_init.hpp"

bool Window::instantiated_ = false;

Window::Window() noexcept
{
    ASSERT(instantiated_ == 0, "already instantiated.");
    instantiated_ = true;
}

Window::~Window() noexcept
{
    instantiated_ = false;
}

bool Window::initialize() noexcept
{
    // �o�̓E�B���h�E�̏�����
    ChangeWindowMode(true);
    SetGraphMode(WindowData::kWidth, WindowData::kHeight, WindowData::kColorBit);
    SetDrawScreen(DX_SCREEN_BACK);

    SetMainWindowText("Window initialization was successful");

    return true;
}