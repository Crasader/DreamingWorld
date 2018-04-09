#include"ConsoleLayer.h"
#include"ConsoleManager.h"
#include"Others.h"

USING_NS_CC;

bool ConsoleLayer::init() {
	if(!Layer::init()) {
		return false;
	}
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
	InputTextField->addEventListener(
		[&](Ref* ref, ui::TextField::EventType type) {
			if(type == ui::TextField::EventType::INSERT_TEXT) {
				Reset();
			}
		}
	);

	//InputScrollView
	InputScrollView = ui::ScrollView::create();
	InputScrollView->setZOrder(2);
	InputScrollView->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	InputScrollView->setScrollBarEnabled(false);
	InputScrollView->setPosition(Vec2(0, 0));
	InputScrollView->setContentSize(Size(VisibleSize.width - 48, 24));
	InputScrollView->getInnerContainer()->setAnchorPoint(Vec2(1, 0));
	InputScrollView->addChild(InputTextField);
	this->addChild(InputScrollView);

	//OutputLabel
	OutputLabel = Label::createWithTTF("", FONTS_CONSOLA, 20);
	OutputLabel->setAnchorPoint(Vec2(0, 0));
	//OutputLabel->setPosition(Vec2(0, 0));
	//OutputLabel->setContentSize(Size(VisibleSize.width, 0));
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

	//EnterButton
	auto EnterButton = ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	EnterButton->setZOrder(2);
	EnterButton->setAnchorPoint(Vec2(0, 0));
	EnterButton->setPosition(Vec2(VisibleSize.width - 48, 0));
	EnterButton->setScale9Enabled(true);
	EnterButton->setSize(Size(48, 24));
	EnterButton->addTouchEventListener(
		[this](Ref* sender, ui::Widget::TouchEventType type) {
			if(type == ui::Widget::TouchEventType::ENDED) {
				if(InputTextField->getString() != "") {
					ConsoleManager::Get()->Input(InputTextField->getString());
					InputTextField->setString("");
					Reset();
				}
			}
		}
	);
	auto EnterButtonLabel = Label::createWithTTF("OK", FONTS_KAI, 24);
	EnterButtonLabel->setColor(Color3B(0, 0, 0));
	EnterButton->setTitleLabel(EnterButtonLabel);
	this->addChild(EnterButton);

	//ConsoleManager
	ConsoleManager::Get()->Move(
		[&](std::string text) {
			this->OutputLabel->setString(text);
			Reset();
		},
		[&]()->std::string {
			return "";
		}
		);
	Reset();
	return true;
}

void ConsoleLayer::Reset() {
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
	if(InputScrollView->getInnerContainerPosition() != Vec2(DefSize.width, 0)) {
		InputScrollView->setInnerContainerPosition(Vec2(DefSize.width, 0));
	}

	//Set the OutputLabel pos and size.
	Size = OutputLabel->getContentSize();
	DefSize = OutputScrollView->getContentSize();
	if(Size.width < DefSize.width) {
		Size.width = DefSize.width;
	}
	if(Size.height < DefSize.height) {
		Size.height = DefSize.height;
	}
	OutputScrollView->setInnerContainerSize(Size);
	if(OutputScrollView->getInnerContainerPosition() != Vec2(0, 0)) {
		OutputScrollView->setInnerContainerPosition(Vec2(0, 0));
	}
}