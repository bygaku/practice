#include "DxLib.h"
#include "Core/game_time.hpp"
#include "Core/scene_manager.hpp"
#include "Scene/scene.hpp"

void Scene::initialize() noexcept
{
	time_ = 0.0f;

	for (auto&& obj : objects_)
	{
		obj.second->activate();
		obj.second->initialize();
	}
}

void Scene::update() noexcept
{
	time_ += GameTime::getDeltaTime();

	for (auto&& obj : objects_)
	{
		obj.second->update();
	}
}

void Scene::draw() const noexcept
{
	printfDx("%sTime: %.1f", tag_.c_str(), time_);

	for (auto&& obj : objects_)
	{
		obj.second->draw();
	}
}

void Scene::lastUpdate() noexcept
{
	for (auto&& obj : objects_)
	{
		obj.second->lastUpdate();
	}
}

void Scene::checkSceneState() noexcept
{
	/// no processing on base class.
}

void Scene::addObjectToScene(std::shared_ptr<GameObject> object, std::string name) noexcept
{
	objects_[name] = object;
}

void Scene::dontDestroyOnLoad(std::shared_ptr<GameObject> object, std::string name) noexcept
{
	dontDestroyObjects_[name] = object;
}

std::unordered_map<std::string, std::shared_ptr<GameObject>> Scene::getDontDestroyObjects() noexcept
{
	return dontDestroyObjects_;
}

void Scene::changeScene(std::string name)
{
	manager_.changeScene(name);
}
