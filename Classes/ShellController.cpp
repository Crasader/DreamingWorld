#include"ShellController.h"

ShellController::ShellController() {
	CmdOutput = "DreamingWorld Command.";
}

ShellController * ShellController::Get() {
	static ShellController t;
	return &t;
}

void ShellController::Move(std::function<void(std::string)> tCB) {
	OutputCallback = tCB;
	OutputCallback(CmdOutput);
}

void ShellController::Input(std::string Cmd) {
	Print("");
	Print(Cmd);
	//TODO: Scan
}

void ShellController::Print(std::string Msg) {
	CmdOutput += '\n';
	CmdOutput += Msg;
	OutputCallback(CmdOutput);
}