#pragma once
#include "Object/game_object.hpp"
#include "string"

class Text : public GameObject
{
public:
	Text() = delete;
	explicit Text(int x, int y, int fontSize)
		: GameObject{ ObjectTag.TEXT }
		, positionX_(x)
		, positionY_(y)
		, str_("")
		, fontSize_(fontSize)
		, color_(GetColor(255, 255, 255))
	{
	};

	virtual ~Text() noexcept = default;

	virtual void initialize() noexcept override;
	virtual void update()	  noexcept override;
	virtual void draw() const noexcept override;
	virtual void lastUpdate() noexcept override;

	/// @brief 表示テキストをセット
	void setText(std::string str) noexcept;
	void setText(std::string str, VECTOR color) noexcept;

private:
	int			positionX_;
	int			positionY_;
	std::string str_;
	int			fontSize_;
	u_int		color_;

};
