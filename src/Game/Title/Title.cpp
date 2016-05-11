#include "Title.h"

Title::Title()
{
	//スタートボタンの初期値情報
	sButton = Vec2f(-100, -100);
	//スタートボタンの終わり値情報
	sButtonEnd = Vec2f(200, 100);

	//タイトルロゴの描画初期値
	TitleRogo = Vec2f(-400, 200);
	//タイトルロゴの描画終わり値
	TitleRogoEnd = Vec2f(800, 200);

	//スイッチ文の条件値
	titleSwitch = 1;

	//それぞれのシーンに切り替えるためのif文
	gameShift = false;
	stageSelectShift = false;
	fatalShift = false;
}

void Title::update()
{
	//今のところ使用しないマウス情報
	//mousePos = env.mousePosition();
	//std::cout << mousePos << std::endl;

	if (env.isPushKey(GLFW_KEY_DOWN))
	{
		//矢印キーの上を押したときに
		//下記のケース文での条件値を増やして動かす。

		titleSwitch += 1;
		if (titleSwitch > 3)
		{
			titleSwitch = 1;
		}
	}
	else if (env.isPushKey(GLFW_KEY_UP))
	{
		//矢印キーの下を押したときに
		//下記のケース文での条件値を減らして動かす。
		titleSwitch -= 1;
		if (titleSwitch < 1)
		{
			titleSwitch = 3;
		}
	}
}

void Title::draw()
{
	switch (titleSwitch)

	{
	default:
		break;

	case GAMEFLAG:
		//ゲーム本編に移行するためのケース文
		gameShift = true;

		if (gameShift == true)
		{
			stageSelectShift = false;
			fatalShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::red);

		break;

	case STAGESLECT:
		//ステージセレクトに移行するためのケース文
		stageSelectShift = true;

		if (stageSelectShift == true)
		{
			gameShift = false;
			fatalShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::white);
		break;

	case FATAL:
		//ゲームを終了するときに使用するケース文
		fatalShift = true;
		
		if (fatalShift == true)
		{
			stageSelectShift = false;
			gameShift = false;
		}

		drawFillBox(sButton.x(), sButton.y(), sButtonEnd.x(), sButtonEnd.y(), Color::blue);

		break;
	}

	drawFillBox(TitleRogo.x(),TitleRogo.y(),TitleRogoEnd.x(),TitleRogoEnd.y(), Color::white);
}

void Title::shift()
{
	if (gameShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//gameShiftがtrueになった時でエンターキーを押したときに
		//ゲーム本編にシフトする。
		Scene::create<GameMain>(new GameMain());
	}

	if (stageSelectShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//stageSelectShiftがtrueの時でエンターキーを押したときに
		//ステージセレクトにシーンを切り替える。
		Scene::create<StageSelect>(new StageSelect());
	}

	if (fatalShift == true && env.isPullKey(GLFW_KEY_ENTER))
	{
		//ゲームを落とす
	}
}

