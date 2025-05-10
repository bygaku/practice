#pragma once
#include "Scene/scene.hpp"

class StageScene final : public Scene
{
public:
	StageScene(SceneManager& manager) noexcept;

	virtual void checkSceneState() noexcept override;
};
