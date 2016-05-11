#pragma once

#include "../AppEnv.h"
#include "../Object/MoveObject.h"
#include "../Taxture/Taxtures.h"
enum BlockType {
	NON,
	WHITEBLOCK,
	BLACKBLOCK,
	GRASS,
	SAND,
	THORN,
	SWITCH,
	RIFUTO,
	BOMB
};


class BlockBase : public MoveObject
{
public:
	BlockBase(Vec2f _pos, Vec2f _size) :
		MoveObject(_pos, _size) 
	{
		up_block = true;
		down_block = true;
		left_block = true;
		right_block = true;
	}
	virtual Vec2f collision(Vec2f,Vec2f, Vec2f);
	virtual void update() override;
	virtual void draw() override;
	virtual bool is_Object() { return false; };
	Vec2f vec;
	bool up_block;
	bool down_block;
	bool left_block;
	bool right_block;
	Vec2f getPos();
	
};