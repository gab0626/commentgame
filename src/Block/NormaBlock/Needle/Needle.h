#pragma once
#include "../NormalBlock.h"

class Needle : public NormalBlock
{
public:
	Needle(Vec2f, Vec2f);
	void draw() override;

private:

};