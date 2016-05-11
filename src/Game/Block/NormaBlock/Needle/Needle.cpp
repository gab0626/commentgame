#include "Needle.h"

Needle::Needle(Vec2f _pos, Vec2f _size) :
	NormalBlock(_pos, _size)
{
}

void Needle::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 256, 256,
		Textures::get("thorn"));
}

