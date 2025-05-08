#include "Utility/assert_for_dxlib.hpp"
#include "Scene/scene.hpp"
#include "Scene/title.hpp"
#include "Scene/load.hpp"
#include "Scene/stage.hpp"
#include "Scene/result.hpp"

#include "scene_manager.hpp"

bool SceneManager::instantiated_ = false;

SceneManager::SceneManager(Game& game) noexcept
	: game_(game)
{
	ASSERT(instantiated_ == 0, "already instantiated.");
	instantiated_ = true;

	scenes_[SceneType.TITLE]  = std::make_shared<TitleScene> (*this);
	scenes_[SceneType.LOAD]   = std::make_shared<LoadScene>  (*this);
	scenes_[SceneType.STAGE]  = std::make_shared<StageScene> (*this);
	scenes_[SceneType.RESULT] = std::make_shared<ResultScene>(*this);

	currentScene_ = scenes_[SceneType.TITLE];
}

SceneManager::~SceneManager() noexcept
{
	instantiated_ = false;
}

void SceneManager::update() noexcept
{
	currentScene_->update();
	currentScene_->checkSceneState();
}

void SceneManager::draw() noexcept
{
	currentScene_->draw();
}

void SceneManager::changeScene(std::string tag) noexcept
{
	if (currentScene_ == scenes_[tag]) return;

	if (scenes_.count(tag))
	{
		currentScene_ = scenes_[tag];
		return;
	}
}
