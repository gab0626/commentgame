#include "NormalBlock.h"


bool is_hit(Vec2f _pos, Vec2f _size, Vec2f floor_pos, Vec2f floor_size) {
	return (_pos.x() > floor_pos.x() - floor_size.x() / 2 - _size.x() / 2 &&
		_pos.x() < floor_pos.x() + floor_size.x() / 2 + _size.x() / 2 &&
		_pos.y() > floor_pos.y() - floor_size.y() / 2 - _size.y() / 2 &&
		_pos.y() < floor_pos.y() + floor_size.y() / 2 + _size.y() / 2
		);
}


NormalBlock::NormalBlock(Vec2f _pos,Vec2f _size) :
	BlockBase(_pos, _size)
{
	
}

NormalBlock::~NormalBlock()
{

}

void NormalBlock::update()
{

}

Vec2f NormalBlock::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	if (is_hit(pos, size, _pos, _size)) {
		//ã
		if (_vec.y() < 0) {

			if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 21) {
				return Vec2f(0, (pos.y() + size.y() / 2 + _size.y() / 2) - _pos.y());
			}
		}
		//¶
		if (_vec.x() > 0) {
			if (_pos.x() < pos.x()) {
				return Vec2f(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x(), 0);
			}
		}
		//‰E
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				return Vec2f(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x(), 0);
			}
		}
	}

	return Vec2f::Zero();
}

void NormalBlock::draw()
{
	
}

bool NormalBlock::is_Object()
{
	return true;
}
