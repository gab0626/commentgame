#pragma once
#include "../Block/Block.h"
#include "../Block/NormaBlock/NormalBlock.h"
#include "../Block/NormaBlock/WhiteBlock/WhiteBlock.h"
#include "../Block/NormaBlock/BlackBlock/BlackBlock.h"
#include "../Block/NormaBlock/Grass/Grass.h"
#include "../Block/NormaBlock/Sand/Sand.h"
#include "../Block/NormaBlock/Needle/Needle.h"
#include "../Block/NormaBlock/Lift/Lift.h"
#include "../Block/NormaBlock/Switch/Switch.h"
#include "../Block/BombBlock/BombBlock.h"

#include <vector>
#include "../Taxture/Taxtures.h"

class Map
{
public:
	Map();
	~Map();
	void update();
	void draw();
	void Load(int);
	Vec2f collision(Vec2f, Vec2f, Vec2f);
	void breakBlock(Vec2f);

private:
	Vec2i sell(Vec2f);

	Vec2f block_size;
	std::vector<std::vector<std::shared_ptr<BlockBase>>> block;


};

