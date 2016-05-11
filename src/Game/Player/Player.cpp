#include "Player.h"

Player::Player(Vec2f _pos, Vec2f _size) :
	CharacterBase(_pos, _size)
{
}

Player::~Player()
{
}

void Player::update()
{
	move();
	fall();
	vector();
}

void Player::draw()
{
	drawBox(pos.x(), pos.y(), size.x(), size.y(), 5, Color::white,
			0,
			Vec2f(1, 1),
			Vec2f(size.x() / 2, size.y() / 2));
}

void Player::setPos(Vec2f _pos)
{
	pos = _pos;
}

void Player::setSize(Vec2f _size)
{
	size = _size;
}

Vec2f Player::getPos()
{
	return pos;
}

Vec2f Player::getSize()
{
	return size;
}

void Player::move()
{
	float speed = 10;
	vec_.x() = 0.0f;
	if (env.isPressKey('A'))
	{
		vec_.x() = -speed;
	}
	if (env.isPressKey('D'))
	{
		vec_.x() = speed;
	}
}

