#pragma once
#include "../Block.h"

bool is_hit(Vec2f _pos, Vec2f _size, Vec2f floor_pos, Vec2f floor_size);

class NormalBlock : public BlockBase
{
public:
	NormalBlock(Vec2f _pos,Vec2f);
	~NormalBlock();
	virtual void update() override;
	Vec2f collision(Vec2f, Vec2f, Vec2f) override;
	virtual void draw() override;

	bool is_Object() override;
private:

};
