#pragma once

class Lib final
{
public:
    Lib() noexcept;
    ~Lib() noexcept;

    /// @brief �V�X�e���̏�����
    bool initialize() noexcept;

private:
    bool succeedInit_;
    static bool instantiated_;

};