#pragma once
#include "Object/game_object.hpp"

class Camera : public GameObject
{
public:
	Camera() = delete;
	explicit Camera(VECTOR position, VECTOR lookAt)
		: GameObject{ ObjectTag.BOX }
		, position_(position)
		, lookAt_(lookAt)
		, kNear_(10.0f)
		, kFar_(2000.0f)
		, offset_(VGet(0.0f, 0.0f, 0.0f))
	{
		SetCameraNearFar(kNear_, kFar_);
	};

	virtual ~Camera() noexcept = default;

	virtual void initialize() noexcept override;
	virtual void update()	  noexcept override;
	virtual void draw() const noexcept override;
	virtual void lastUpdate() noexcept override;

	void setOffset(const VECTOR& offset) noexcept;

private:
	VECTOR position_;
	VECTOR offset_;
	VECTOR lookAt_;
	const float kNear_;
	const float kFar_;

};
