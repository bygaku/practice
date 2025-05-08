#pragma once
#include "string"
#include "unordered_map"
#include "memory"
#include "Tag/scene_type.hpp"
#include "Object/game_object.hpp"

class SceneManager;

class Scene
{
public:
	Scene() = delete;
	explicit Scene(std::string tag, SceneManager& manager) noexcept
		: manager_(manager)
		, tag_(tag)
		, time_(0.0f)
	{
		DrawString(400, 0, "Scene Create!", GetColor(255, 255, 255));
		initialize();
	};

	virtual ~Scene() noexcept = default;
	virtual void initialize() noexcept;
	virtual void update()	  noexcept;
	virtual void draw() const noexcept;
	virtual void lastUpdate() noexcept;

	/// @brief シーンの状態を確認
	virtual void checkSceneState() noexcept;

	/// @brief シーンにオブジェクトを追加
	void AddObjectToScene(std::shared_ptr<GameObject> object, std::string name) noexcept;
	
protected:
	SceneManager& manager_;
	
	/// シーンを切り替え
	void changeScene(std::string name);
private:
	std::string tag_;
	std::unordered_map<std::string, std::shared_ptr<GameObject>> objects_;

	float time_;
};
