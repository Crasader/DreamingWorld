#include "Game.h"

Game * Game::Get() {
	static Game t;
	return &t;
}
