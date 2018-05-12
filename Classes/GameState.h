#pragma once
#include <string>
#include <vector>
#include "Hero.h"

typedef unsigned long long Player_ID;
typedef unsigned short Item_Level;

class GameState
{
  public:
	static GameState *getGameState();

	struct ItemState
	{
		Player_ID Iid = 0;
		std::string Iname;
		Item_Level Ilevel = 0;
		ItemMode mode;

		unsigned int num = 0;

		unsigned int AD=0;//武器类型增加的攻击力
		unsigned int Armor=0;//护甲
		float AD_Break=0;//护甲穿透

		bool beingAttack();//被攻击特效
		bool doingAttack();//攻击特效
	};

	struct SkillState
	{
		Player_ID Sid;
		std::string Sname;
		Item_Level Slevel;
	};

	/*每个玩家的信息

	TODO: 完善玩家信息系统
	*/
	struct PlayerState
	{

		std::string name; //昵称

		Player_ID Pid = 0; //ID

		unsigned int Plevel = 0; //玩家的的等级

		std::vector<ItemState> bag; //背包中的为物品信息

		std::vector <Hero> heros;
	};

	/*当前本地用户控制的玩家信息*/
	PlayerState Powner;

	std::vector<Hero> herosInFighting[2];//正在对阵的英雄信息
  private:
	GameState() = default;
};
enum ItemMode
{
	equipment,
	materia
};