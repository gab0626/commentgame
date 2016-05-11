#pragma once
#include "../Object/MoveObject.h"

class Enemy : public MoveObject
{
public:
	Enemy();
	Enemy(Vec2f _pos, Vec2f _size);
	~Enemy();
	void update() override;
	void draw() override;
	
private:

};





