#pragma once
#include "GameState.h"
#include <string>

typedef unsigned long long Hero_ID;
typedef unsigned short Hero_Level;
struct Hero {
	Hero_ID id;
	std::string name;
	Hero_Level level;
	
	GameState::ItemState package[6];//装备栏

	GameState::SkillState skills[4];//技能栏

	unsigned int HP=0;//生命值

	unsigned int HP_Max=0;//最大生命值

	unsigned int AD_FromEquipment=0;//面板攻击力

	float AD_Break=0;//护甲穿透

	unsigned int Armor=0;//面板护甲

	void scanAD_F();//解算面板攻击力

	void scanArmor();//解算面板护甲

	void scanAD_Break();//解算面板护甲穿透

	bool beingAttack();//被攻击特效
	bool doingAttack();//攻击特效,返回true表示取消本次事件
};