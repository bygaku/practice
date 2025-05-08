#pragma once
#include "Scene/scene.hpp"

class TitleScene final : public Scene
{
public:
	TitleScene(SceneManager& manager) noexcept;

	virtual void checkSceneState() noexcept override;
};
