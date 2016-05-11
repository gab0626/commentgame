#pragma once
#include "ObjectBase.h"
#include "../AppEnv.h"
#include "../Share/Property/PropertySystem.h"

class MoveObject :public ObjectBase
{
public:
	MoveObject(Vec2f _pos, Vec2f _size) :
		ObjectBase(_pos, _size),
		vec(vec_)
	{
		vec = Vec2f::Zero();
	};
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void addpos(Vec2f);
	WritableP<Vec2f> vec;
protected:
	Vec2f vec_;
};