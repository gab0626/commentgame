#include "BombBlock.h"

BombBlock::BombBlock(Vec2f _pos, Vec2f _size) :
	BlockBase(_pos, _size)
{


}

bool BombBlock::is_Object()
{
	return false;
}

void BombBlock::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 128, 128,
		Textures::get("bomb"));
}

