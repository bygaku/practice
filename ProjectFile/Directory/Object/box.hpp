#pragma once
#include "Object/game_object.hpp"

class Box : public GameObject
{
public:
	Box() = delete;
	explicit Box(VECTOR position, float uniScale)
		: GameObject{ ObjectTag.BOX }
		, position_(position)
		, uniScale_(uniScale)
		, rad_(uniScale / 2.0f)
		, color_(GetColor(255, 255, 255))
	{
	};

	virtual ~Box() noexcept = default;

	virtual void initialize() noexcept override;
	virtual void update()	  noexcept override;
	virtual void draw() const noexcept override;
	virtual void lastUpdate() noexcept override;

	/// @brief 色をセット
	void setColor(VECTOR_D color) noexcept;

private:
	/// @brief 四角形を線で描画
	void drawVerticalSquare(float yAxis) const noexcept;

private:
	VECTOR position_;
	float  uniScale_;
	float  rad_;
	u_int  color_;

};
