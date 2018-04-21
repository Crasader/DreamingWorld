#include"CharacterScene.h"
#include"Others.h"
#include"Resource.h"
#include"ConsoleLayer.h"
#include<ui/CocosGUI.h>

USING_NS_CC;

bool CharacterScene::init() {
	if(!Scene::init()) {
		return false;
	}
	//BackButton
	auto BackButton = ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	BackButton->setPosition(Vec2(23, 745));
	BackButton->setScale9Enabled(true);
	BackButton->setContentSize(Size(40, 40));
	BackButton->addTouchEventListener(
		[&](Ref* sender, ui::Widget::TouchEventType type) {
			switch(type) {
			case ui::Widget::TouchEventType::ENDED:

				Director::getInstance()->popScene();
				break;
			}
		}
	);
	auto BackButtonLabel = Label::createWithTTF(u8"<-", FONTS_KAI, 32);
	BackButtonLabel->setColor(Color3B(0, 0, 0));
	BackButton->setTitleLabel(BackButtonLabel);
	this->addChild(BackButton);

	//Key
	CONSOLE_KEY;

	return true;
}