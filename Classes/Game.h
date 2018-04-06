#pragma once

class Game {
private:
	Game() = default;
public:
	~Game() = default;
	static Game* Get();
};