#pragma once
#include "../NormalBlock.h"

class WhiteBlock : public NormalBlock
{
public:
	WhiteBlock(Vec2f, Vec2f);
	void draw() override;

private:

};
