#pragma once

namespace WindowData
{
#ifdef _RELEASE
    static constexpr int kWidth   = 1920;     /// @brief ��ʉ��T�C�Y
    static constexpr int kHeight  = 1080;     /// @brief ��ʏc�T�C�Y
    static constexpr int kWidthF  = 1280;     /// @brief <float> ��ʉ��T�C�Y
    static constexpr int kHeightF =  720;     /// @brief <float> ��ʏc�T�C�Y
#else
    static constexpr int kWidth   = 1280;     /// @brief ��ʉ��T�C�Y
    static constexpr int kHeight  =  720;     /// @brief ��ʏc�T�C�Y
    static constexpr int kWidthF  = 1280;     /// @brief <float> ��ʉ��T�C�Y
    static constexpr int kHeightF =  720;     /// @brief <float> ��ʏc�T�C�Y
#endif
    static constexpr int kColorBit = 16;     /// @brief �J���[�r�b�g
}