#include "Bow.h"


Bow::Bow() :
	ItemBase(),
	max_arrow_num(10),
	max_arrow_vec(10.0f),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{

}

Bow::Bow(Vec2f _pos, Vec2f _size) :
	ItemBase(_pos, _size, Vec2f::Zero()),
	max_arrow_num(10),
	max_arrow_vec(10.0f),
	arrow_vec(Vec2f::Zero()),
	rad(0.0f)
{

}

Bow::~Bow() {

}

void Bow::update() {

	drawTheBow();
	shootTheBow();

	for (auto arrow : arrows)
		arrow.update();
}

void Bow::draw() {

	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_position.x(), cut_position.y(), cut_size.x(), cut_size.y(), texture, Color(color.x(), color.y(), color.z()));

	/*仮置き*/
	//弓
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::green);
	//予測線
	if (env.isPressKey(GLFW_KEY_ENTER))
		drawLine(pos.x(), pos.y(), pos.x() + (arrow_vec.x() * 10.0f), pos.y() + (arrow_vec.y() * 10.0f), 10, Color(1.0f, 1.0f, 0.0f, 0.5f));
	/*仮置き*/

	for (auto arrow : arrows)
		arrow.draw();
}

void Bow::drawTheBow() {

	if (is_player_have != true)
		return;

	if (!env.isPressKey(GLFW_KEY_ENTER))
		return;

	changeAngle();
}

void Bow::shootTheBow() {

	if (is_player_have != true)
		return;

	if (!env.isPullKey(GLFW_KEY_ENTER))
		return;

	arrow_vec.x() = max_arrow_vec * std::cos(rad);
	arrow_vec.y() = max_arrow_vec * std::sin(rad);

	arrows.emplace_back(Arrow(pos, size, arrow_vec));

	if (arrows.size() <= max_arrow_num)
		return;

	std::list<Arrow>::iterator first_arrow = arrows.begin();
	arrows.erase(first_arrow);
}

void Bow::changeAngle() {

	//上限90度まで
	if (env.isPressKey(GLFW_KEY_UP) && rad < 0.5f)
		rad += 0.05f;
	//下限0度まで
	else if (env.isPressKey(GLFW_KEY_UP) && rad > 0.0f)
		rad -= 0.05f;

}
