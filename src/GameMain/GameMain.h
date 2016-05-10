#pragma once
#include "../SceneBase/CreateScene.h"
#include "../EnemyHolder/EnemyHolder.h"
#include "../Map/Map.h"
#include "../Ui/Ui.h"
#include "../Player/PlayerManager.h"
#include "../AppEnv.h"
#include "../Easing/easing.h"

class GameMain : public SceneBase
{
public:
	GameMain();
	~GameMain();

	void update() override;
	void draw() override;
	void shift() override;

private:
	
	Map map;
	Ui ui;
	EnemyHolder enemyholder;
	
	Vec2f camera_pos;
};