#include "GameMode.h"

GameMode * GameMode::getGameMode() {
	static GameMode gameMode;

	return &gameMode;
}

void GameMode::Init() {
	gameState = GameState::getGameState();

}

GameState * GameMode::getGameState() {
	return gameState;
}
