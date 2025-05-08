#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Initializer/window_init.hpp"
#include "Initializer/library_init.hpp"
#include "Core/game_manager.hpp"

int WINAPI WinMain
(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    // ���O�̏o�͂��֎~
    SetOutApplicationLogValidFlag(false);

    auto* window_init  = new Window();
    auto* library_init = new Lib();

    if (!window_init->initialize())  return -1;
    if (!library_init->initialize()) return -1;

    Game::create();
    auto& game = Game::getInstance();

    while (game.isRunning())
    {
        clsDx();
        game.update();
    }

    Game::destroy();
    delete library_init;
    delete window_init;

    return 0;
}