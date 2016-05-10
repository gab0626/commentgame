#pragma once

#include "../NormalBlock.h"

class Grass : public NormalBlock
{
public:
	Grass(Vec2f, Vec2f);
	void draw() override;

private:

};