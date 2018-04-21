#pragma once

#include<cocos2d.h>
#include<ui/CocosGUI.h>

//#include<string>

#define DIR_ASSETS std::string("Assets/")
#define DIR_FONTS DIR_ASSETS + std::string("Fonts/")
#define DIR_IMAGES DIR_ASSETS + std::string("Images/")

#define FONTS_DENG DIR_FONTS + std::string("Deng.ttf")
#define FONTS_DENG_B DIR_FONTS + std::string("DengB.ttf")
#define FONTS_DENG_L DIR_FONTS + std::string("DengL.ttf")
#define FONTS_KAI DIR_FONTS + std::string("KaiSim.ttf")
#define FONTS_MSYH DIR_FONTS + std::string("Msyh.ttc")
#define FONTS_MSYH_B DIR_FONTS + std::string("MsyhB.ttc")
#define FONTS_MSYH_L DIR_FONTS + std::string("MsyhL.ttc")
#define FONTS_ARIAL DIR_FONTS + std::string("Arial.ttf")
#define FONTS_CONSOLA DIR_FONTS + std::string("Consola.ttf")

inline cocos2d::ui::Button* CreateDefaultButton(std::string Name, cocos2d::Vec2 Pos, cocos2d::Size Size, std::function<void(cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType)> TouchEvent,
												std::string Title, std::string Font, float FontSize, cocos2d::Color3B FontColor) {
	auto Button = cocos2d::ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	Button->setName(Name);
	Button->setPosition(Pos);
	Button->setScale9Enabled(true);
	Button->setContentSize(Size);
	Button->addTouchEventListener(TouchEvent);
	auto ButtonLabel = cocos2d::Label::createWithTTF(Title, Font, FontSize);
	ButtonLabel->setColor(FontColor);
	Button->setTitleLabel(ButtonLabel);
	return Button;
}