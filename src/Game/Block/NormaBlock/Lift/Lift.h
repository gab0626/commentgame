#pragma once
#include "../NormalBlock.h"
#include "../../../Easing/easing.h"

class Lift : public NormalBlock
{
public:
	Lift(Vec2f, Vec2f,Vec2i);
	void draw() override;
	void update() override;
private:
	Vec2i move_sell;
	bool move_end;
	Vec2f bigin_pos;
	Vec2f ago_flame_pos;
	Vec2f collision(Vec2f, Vec2f, Vec2f) override;

	Vec2f getVec();

};