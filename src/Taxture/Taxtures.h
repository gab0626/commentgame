#pragma once
#include "../AppEnv.h"

class Textures
{
public:
	//画像の識別子
	//画像のパス（参照先）
	static void set(std::string _path, std::string _texturename) {

		if (t.find(_path) == t.end()) {
			t[_path] = Texture(_texturename);
		}

	}
	//画像の識別子
	static Texture get(std::string _path) {

		return t[_path];
	}

private:
	static std::unordered_map<std::string, Texture> t;
};