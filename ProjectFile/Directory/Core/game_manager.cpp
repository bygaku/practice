#include "DxLib.h"
#include "Utility/assert_for_dxlib.hpp"
#include "Core/game_time.hpp"
#include "Core/game_manager.hpp"
#include "Core/scene_manager.hpp"

Game* Game::instance_ = nullptr;

Game::Game() noexcept
	: gameTime_(std::make_shared<GameTime>())
	, sceneManager_(std::make_shared<SceneManager>(*this))
	, time_(0.0f)
{
}

Game& Game::getInstance() noexcept
{
	ASSERT(instance_ != nullptr, "instance_ isn't existing.");
	return *instance_;
}
 
void Game::create() noexcept
{
	ASSERT(instance_ == nullptr, "instance_ already exist.");
	instance_ = new Game();
}

void Game::destroy() noexcept
{
	ASSERT(instance_ != nullptr, "instance_ is nullptr.");
	DxLib_End();
	delete instance_;
}

bool Game::isRunning() const noexcept
{
	return !ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE);
}

void Game::update() noexcept
{
	ClearDrawScreen();
	time_ += GameTime::getDeltaTime();

	printfDx("Game Update!!\n\n");
	printfDx("GameTime:%.1f\n", time_);

	sceneManager_->update();
	sceneManager_->draw();

	gameTime_->sleepForNextFrame();
	gameTime_->incrementFrame();
}
