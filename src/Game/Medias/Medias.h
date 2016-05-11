#pragma once
#include "../AppEnv.h"

class Medias
{
public:
	static void set(std::string _path, std::string _texturename) {
		if (media.find(_path) == media.end()) {
			media[_path] = std::make_shared<Media>(_texturename);
		}

	}
	static Media get(std::string _path) {
		return *media[_path];
	}
private:
	static std::unordered_map<std::string, std::shared_ptr<Media>> media;
};