#pragma once
#include "GameState.h"

class GameMode {
public:
	static GameMode* getGameMode();
	void Init();
	GameState* getGameState();
private:
	GameMode() = default;

	GameState *gameState = nullptr;
};