#include "assert_for_dxlib.hpp"
#include "format"
#include "DxLib.h"

namespace utilitys
{
    [[noreturn]] void errorAssert(
        std::string_view conditional_expression,
        std::string_view error_mes,
        std::string_view file,
        std::string_view func,
        int line)
    {
        // DxLibがまだ初期化されていない場合は強制終了
        if (DxLib_IsInit() != TRUE)
        {
            std::fprintf(stderr, "DxLib is not initialized.\n");
            std::exit(1);
        }

        clsDx();
        printfDx("%s", error_constants::kAssertionHeader);

        printfDx("%s", std::format("Error Condition : {}\n\n",  conditional_expression).c_str());
        printfDx("%s", std::format("Error Cause : {}\n\n",      error_mes).c_str());
        printfDx("%s", std::format("File Name : {}\n\n",        file).c_str());
        printfDx("%s", std::format("Function Name : {}\n\n",    func).c_str());
        printfDx("%s", std::format("Line Number : {}\n\n",      line).c_str());

        // ユーザーからの入力を待機
        while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
        {
            ClearDrawScreen();
            ScreenFlip();
        }

        DxLib_End();

        // プログラムを終了
        std::exit(error_constants::kExitCode);
    }

}