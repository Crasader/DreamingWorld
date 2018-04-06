#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>
#include<string>

class ShellLayer: public cocos2d::Layer {
public:
	virtual bool init() override;

	CREATE_FUNC(ShellLayer);

private:
	cocos2d::ui::TextField* CommandText;
	cocos2d::Label* HistoryLabel;
	cocos2d::ui::ScrollView* HistoryLabelScroll;
	cocos2d::ui::ScrollView* CommandTextScroll;
};