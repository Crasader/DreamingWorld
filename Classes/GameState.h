#pragma once
#include <string>

typedef unsigned long long Player_ID;
typedef unsigned int Item_Level;
enum ItemMode {
	equipment,
	materia
};
class GameState {
public:
	static GameState* getGameState();

	struct PlayerState {
		std::string name;
		Player_ID Pid;
	};
	struct ItemState {
		Player_ID Iid = 0;
		std::string Iname;
		Item_Level Ilevel = 0;
		ItemMode mode;

		unsigned int num = 0;
	};
	struct SkillState {
		Player_ID Sid;
		std::string Sname;
		Item_Level Slevel;
	};
private:
	GameState() = default;
};
