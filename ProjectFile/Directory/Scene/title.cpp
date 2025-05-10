#include "DxLib.h"
#include "memory"
#include "Data/window_data.hpp"
#include "Scene/title.hpp"

#include "Object/box.hpp"
#include "Object/text.hpp"
#include "Object/camera.hpp"

TitleScene::TitleScene(SceneManager& manager) noexcept
	: Scene(SceneType.TITLE, manager)
{
	/* HACK:
	*  Objectをここで定義してSceneに渡したら, コンテナからオブジェクトの情報獲得ができないため、
	* Getterもしくは責任分離のためObjectManagerをScene基底にもたせるべきであると思います。
	* 明示的な破棄をしたい場合も同様にオブジェクトの情報がいるため、managerを作るべき。
	*/
	auto text = std::make_shared<Text>(50);
	text->setText("Sを押してBoxを表示.");
	text->setTextCenter();

	addObjectToScene(text, "text1");

	initialize();
};

void TitleScene::checkSceneState() noexcept
{
	if (CheckHitKey(KEY_INPUT_S))
	{
		changeScene(SceneType.STAGE);
	}
}
