#include"ConsoleLayer.h"
#include"ConsoleManager.h"
#include"Others.h"
#include"Resource.h"

USING_NS_CC;

bool ConsoleLayer::init() {
	if(!Layer::init()) {
		return false;
	}
	HisPos = ConsoleManager::Get()->GetInput()->size();
	auto VisibleSize = Director::getInstance()->getVisibleSize();

	//Background
	auto InputBackground = LayerColor::create(Color4B(32, 32, 32, 200), VisibleSize.width, 24);
	InputBackground->setZOrder(1);
	this->addChild(InputBackground);
	auto OutputBackground = LayerColor::create(Color4B(64, 64, 64, 200), VisibleSize.width, 240);
	OutputBackground->setZOrder(1);
	OutputBackground->setPosition(0, 24);
	this->addChild(OutputBackground);

	//InputTextField
	InputTextField = ui::TextField::create("Type commands here.", FONTS_CONSOLA, 20);
	InputTextField->setAnchorPoint(Vec2(0, 0));
	InputTextField->setInsertText(true);
	InputTextField->addEventListener(
		[&](Ref* ref, ui::TextField::EventType type) {
			if(type == ui::TextField::EventType::INSERT_TEXT) {
				ResetInput();
			}
		}
	);

	//InputScrollView
	InputScrollView = ui::ScrollView::create();
	InputScrollView->setZOrder(2);
	InputScrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	InputScrollView->setScrollBarEnabled(false);
	InputScrollView->setPosition(Vec2(0, 0));
	InputScrollView->setContentSize(Size(VisibleSize.width, 24));
	InputScrollView->getInnerContainer()->setAnchorPoint(Vec2(1, 0));
	InputScrollView->addChild(InputTextField);
	this->addChild(InputScrollView);

	//OutputLabel
	OutputLabel = Label::createWithTTF("", FONTS_CONSOLA, 20);
	OutputLabel->setAnchorPoint(Vec2(0, 0));
	OutputLabel->setColor(Color3B(255, 255, 255));

	//OutputScrollView
	OutputScrollView = ui::ScrollView::create();
	OutputScrollView->setZOrder(2);
	OutputScrollView->setDirection(ui::ScrollView::Direction::BOTH);
	OutputScrollView->setScrollBarEnabled(true);
	OutputScrollView->setPosition(Vec2(0, 24));
	OutputScrollView->setContentSize(Size(VisibleSize.width, 240));
	OutputScrollView->addChild(OutputLabel);
	this->addChild(OutputScrollView);

	//KeyboardEvent
	auto key = EventListenerKeyboard::create();
	key->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event) {
		auto Size = ConsoleManager::Get()->GetInput()->size();
		if(keyCode == EventKeyboard::KeyCode::KEY_ENTER) {
			if(InputTextField->getString() != "") {
				ConsoleManager::Get()->Input(InputTextField->getString());
				InputTextField->setString("");
				ResetInput();
				ResetOutput();
				HisPos = Size + 1;
			}
		}
		if(keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
			if(HisPos > 0) {
				HisPos--;
			}

			if(HisPos < 0) {
				HisPos = 0;
			}
			if(HisPos > Size) {
				HisPos = Size;
			}

			if(HisPos == Size) {
				InputTextField->setString("");
			}
			else {
				InputTextField->setString((*(ConsoleManager::Get()->GetInput()))[HisPos]);
			}
		}
		if(keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
			HisPos++;

			if(HisPos < 0) {
				HisPos = 0;
			}
			if(HisPos > Size) {
				HisPos = Size;
			}

			if(HisPos == Size) {
				InputTextField->setString("");
			}
			else {
				InputTextField->setString((*(ConsoleManager::Get()->GetInput()))[HisPos]);
			}
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this->InputTextField);

	//ConsoleManager
	ConsoleManager::Get()->
		AddConsole(this,
				   [&]() {
					   this->OutputLabel->setString(*ConsoleManager::Get()->GetOutput());
					   ResetInput();
					   ResetOutput();
				   }
	);
	ResetInput();
	ResetOutput();

	return true;
}

ConsoleLayer::~ConsoleLayer() {
	ConsoleManager::Get()->RemoveConsole(this);
}

void ConsoleLayer::ResetInput() {
	//Set the InputTextField pos and size.
	auto Size = InputTextField->getContentSize();
	auto DefSize = InputScrollView->getContentSize();
	if(Size.width < DefSize.width) {
		Size.width = DefSize.width;
	}
	if(Size.height < DefSize.height) {
		Size.height = DefSize.height;
	}
	InputScrollView->setInnerContainerSize(Size);
	InputScrollView->setInnerContainerPosition(Vec2(DefSize.width, 0));
}

void ConsoleLayer::ResetOutput() {
	//Set the OutputLabel pos and size.
	auto Size = InputTextField->getContentSize();
	auto DefSize = InputScrollView->getContentSize();
	Size = OutputLabel->getContentSize();
	DefSize = OutputScrollView->getContentSize();
	if(Size.width < DefSize.width) {
		Size.width = DefSize.width;
	}
	if(Size.height < DefSize.height) {
		Size.height = DefSize.height;
	}
	if(!Size.equals(OutputScrollView->getInnerContainerSize())) {
		OutputScrollView->setInnerContainerSize(Size);
	}
	OutputScrollView->setInnerContainerPosition(Vec2(0, 0));
}