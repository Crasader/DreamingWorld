#pragma once
#include "GameState.h"
#include <string>
typedef unsigned long long Hero_ID;
typedef unsigned short Hero_Level;
struct Hero {
	Hero_ID id;
	std::string name;
	Hero_Level level;
	
	GameState::ItemState package[6];

	GameState::SkillState skills[4];
};