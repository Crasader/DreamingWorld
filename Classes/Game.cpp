#include "Game.h"

#include"ConsoleManager.h"
#include"Others.h"

Game::Game() {
	ConsoleManager::Get()->
		AddCommand("/history", 0,
				   [&](std::vector<std::string>)->bool {
					   for(auto &t : *ConsoleManager::Get()->GetInput()) {
						   ConsoleManager::Get()->Print(t);
					   }
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/author", 0,
				   [&](std::vector<std::string>)->bool {
					   ConsoleManager::Get()->Print(AUTHOR);
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/version", 0,
				   [&](std::vector<std::string>)->bool {
					   ConsoleManager::Get()->Print(VERSION);
					   return true;
				   }
	);
}

Game * Game::Get() {
	static Game t;
	return &t;
}