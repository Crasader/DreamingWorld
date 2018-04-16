#include "Game.h"

#include<cocos2d.h>

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
	ConsoleManager::Get()->
		AddCommand("/exit", 0,
				   [&](std::vector<std::string>)->bool {
					   cocos2d::Director::getInstance()->end();
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/help", 1,
				   [&](std::vector<std::string >t)->bool {
					   //int i = std::stoi(t[0]);
					   ConsoleManager::Get()->Print("Page: " + t[0]);
					   return true;
				   }
	);
}

Game * Game::Get() {
	static Game t;
	return &t;
}