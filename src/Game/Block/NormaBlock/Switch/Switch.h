#pragma once
#include "../NormalBlock.h"

class Switch : public NormalBlock
{
public:
	Switch(Vec2f, Vec2f);
	void draw() override;

private:

};