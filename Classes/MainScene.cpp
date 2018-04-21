#include"MainScene.h"
#include"CharacterScene.h"
#include"Others.h"
#include"Resource.h"
#include"ConsoleLayer.h"
#include"ConsoleManager.h"
#include<ui/CocosGUI.h>

USING_NS_CC;

bool MainScene::init() {
	if(!Scene::init()) {
		return false;
	}
	auto VisionSize = Director::getInstance()->getVisibleSize();

	//Keyboard
	CONSOLE_KEY;

	//Background
	auto Background = Sprite::create(DIR_IMAGES + "Background.png");
	Background->setPosition(Vec2(VisionSize.width / 2, VisionSize.height / 2));
	Background->setContentSize(VisionSize);
	this->addChild(Background);

	//CharacterButton
	this->addChild(CreateDefaultButton("Character", Vec2(664, 62), Size(80, 80),
				   [](Ref* sender, ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::ENDED) {
						   Director::getInstance()->pushScene(CharacterScene::create());
					   }
				   },
				   u8"人物", FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//BagButton
	this->addChild(CreateDefaultButton("Bag", Vec2(746, 62), Size(80, 80),
				   [](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::ENDED) {
						   //TODO: BagLayer
					   }
				   },
				   u8"背包", FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	//ShopButton
	this->addChild(CreateDefaultButton("Shop", Vec2(828, 62), Size(80, 80),
				   [](cocos2d::Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
					   if(type == ui::Widget::TouchEventType::ENDED) {
					   }
				   },
				   u8"商店", FONTS_KAI, 32, Color3B(0, 0, 0))
	);

	ConsoleManager::Get()->
		AddCommand("/setpos", 3,
				   [&](std::vector<std::string> t)->bool {
					   this->getChildByName(t[0])->setPosition(Vec2(std::stof(t[1]), std::stof(t[2])));
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/setsize", 3,
				   [&](std::vector<std::string> t)->bool {
					   this->getChildByName(t[0])->setContentSize(Size(std::stof(t[1]), std::stof(t[2])));
					   return true;
				   }
	);
	ConsoleManager::Get()->
		AddCommand("/addbtn", 6,
				   [&](std::vector<std::string> t)->bool {
					   this->addChild(CreateDefaultButton(t[0], Vec2(std::stof(t[1]), std::stof(t[2])), Size(std::stof(t[3]), std::stof(t[4])),
									  [](Ref* sender, ui::Widget::TouchEventType type) {},
									  t[5], FONTS_KAI, 32, Color3B(0, 0, 0))
					   );
					   return true;
				   }
	);

	return true;
}