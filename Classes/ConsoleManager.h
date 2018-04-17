#pragma once

#include<string>
#include<vector>
#include<map>
#include<functional>

class ConsoleLayer;

class ConsoleManager {
private:
	ConsoleManager();
public:
	~ConsoleManager() = default;
	static ConsoleManager* Get();

private:
	struct Console {
		ConsoleLayer* pConsole;
		std::function<void()> OutputCallback;
	};
	std::vector<Console> Consoles;
public:
	bool AddConsole(ConsoleLayer* tConsoleLayer, std::function<void()> tOutputCallback);
	bool RemoveConsole(ConsoleLayer* tConsoleLayer);

private:
	struct Command {
		std::function<bool(std::vector<std::string>)> Callback;
		std::size_t ArgCount;
	};
	std::map<std::string, Command> Commands;
public:
	bool AddCommand(std::string tCommandName, std::size_t tArgCount,
					std::function<bool(std::vector<std::string>)> tCommandCallback);
	bool RemoveCommand(std::string tCommandName);
	std::string CommandHelp();

private:
	std::string CmdOutput;
	std::vector<std::string> CmdInput;

public:
	const std::vector<std::string>* GetInput();
	const std::string* GetOutput();
public:
	void Input(std::string Cmd);
	void Print(std::string Msg);
};

#define CONSOLE_KEY_PRE private: \
bool ShellOpened;

#define CONSOLE_KEY ShellOpened = false; \
auto key = EventListenerKeyboard::create(); \
key->onKeyReleased = [this](cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event) { \
	if(keyCode == EventKeyboard::KeyCode::KEY_DELETE) { \
		if(ShellOpened) { \
			this->removeChildByName("Shell"); \
		} \
		else { \
			auto tShell = ConsoleLayer::create(); \
			tShell->setName("Shell"); \
tShell->setZOrder(256);\
			this->addChild(tShell); \
		} \
		ShellOpened = !ShellOpened; \
	} \
}; \
_eventDispatcher->addEventListenerWithSceneGraphPriority(key, this);
