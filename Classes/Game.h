#pragma once

class Game {
private:
	Game();
public:
	~Game() = default;
	static Game* Get();
};