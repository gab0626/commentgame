#pragma once
#include "../ItemBase.h"
#include "../../Share/Property/PropertySystem.h"


class Bomb : public ItemBase
{
public:

	Bomb();
	Bomb(Vec2f _pos, Vec2f _size, Vec2f vec);
	~Bomb();

	void update() override;
	void draw() override;

private:

	void countDown();
	void animation();


	int explosion_count;
	int animation_count;
	bool is_countdown;
	bool is_explosion;

	Vec2f cut_pos;
	Vec2f cut_size;
	Vec3f color;

};