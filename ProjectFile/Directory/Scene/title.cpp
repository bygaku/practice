#include "DxLib.h"
#include "memory"
#include "Data/window_data.hpp"
#include "Scene/title.hpp"

#include "Object/box.hpp"
#include "Object/text.hpp"

TitleScene::TitleScene(SceneManager& manager) noexcept
	: Scene(SceneType.TITLE, manager)
{
	int	   boxSize = 10;
	VECTOR center  = VGet(WindowData::kWidthF  / 2.0f,
						  WindowData::kHeightF / 2.0f, 
						  0.0f);

	auto box1 = std::make_shared<Box>(VGet(20,  0, -20), boxSize);
	auto box2 = std::make_shared<Box>(VGet(-60, 0,  50), boxSize);
	auto box3 = std::make_shared<Box>(VGet(60,  0,  20), boxSize);
	auto text = std::make_shared<Text>(WindowData::kWidth / 2, WindowData::kHeight / 2, 40);

	text->setText("S‚ð‰Ÿ‚µ‚ÄBox‚ð•\Ž¦...");

	AddObjectToScene(box1, "box1");
	AddObjectToScene(box2, "box2");
	AddObjectToScene(box3, "box3");
	AddObjectToScene(text, "text1");

	initialize();
};

void TitleScene::checkSceneState() noexcept
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		changeScene(SceneType.STAGE);
	}
}
