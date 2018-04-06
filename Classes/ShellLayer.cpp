#include"ShellLayer.h"
#include"ShellController.h"
#include"Others.h"

USING_NS_CC;

bool ShellLayer::init() {
	if(!Layer::init()) {
		return false;
	}
	auto VisibleSize = Director::getInstance()->getVisibleSize();

	//TextField
	CommandText = ui::TextField::create("Type command lines here.", FONTS_CONSOLA, 24);
	CommandText->setAnchorPoint(Vec2(0, 0));
	CommandText->setPosition(Vec2(0, 0));
	CommandText->setContentSize(Size(VisibleSize.width - 50, 30));
	CommandText->addEventListener(
		[&](Ref* ref, ui::TextField::EventType type) {
			if(type == ui::TextField::EventType::INSERT_TEXT) {
				CommandTextScroll->setInnerContainerSize(CommandText->getContentSize());
				CommandText->setPosition(Vec2(0, 0));
				CommandTextScroll->setInnerContainerPosition(Vec2(CommandTextScroll->getContentSize().width - CommandTextScroll->getInnerContainerSize().width, 0));
			}
		}
	);

	//CommandTextScrollView
	CommandTextScroll = ui::ScrollView::create();
	CommandTextScroll->setZOrder(2);
	CommandTextScroll->setPosition(Vec2(0, 0));
	CommandTextScroll->setContentSize(Size(VisibleSize.width - 50, 30));
	CommandTextScroll->setInnerContainerSize(CommandText->getContentSize());
	CommandTextScroll->setDirection(ui::ScrollView::Direction::HORIZONTAL);
	CommandTextScroll->setScrollBarEnabled(false);
	CommandTextScroll->addChild(CommandText);
	this->addChild(CommandTextScroll);

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
				if(CommandText->getString() != "") {
					ShellController::Get()->Input(CommandText->getString());
					CommandText->setString("");
					CommandTextScroll->setInnerContainerSize(CommandText->getContentSize());
					CommandText->setPosition(Vec2(0, 0));
					CommandTextScroll->setInnerContainerPosition(Vec2(CommandTextScroll->getContentSize().width - CommandTextScroll->getInnerContainerSize().width, 0));
				}
			}
		}
	);
	auto EnterButtonLabel = Label::createWithTTF("OK", FONTS_KAI, 24);
	EnterButtonLabel->setColor(Color3B(0, 0, 0));
	EnterButton->setTitleLabel(EnterButtonLabel);
	this->addChild(EnterButton);

	//HistoryLabel
	HistoryLabel = Label::createWithTTF("", FONTS_CONSOLA, 24);
	HistoryLabel->setAnchorPoint(Vec2(0, 1));
	HistoryLabel->setPosition(Vec2(0, 0));
	HistoryLabel->setContentSize(Size(VisibleSize.width, 0));
	HistoryLabel->setColor(Color3B(255, 255, 255));

	//HistoryLabelScrollView
	HistoryLabelScroll = ui::ScrollView::create();
	HistoryLabelScroll->setZOrder(2);
	HistoryLabelScroll->setPosition(Vec2(0, 30));
	HistoryLabelScroll->setContentSize(Size(VisibleSize.width, 200));
	HistoryLabelScroll->setInnerContainerSize(HistoryLabel->getContentSize());
	HistoryLabelScroll->setDirection(ui::ScrollView::Direction::BOTH);
	HistoryLabelScroll->setScrollBarEnabled(true);
	HistoryLabelScroll->addChild(HistoryLabel);
	this->addChild(HistoryLabelScroll);

	//ShellController
	ShellController::Get()->Move(
		[&](std::string text) {
			this->HistoryLabel->setString(text);
			HistoryLabelScroll->setInnerContainerSize(HistoryLabel->getContentSize());
			HistoryLabel->setPosition(Vec2(0, HistoryLabel->getContentSize().height));
			HistoryLabelScroll->setInnerContainerPosition(Vec2(0, 0));
		}
	);

	return true;
}