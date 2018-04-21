#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>
#include"ConsoleManager.h"

class CharacterScene: public cocos2d::Scene {
public:
	CREATE_FUNC(CharacterScene);

	bool init() override;

	CONSOLE_KEY_PRE;
};

class CharacterWidget:public cocos2d::ui::Widget {
public:
	CREATE_FUNC(CharacterWidget);

	bool init() override;

private:
	std::string CharName = "Name";
};