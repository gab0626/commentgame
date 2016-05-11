#pragma once
#include "Player.h"
#include <assert.h>

#define P_Manager PlayerManager::get()
#define GetPlayer P_Manager.getPlayer()

class PlayerManager {
public:
	
	static PlayerManager& get() 
	{
		static PlayerManager pm;
		return pm;
	}
	PlayerManager()
	{
		
	}
	~PlayerManager(){}

	std::shared_ptr<Player> getPlayer() 
	{
		if (p_player == nullptr)
		{
			assert(!"Player null !!!");
		}

		return p_player;
	}

	void createPlayer(std::string filename) 
	{
		std::ifstream open = std::ifstream(filename);

		Vec2f pos, size;
		open >> pos.x() >> pos.y();
		open >> size.x() >> size.y();

		p_player = std::make_shared<Player>(pos,size);
	}

private:
	std::shared_ptr<Player> p_player;

};