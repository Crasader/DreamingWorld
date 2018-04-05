#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>

class Shell: public cocos2d::Layer {
public:
	virtual bool init() override;

	CREATE_FUNC(Shell);

private:
	cocos2d::ui::TextField* CommandText;
	cocos2d::Label* HistoryLabel;
	void Input();
};