#include "GameMain.h"
#include "../Title/Title.h"

GameMain::GameMain()
{
	int _stage_num = 10;
	P_Manager.createPlayer("res/stage/stage" + std::to_string(_stage_num) + "/Player.txt");
	map.Load(_stage_num);
}

GameMain::~GameMain()
{
	Easing::Clear();
}

void GameMain::update()
{
	map.update();
	ui.update();
	enemyholder.update();
	GetPlayer->update();


	GetPlayer->addpos(map.collision(GetPlayer->getPos(), GetPlayer->getSize(), GetPlayer->vec));
	camera_pos = GetPlayer->getPos();


	if (env.isPushButton(Mouse::RIGHT)) {
		map.breakBlock(GetPlayer->getPos());
	}

}

void GameMain::draw()
{
	glPushMatrix();
	glTranslated(-camera_pos.x(), -camera_pos.y(), 0);
	map.draw();
	enemyholder.draw();
	GetPlayer->draw();
	Vec2f a;
	a = GetPlayer->getPos();
	drawPoint(a.x(), a.y(), 100, Color::white);

	glPopMatrix();

	ui.draw();
}

void GameMain::shift()
{
	if (env.isPushButton(Mouse::LEFT)) {
		Scene::create<Title>(new Title());
	}
}
