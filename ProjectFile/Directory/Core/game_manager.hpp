#pragma once
#include "memory"
#include "unordered_map"
#include "string"

class GameTime;
class SceneManager;

class Game final
{
public:
	static Game& getInstance() noexcept;
	static void create()  noexcept;
	static void destroy() noexcept;

	bool isRunning() const noexcept;
	void update() noexcept;

private:
	std::shared_ptr<SceneManager> sceneManager_;
	std::shared_ptr<GameTime>	  gameTime_;
	float time_;

private:
	static Game* instance_;

	Game() noexcept;
	Game(const Game&) = delete;
	Game& operator = (const Game&) = delete;
	~Game() noexcept = default;

};
