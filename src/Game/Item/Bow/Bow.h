#pragma once
#include "Arrow/Arrow.h"



class Bow : public ItemBase
{
public:

	Bow();
	Bow(Vec2f _pos, Vec2f _size);
	~Bow();

	void update() override;
	void draw() override;

private:

	void drawTheBow();
	void shootTheBow();
	void changeAngle();

	std::list<Arrow> arrows;
	int max_arrow_num;
	float max_arrow_vec;
	Vec2f arrow_vec;
	float rad;
};