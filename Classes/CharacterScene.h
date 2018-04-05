#pragma once

#include<cocos2d.h>

class CharacterScene: public cocos2d::Scene {
public:
	CREATE_FUNC(CharacterScene);

	bool init() override;
};