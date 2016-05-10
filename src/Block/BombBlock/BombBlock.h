#pragma once
#include "../Block.h"


class BombBlock :public BlockBase
{
public:
	BombBlock(Vec2f, Vec2f);
	bool is_Object() override;
	void draw() override;
private:

};

