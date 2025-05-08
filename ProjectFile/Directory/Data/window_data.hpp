#pragma once

namespace WindowData
{
#ifdef _RELEASE
    static constexpr int kWidth   = 1920;     /// @brief 画面横サイズ
    static constexpr int kHeight  = 1080;     /// @brief 画面縦サイズ
    static constexpr int kWidthF  = 1280;     /// @brief <float> 画面横サイズ
    static constexpr int kHeightF =  720;     /// @brief <float> 画面縦サイズ
#else
    static constexpr int kWidth   = 1280;     /// @brief 画面横サイズ
    static constexpr int kHeight  =  720;     /// @brief 画面縦サイズ
    static constexpr int kWidthF  = 1280;     /// @brief <float> 画面横サイズ
    static constexpr int kHeightF =  720;     /// @brief <float> 画面縦サイズ
#endif
    static constexpr int kColorBit = 16;     /// @brief カラービット
}