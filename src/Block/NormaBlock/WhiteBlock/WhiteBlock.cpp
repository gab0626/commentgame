#include "WhiteBlock.h"

WhiteBlock::WhiteBlock(Vec2f _pos, Vec2f _size):
	NormalBlock(_pos,_size)
{
}

void WhiteBlock::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 128, 128,
		Textures::get("whiteblock"));
}
