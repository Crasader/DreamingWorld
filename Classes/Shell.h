#pragma once

#include<cocos2d.h>

class Shell: public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer();

	virtual bool init() override;

	CREATE_FUNC(Shell);

private:
	cocos2d::Label* label;
};