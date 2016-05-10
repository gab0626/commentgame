#include "Arrow.h"


Arrow::Arrow() :
	ItemBase()
{

}

Arrow::Arrow(Vec2f _pos, Vec2f _size, Vec2f _vec) :
	ItemBase(_pos, _size, _vec)
{

}

Arrow::~Arrow() {

}

void Arrow::update() {

	move();
}

void Arrow::draw() {
	
	//drawTextureBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), cut_position.x(), cut_position.y(), cut_size.x(), cut_size.y(), texture, Color(color.x(), color.y(), color.z()));

	/*‰¼’u‚«*/
	drawFillBox(pos.x() - size.x() / 2, pos.y() - size.y() / 2, size.x(), size.y(), Color::red);
	/*‰¼’u‚«*/
}

void Arrow::move() {

	pos = vec;
}
