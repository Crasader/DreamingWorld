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

public:
	void Move(std::function<void(std::string)> OCB, std::function<std::string()> SCB);

private:
	std::string CmdOutput;
	std::vector<std::string> CmdInput;

private:
	std::function<void(std::string)> OutputCallback;
	std::function<std::string()> ScanCallback;
public:
	void Input(std::string Cmd);
	void Print(std::string Msg);

private:
	struct Command {
		std::function<bool(std::vector<std::string>)> Callback;
		std::size_t ArgCount;
	};
	std::map<std::string, Command> Commands;
public:
	bool AddCommand(std::string tCommandName, std::size_t tArgCount,
					std::function<bool(std::vector<std::string>)> tCommandCallback);
};