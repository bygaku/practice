#pragma once
#include "Scene/scene.hpp"

class ResultScene final : public Scene
{
public:
	ResultScene(SceneManager& manager) noexcept
		: Scene(SceneType.RESULT, manager)
	{
		initialize();
	};
};
