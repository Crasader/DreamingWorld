#pragma once

#include<cocos2d.h>
#include"ConsoleManager.h"

class CharacterScene: public cocos2d::Scene {
public:
	CREATE_FUNC(CharacterScene);

	bool init() override;

	CONSOLE_KEY_PRE;
};