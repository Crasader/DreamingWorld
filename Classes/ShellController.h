#pragma once

#include<string>
#include<functional>

class ShellController {
private:
	ShellController();
public:
	~ShellController() = default;
	static ShellController* Get();

private:
	std::string CmdOutput;
	std::function<void(std::string)> OutputCallback;

public:
	void Move(std::function<void(std::string)> tCB);

public:
	void Input(std::string Cmd);
	void Print(std::string Msg);
};