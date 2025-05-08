#pragma once
#include "Scene/scene.hpp"

class LoadScene final : public Scene
{
public:
	LoadScene(SceneManager& manager) noexcept
		: Scene(SceneType.LOAD, manager)
	{
		initialize();
	};
};
