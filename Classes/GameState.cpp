#include "GameState.h"

GameState * GameState::getGameState() {
	static GameState gameState;
	return &gameState;
}
