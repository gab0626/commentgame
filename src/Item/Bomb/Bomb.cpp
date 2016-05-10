#include "Bomb.h"

float getAnimationCutPositionX(
	Vec2f cut_size,
	int& animation_count,
	int animation_display_time,
	int animation_cut_num) {

	return cut_size.x() *
		(static_cast<float>((++animation_count / animation_display_time) % animation_cut_num));

}




Bomb::Bomb() :
	ItemBase(),
	explosion_count(600),
	animation_count(0),
	is_countdown(false),
	is_explosion(false),
	cut_pos(Vec2f::Zero()),
	cut_size(Vec2f(0.0f, 0.0f)),
	color(Vec3f(0.0f, 0.0f, 0.0f))
{

}

Bomb::Bomb(Vec2f _pos, Vec2f _size, Vec2f vec) :
	ItemBase(Vec2f::Zero(), Vec2f::Zero(), vec),
	explosion_count(600),
	animation_count(0),
	is_countdown(false),
	is_explosion(false),
	cut_pos(Vec2f(0.0f, 0.0f)),
	cut_size(Vec2f(0.0f, 0.0f)),
	color(Vec3f(0.0f, 0.0f, 0.0f))
{

}

Bomb::~Bomb() {

}

void Bomb::update() {

	countDown();
	animation();
}

void Bomb::draw() {

	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_position.x(), cut_position.y(), cut_size.x(), cut_size.y(), texture, Color(color.x(), color.y(), color.z()));

	/*‰¼’u‚«*/
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::blue);
	/*‰¼’u‚«*/
}





void Bomb::countDown() {

	if (is_countdown != true || explosion_count <= 0)
		return;

	--explosion_count;

	if (explosion_count <= 0)
		is_explosion = true;
}

void Bomb::animation() {

	if (is_explosion != true)
		return;

	cut_pos.x() = getAnimationCutPositionX(cut_size, animation_count, 20, 6);
}