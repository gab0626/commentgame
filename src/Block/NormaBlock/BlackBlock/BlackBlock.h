#pragma once

#include "../NormalBlock.h"

class BlackBlock : public NormalBlock
{
public:
	BlackBlock(Vec2f, Vec2f);
	void draw() override;

private:

};