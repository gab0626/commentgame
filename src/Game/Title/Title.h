#pragma once
#include "../SceneBase/CreateScene.h"
#include "../StageSelect/StageSelect.h"
#include "../GameMain/GameMain.h"

//その名の通り
//switch文で使用する列挙
enum SwitchNumber
{
	GAMEFLAG = 1,
	STAGESLECT = 2,
	FATAL = 3,
};

class Title : public SceneBase
{
public:
	Title();
	void update() override;
	void draw() override;
	void shift() override;

private:
	//今のところは使用しないマウスポインタ
	//Vec2f mousePos;

	//スタートボタンを描画するための変数
	Vec2f sButton;
	Vec2f sButtonEnd;

	//タイトルロゴ情報
	Vec2f TitleRogo;
	Vec2f TitleRogoEnd;
	
	//swicth文を動かすための条件値
	int titleSwitch;

	//シーンを切り替える為の変数
	bool gameShift;
	bool stageSelectShift;
	bool fatalShift;
};