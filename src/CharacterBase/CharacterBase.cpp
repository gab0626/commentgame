#include "CharacterBase.h"


CharacterBase::CharacterBase(Vec2f _pos, Vec2f _size) :
	MoveObject(_pos, _size),
	gravity(gravity_),
	gravity_max(gravity_max_)
{

}

void CharacterBase::fall()
{
	vec_.y() -= gravity_;
	vec_.y() = std::max(vec_.y(), -gravity_max_);
}

void CharacterBase::vector()
{
	pos += vec_;
}


