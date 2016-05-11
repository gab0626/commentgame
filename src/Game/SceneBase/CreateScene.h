#pragma once
#include "../AppEnv.h"
#include "SceneBase.h"

class Scene
{
public:
	template<typename ty>
	static void create(ty* _scene) {
		scene = std::make_shared<ty>(*_scene);
	};

	static SceneBase& get() {
		return *scene;
	}

private:
	static std::shared_ptr<SceneBase> scene;
};
