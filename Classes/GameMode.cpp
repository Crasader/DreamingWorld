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

bool GameMode::onAttack(Hero &from,Hero &to){
	if(isTurn){
		
		//返回true表示取消事件
		if(from.doingAttack()){
			return true;
		}
		if(to.beingAttack()){
			return true;
		}

		unsigned int AD=from.AD_FromEquipment,Armor=to.Armor,damage=0;
		Armor*=(1-from.AD_Break);
		damage = AD *(1-Armor/(Armor+100));
		to.HP-=damage;
		//TODO: 完成数据运算
		return true;
	}else{
		return false;
	}
}