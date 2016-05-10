#include "Lift.h"

Lift::Lift(Vec2f _pos, Vec2f _size, Vec2i _move_sell) :
	NormalBlock(_pos, _size)
{
	move_sell = _move_sell;
	move_end = false;
	bigin_pos = _pos;
}

void Lift::draw()
{
	drawTextureBox(pos.x() - size.x() / 2,
		pos.y() - size.y() / 2,
		size.x(), size.y(), 0, 0, 256, 256,
		Textures::get("rifuto"));
	ago_flame_pos = pos;
}

void Lift::update()
{
	if (!move_end) {
		Easing::Start(pos.x(), bigin_pos.x() +size.x()*move_sell.x(), Easing::Function::QuadInOut,300);
		Easing::Start(pos.y(), bigin_pos.y() + size.y()*move_sell.y(), Easing::Function::QuadInOut,300);
		if (Easing::BeginSet(pos.x())) {
			Easing::BeginSet(pos.y());
			move_end = !move_end;
		}
	}
	else
	{
		Easing::Start(pos.x(), bigin_pos.x(), Easing::Function::QuadInOut,300);
		Easing::Start(pos.y(), bigin_pos.y(), Easing::Function::QuadInOut,300);
		if (Easing::BeginSet(pos.x())) {
			Easing::BeginSet(pos.y());
			move_end = !move_end;
		}
	}
	


}

Vec2f Lift::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	
	if (is_hit(pos, size, _pos, _size)) {
		//è„
		if (_vec.y() < 0) {

			if (_pos.y() > (pos.y() + size.y() / 2 + _size.y() / 2) - 21) {
				return Vec2f(0, (pos.y() + size.y() / 2 + _size.y() / 2) - _pos.y());
			}
		}
		//ç∂
		if (_vec.x() > 0) {
			if (_pos.x() < pos.x()) {
				return Vec2f(pos.x() - size.x() / 2 - _size.x() / 2 - _pos.x(), 0);
			}
		}
		//âE
		if (_vec.x() < 0) {
			if (_pos.x() > pos.x()) {
				return Vec2f(pos.x() + size.x() / 2 + _size.x() / 2 - _pos.x(), 0);
			}
		}
	}
	return Vec2f::Zero();
}

Vec2f Lift::getVec()
{
	return ago_flame_pos - pos;
}

