#pragma once
#include "../Object/MoveObject.h"


class ItemBase : public MoveObject
{
public:

	ItemBase() :
		MoveObject(Vec2f::Zero(), Vec2f::Zero()),
		is_draw(is_draw_),
		is_player_have(is_player_have_)
	{
		is_draw = true;
		is_player_have = false;
	}
	ItemBase(Vec2f _pos, Vec2f _size, Vec2f vec) :
		MoveObject(_pos, _size),
		is_draw(is_draw_),
		is_player_have(is_player_have_)
	{
		this->vec = vec;
		is_draw = true;
		is_player_have = false;
	}
	~ItemBase() = default;

	virtual	void update() {};
	virtual	void draw() {};

	WritableP<bool> is_draw;
	WritableP<bool> is_player_have;

private:

	bool is_player_have_;
	bool is_draw_;

};