#pragma once
#include "../AppEnv.h"

class ObjectBase
{
public:

	ObjectBase(Vec2f _pos, Vec2f _size) :
		pos(_pos), size(_size)
	{

	}

protected:
	Vec2f pos;
	Vec2f size;
};

