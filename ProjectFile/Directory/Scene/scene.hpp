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

	/// @brief �V�[���̏�Ԃ��m�F
	virtual void checkSceneState() noexcept;

	/// @brief �V�[���ɃI�u�W�F�N�g��ǉ�
	void addObjectToScene(std::shared_ptr<GameObject> object, std::string name) noexcept;

	/// @brief ���ׂẴV�[���ɓK������I�u�W�F�N�g��ǉ�
	/// @memo �����I�Ȕj���̋@�\�ǉ� => �I�u�W�F�N�g�Ǘ��N���X�łˁ�
	void dontDestroyOnLoad(std::shared_ptr<GameObject> object, std::string name) noexcept;

	std::unordered_map<std::string, std::shared_ptr<GameObject>> getDontDestroyObjects() noexcept;
protected:
	SceneManager& manager_;
	
	/// �V�[����؂�ւ�
	void changeScene(std::string name);
private:
	std::string tag_;
	std::unordered_map<std::string, std::shared_ptr<GameObject>> objects_;
	std::unordered_map<std::string, std::shared_ptr<GameObject>> dontDestroyObjects_;

	float time_;
};
