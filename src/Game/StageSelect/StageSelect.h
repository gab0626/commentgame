#pragma once
#include "../SceneBase/CreateScene.h"
#include "../Title/Title.h"

class StageSelect : public SceneBase
{
public:
	StageSelect();
	void update() override;
	void draw() override;
	void shift() override;

private:

};