#pragma once

class Window final
{
public:
    Window() noexcept;
    ~Window() noexcept;

    /// @brief �E�B���h�E�̏�����
    bool initialize() noexcept;

private:
    static bool instantiated_;

};