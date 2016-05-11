#pragma once
#include "../Bomb/Bomb.h"
#include "../Bow/Bow.h"


class ItemManager
{
public:

	ItemManager();
	~ItemManager();



private:

	std::list<ItemBase*> item_list;

	void update();
	void draw();
};