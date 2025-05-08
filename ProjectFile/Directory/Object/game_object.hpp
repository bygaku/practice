#pragma once
#include "string"
#include "vector"
#include "memory"
#include "Tag/object_tag.hpp"

class GameObject
{
public:
	GameObject() = delete;
	explicit GameObject(std::string tag) noexcept
		: tag_(tag)
		, isActive_(true)
	{
		printfDx("\nGameObject Entry!");
	};

	virtual ~GameObject() noexcept = default;

	virtual void initialize() noexcept = 0;
	virtual void update()	  noexcept = 0;
	virtual void draw() const noexcept = 0;
	virtual void lastUpdate() noexcept = 0;

	/// @brief �I�u�W�F�N�g��L����
	void activate() noexcept { isActive_ =  true; };
	/// @brief �I�u�W�F�N�g���폜�����ɏ������~
	void deactivate() noexcept { isActive_ = false; };

private:
	std::string tag_;
	bool isActive_;

};