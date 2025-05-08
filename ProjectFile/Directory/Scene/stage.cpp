#include "DxLib.h"
#include "Scene/stage.hpp"

void StageScene::checkSceneState() noexcept
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		changeScene(SceneType.RESULT);
	}
}
