#include "SceneManager/SceneManager.h"
#include "AppEnv.h"

int main() {
	
	SceneManager scenemanager;

	while (env.isOpen()) {
		env.begin();
		
		scenemanager.update();
		scenemanager.draw();
		scenemanager.shift();
		
		env.end();
	}
}
