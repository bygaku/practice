#pragma once
#include "Scene/scene.hpp"

class StageScene final : public Scene
{
public:
	StageScene(SceneManager& manager) noexcept
		: Scene(SceneType.STAGE, manager)
	{
		initialize();
	};

	virtual void checkSceneState() noexcept override;
};
