#include "DxLib.h"
#include "memory"
#include "Data/window_data.hpp"
#include "Scene/stage.hpp"

#include "Object/box.hpp"
#include "Object/text.hpp"
#include "Object/camera.hpp"


StageScene::StageScene(SceneManager& manager) noexcept
	: Scene(SceneType.STAGE, manager)
{
	float  box_size = 10.0f;
	VECTOR center	= VGet(WindowData::kWidthF  / 2.0f,
						   WindowData::kHeightF / 2.0f,
						   0.0f);

	auto box_1 = std::make_shared<Box>(VGet(20.0f, 0.0f, -20.0f), box_size);
	box_1->setColor(VGetD(255, 0, 0));
	auto box_2 = std::make_shared<Box>(VGet(-30.0f, 0.0f, 50.0f), box_size);
	box_2->setColor(VGetD(0, 255, 0));
	auto box_3 = std::make_shared<Box>(VGet(60.0f, 0.0f, 20.0f), box_size);
	box_3->setColor(VGetD(0, 0, 255));

	VECTOR look_at	  = VGet(0.0f,	 0.0f,	0.0f);
	VECTOR camera_pos = VGet(-50.0f, 50.0f, -50.0f);

	auto main_camera = std::make_shared<Camera>(camera_pos, look_at);

	addObjectToScene(box_1, "box1");
	addObjectToScene(box_2, "box2");
	addObjectToScene(box_3, "box3");
	addObjectToScene(main_camera, "mainCamera");

	initialize();
};


void StageScene::checkSceneState() noexcept
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		changeScene(SceneType.RESULT);
	}
}
