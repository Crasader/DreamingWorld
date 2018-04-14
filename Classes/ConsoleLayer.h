#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>
#include<string>

class ConsoleLayer: public cocos2d::Layer {
public:
	virtual bool init() override;
	CREATE_FUNC(ConsoleLayer);
	~ConsoleLayer() override;

private:
	cocos2d::ui::TextField* InputTextField;
	cocos2d::Label* OutputLabel;
	cocos2d::ui::ScrollView* OutputScrollView;
	cocos2d::ui::ScrollView* InputScrollView;
	void Reset();
};