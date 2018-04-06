//#include "HelloWorldScene.h"
//#include "SimpleAudioEngine.h"
//#include"ShellLayer.h"
//USING_NS_CC;
//
//Scene* HelloWorld::createScene() {
//	return HelloWorld::create();
//}
//
//// Print useful error message instead of segfaulting when files are not there.
//static void problemLoading(const char* filename) {
//	printf("Error while loading: %s\n", filename);
//	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
//}
//
//// on "init" you need to initialize your instance
//bool HelloWorld::init() {
//	//////////////////////////////
//	// 1. super init first
//	if(!Scene::init()) {
//		return false;
//	}
//
//	auto visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();
//
//	/////////////////////////////
//	// 2. add a menu item with "X" image, which is clicked to quit the program
//	//    you may modify it.
//
//	// add a "close" icon to exit the progress. it's an autorelease object
//	auto closeItem = MenuItemImage::create(
//		"CloseNormal.png",
//		"CloseSelected.png",
//		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//
//	if(closeItem == nullptr ||
//	   closeItem->getContentSize().width <= 0 ||
//	   closeItem->getContentSize().height <= 0) {
//		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
//	}
//	else {
//		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
//		float y = origin.y + closeItem->getContentSize().height / 2;
//		closeItem->setPosition(Vec2(x, y));
//	}
//
//	// create menu, it's an autorelease object
//	auto menu = Menu::create(closeItem, NULL);
//	menu->setPosition(Vec2::ZERO);
//	this->addChild(menu, 1);
//
//	/////////////////////////////
//	// 3. add your codes below...
//
//	// add a label shows "Hello World"
//	// create and initialize a label
//
//	auto label = Label::createWithTTF(TTFConfig("fonts/consola.ttf", 12), "DiedRadish");
//	if(label == nullptr) {
//		problemLoading("'fonts/consola.ttf'");
//	}
//	else {
//		// position the label on the center of the screen
//		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
//						   origin.y + visibleSize.height - label->getContentSize().height));
//
//		// add the label as a child to this layer
//		this->addChild(label, 1);
//	}
//
//	// add "HelloWorld" splash screen"
//	sp = Sprite::create("HelloWorld.png");
//	if(sp == nullptr) {
//		problemLoading("'HelloWorld.png'");
//	}
//	else {
//		// position the sprite on the center of the screen
//		sp->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
//		sp->setZOrder(1);
//		// add the sprite as a child to this layer
//		this->addChild(sp, 0);
//	}
//
//	//5. keyboard event
//	auto key = EventListenerKeyboard::create();
//	key->onKeyPressed = CC_CALLBACK_2(HelloWorld::onPress, this);
//	key->onKeyReleased = CC_CALLBACK_2(HelloWorld::onRelease, this);
//	_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);
//
//	auto f = ShellLayer::create();
//	f->setZOrder(0);
//	this->addChild(f);
//	return true;
//}
//
//void HelloWorld::menuCloseCallback(Ref* pSender) {
//	//Close the cocos2d-x game scene and quit the application
//	Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//	exit(0);
//#endif
//
//	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
//
//	//EventCustom customEndEvent("game_scene_close_event");
//	//_eventDispatcher->dispatchEvent(&customEndEvent);
//}
//
//void HelloWorld::onPress(EventKeyboard::KeyCode keyCode, Event * event) {
//	if(keyCode == EventKeyboard::KeyCode::KEY_W) {
//		auto mt = MoveTo::create(6, Vec2(sp->getPositionX(), Director::getInstance().);
//		mt->setFlags(1);
//		sp->runAction(mt);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_A) {
//		auto mt = MoveTo::create(6, Vec2(0, sp->getPositionY()));
//		mt->setFlags(2);
//		sp->runAction(mt);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_S) {
//		auto mt = MoveTo::create(6, Vec2(sp->getPositionX(), 0));
//		mt->setFlags(3);
//		sp->runAction(mt);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_D) {
//		auto mt = MoveTo::create(6, Vec2(480, sp->getPositionY()));
//		mt->setFlags(4);
//		sp->runAction(mt);
//	}
//}
//
//void HelloWorld::onRelease(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event) {
//	if(keyCode == EventKeyboard::KeyCode::KEY_W) {
//		sp->stopActionsByFlags(1);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_A) {
//		sp->stopActionsByFlags(2);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_S) {
//		sp->stopActionsByFlags(3);
//	}
//	if(keyCode == EventKeyboard::KeyCode::KEY_D) {
//		sp->stopActionsByFlags(4);
//	}
//}