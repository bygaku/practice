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
	*  Object�������Œ�`����Scene�ɓn������, �R���e�i����I�u�W�F�N�g�̏��l�����ł��Ȃ����߁A
	* Getter�������͐ӔC�����̂���ObjectManager��Scene���ɂ�������ׂ��ł���Ǝv���܂��B
	* �����I�Ȕj�����������ꍇ�����l�ɃI�u�W�F�N�g�̏�񂪂��邽�߁Amanager�����ׂ��B
	*/
	auto text = std::make_shared<Text>(50);
	text->setText("S��������Box��\��.");
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
