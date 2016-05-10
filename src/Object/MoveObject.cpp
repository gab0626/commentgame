#include "MoveObject.h"

void MoveObject::addpos(Vec2f _vec)
{
	if (_vec.y() > 0) {
		vec_.y() = 0;
	}
	this->pos += _vec;

}
