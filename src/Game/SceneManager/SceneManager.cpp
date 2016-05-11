#include "SceneManager.h"

SceneManager::SceneManager()
{
	Scene::create<Title>(new Title());
}

void SceneManager::update()
{
	Scene::get().update();
}

void SceneManager::draw()
{
	Scene::get().draw();
}

void SceneManager::shift()
{
	Scene::get().shift();
}


