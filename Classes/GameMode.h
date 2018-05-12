#pragma once
#include "GameState.h"
#include "Hero.h"

class GameMode {
public:
	static GameMode* getGameMode();
	void Init();
	GameState* getGameState();

	bool isTurn;//当前是否是自己的回合

	
	bool onAttack(Hero &from,Hero &to);
private:
	GameMode() = default;

	GameState *gameState = nullptr;
};