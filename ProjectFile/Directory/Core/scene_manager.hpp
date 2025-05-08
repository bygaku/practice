#pragma once
#include "Core/game_manager.hpp"

class Scene;

class SceneManager final
{
public:
	SceneManager() = delete;
	explicit SceneManager(Game& game) noexcept;

	~SceneManager() noexcept;

	void update() noexcept;
	void draw() noexcept;

	/// @brief ƒV[ƒ“‚ğ•ÏX
	void changeScene(std::string tag) noexcept;

private:
	static bool instantiated_;

	Game& game_;
	std::unordered_map<std::string, std::shared_ptr<Scene>> scenes_;
	std::shared_ptr<Scene> currentScene_;

};
