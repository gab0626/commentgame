#include "Map.h"

float absmax(float a, float b) {
	if (std::abs(a) > std::abs(b))
		return a;
	return b;
}

Map::Map()
{
	Textures::set("whiteblock", "res/Texture/Block/whitelock.png");
	Textures::set("blackblock", "res/Texture/Block/blacklock.png");
	Textures::set("grass", "res/Texture/Block/grass.png");
	Textures::set("sand", "res/Texture/Block/sand.png");
	Textures::set("thorn", "res/Texture/Block/thorn.png");
	Textures::set("switch", "res/Texture/Block/switch.png");
	Textures::set("rifuto", "res/Texture/Block/rifuto.png");
	Textures::set("bomb", "res/Texture/Block/bomb.png");

}

Map::~Map()
{

}

void Map::update()
{
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			x->update();
		}
	}
}

void Map::draw()
{
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			x->draw();
		}
	}
}

void Map::Load(int _stage_num)
{
	std::ifstream file("res/stage/stage" +
		std::to_string(_stage_num) +
		"/Map.txt");

	assert(file);

	{
		std::ifstream blocksize_file("res/stage/stage" +
			std::to_string(_stage_num) +
			"/BlockSize.txt");
		assert(blocksize_file);
		blocksize_file >> block_size.x();
		blocksize_file >> block_size.y();
	}

	int _width;
	int _height;
	file >> _height;
	file >> _width;

	Vec2f _block_pos;
	int _block_type;
	for (int y = 0; y < _width; y++)
	{
		std::vector<std::shared_ptr<BlockBase>> _block;
		for (int x = 0; x < _height; x++)
		{
			file >> _block_type;
			_block_pos = Vec2f(x * block_size.x(), -y*block_size.y());
			switch (_block_type)
			{
			case  BlockType::WHITEBLOCK:
				_block.push_back(std::make_shared<WhiteBlock>(
					WhiteBlock(_block_pos,
						block_size)));
				break;
			case BLACKBLOCK:
				_block.push_back(std::make_shared<BlackBlock>(
					BlackBlock(_block_pos,
						block_size)));
				break;
			case GRASS:
				_block.push_back(std::make_shared<Grass>(
					Grass(_block_pos,
						block_size)));
				break;
			case SAND:
				_block.push_back(std::make_shared<Sand>(
					Sand(_block_pos,
						block_size)));

				break;
			case THORN:
				_block.push_back(std::make_shared<Needle>(
					Needle(_block_pos,
						block_size)));
				break;
			case SWITCH:
				_block.push_back(std::make_shared<Switch>(
					Switch(_block_pos,
						block_size)));
				break;
			case RIFUTO:
				_block.push_back(std::make_shared<Lift>(
					Lift(_block_pos,
						block_size, Vec2i(0, 5))));
				break;
			case BOMB:
				_block.push_back(std::make_shared<BombBlock>(
					BombBlock(_block_pos,
						block_size)));
				break;
			default:
				_block.push_back(std::make_shared<BlockBase>(BlockBase(_block_pos, block_size)));
				break;
			}

		}
		block.push_back(_block);

		_block.clear();
	}

}

Vec2f Map::collision(Vec2f _pos, Vec2f _size, Vec2f _vec)
{
	Vec2f sinking = Vec2f::Zero();
	Vec2f a;
	for (auto& y : block)
	{
		for (auto& x : y)
		{
			a = x->collision(_pos, _size, _vec);
			sinking.x() = absmax(sinking.x(), a.x());
			sinking.y() = absmax(sinking.y(), a.y());
		}
	}
	return sinking;
}

void Map::breakBlock(Vec2f _pos)
{
	drawPoint(_pos.x(), _pos.y(), 10, Color::white);

	Vec2i _sell = sell(_pos);
	Vec2f _block_pos;

	for (int y = _sell.y() - 1; y <= _sell.y() + 1; y++)
	{
		for (int x = _sell.x() - 1; x <= _sell.x() + 1; x++)
		{
			_block_pos = Vec2f(x * block_size.x(), -y*block_size.y());
			block[y][x] = nullptr;
			block[y][x] = std::make_shared<BlockBase>(BlockBase(_block_pos, block_size));
		}
	}


}


Vec2i Map::sell(Vec2f _pos)
{
	
	return Vec2i(
		std::max(
			1,
			std::min(static_cast<int>(block[0].size()-1),
				static_cast<int>(_pos.x() / block_size.x()))
			),
		std::max(
			1,
			std::min(static_cast<int>(block.size()-1),
				static_cast<int>(-_pos.y() / block_size.y()))
			)
		);
}
