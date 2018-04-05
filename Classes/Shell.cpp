#include"Shell.h"
#include"Others.h"

USING_NS_CC;

bool Shell::init() {
	if(!Layer::init()) {
		return false;
	}
	auto VisibleSize = Director::getInstance()->getVisibleSize();

	//TextField
	CommandText = ui::TextField::create("Shell", FONTS_CONSOLA, 24);
	CommandText->setAnchorPoint(Vec2(0, 0));
	CommandText->setPosition(Vec2(0, 0));
	CommandText->setTextAreaSize(Size(VisibleSize.width - 50, 30));
	CommandText->setContentSize(Size(VisibleSize.width - 50, 30));
	CommandText->setZOrder(2);
	this->addChild(CommandText);

	//Background
	auto LowBackground = LayerColor::create(Color4B(32, 32, 32, 200), VisibleSize.width, 30);
	LowBackground->setZOrder(1);
	this->addChild(LowBackground);
	auto HighBackground = LayerColor::create(Color4B(64, 64, 64, 200), VisibleSize.width, 200);
	HighBackground->setZOrder(1);
	HighBackground->setAnchorPoint(Vec2(0, 0));
	HighBackground->setPosition(0, 30);
	this->addChild(HighBackground);

	//EnterButton
	auto EnterButton = ui::Button::create(DIR_IMAGES + "Button_Normal.png", DIR_IMAGES + "Button_Press.png", DIR_IMAGES + "Button_Disable.png");
	EnterButton->setZOrder(2);
	EnterButton->setAnchorPoint(Vec2(0, 0));
	EnterButton->setPosition(Vec2(VisibleSize.width - 50, 0));
	EnterButton->setScale9Enabled(true);
	EnterButton->setSize(Size(50, 30));
	EnterButton->addTouchEventListener(
		[this](Ref* sender, ui::Widget::TouchEventType type) {
			if(type == ui::Widget::TouchEventType::ENDED) {
				this->Input();
			}
		}
	);
	auto EnterButtonLabel = Label::createWithTTF(u8"È·¶¨", FONTS_KAI, 24);
	EnterButtonLabel->setColor(Color3B(0, 0, 0));
	EnterButton->setTitleLabel(EnterButtonLabel);
	this->addChild(EnterButton);

	//HistoryLabel
	HistoryLabel = Label::createWithTTF("", FONTS_CONSOLA, 24);
	HistoryLabel->setAnchorPoint(Vec2(0, 0));
	HistoryLabel->setPosition(Vec2(0, 30));
	HistoryLabel->setContentSize(Size(VisibleSize.width, 200));
	HistoryLabel->setColor(Color3B(255, 255, 255));
	this->addChild(HistoryLabel);

	return true;
}

void Shell::Input() {
	if(CommandText->getString() != "") {
		HistoryLabel->setString(HistoryLabel->getString() + CommandText->getString() + '\n');
		CommandText->setString("");
	}
}