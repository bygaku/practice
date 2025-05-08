#pragma once
#include "Object/game_object.hpp"

class Plane : public GameObject
{
public:
	Plane() = delete;
	explicit Plane(VECTOR position, int size)
		: GameObject{ ObjectTag.BOX }
		, position_(position)
		, size_(size)
	{
	};

	virtual ~Plane() noexcept = default;

	virtual void initialize() noexcept override;
	virtual void update()	  noexcept override;
	virtual void draw() const noexcept override;
	virtual void lastUpdate() noexcept override;

private:
	VECTOR position_;
	int size_;

};
