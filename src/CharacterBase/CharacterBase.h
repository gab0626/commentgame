#pragma once
#include "../Object/MoveObject.h"
#include "../Share/Property/PropertySystem.h"

class CharacterBase : public MoveObject {
public:


	CharacterBase(Vec2f _pos, Vec2f _size);

	WritableP<float> gravity;
	WritableP<float> gravity_max;

	void vector();
protected:
	void fall();
private:

	float gravity_ = 0.3f;
	float gravity_max_ = 20;

};