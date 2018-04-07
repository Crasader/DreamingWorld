#include"ConsoleManager.h"

#include<exception>

ConsoleManager::ConsoleManager() {
	CmdOutput = "DreamingWorld Console.";
}

ConsoleManager * ConsoleManager::Get() {
	static ConsoleManager t;
	return &t;
}

void ConsoleManager::Move(std::function<void(std::string)> OCB, std::function<std::string()> SCB) {
	OutputCallback = OCB;
	ScanCallback = SCB;
	OutputCallback(CmdOutput);
}

void ConsoleManager::Input(std::string Cmd) {
	Print("");
	std::vector<std::string> Args;
	std::string Arg;
	for(std::size_t i = 0; i < Cmd.size(); i++) {
		Arg = "";
		if(Cmd[i] == ' ') {
			while(i < Cmd.size() && Cmd[i] == ' ') {
				i++;
			}
			i--;
			continue;
		}
		if(Cmd[i] == '/') {
			while(i < Cmd.size() && Cmd[i] != ' ') {
				Arg += Cmd[i];
				i++;
			}
			Args.push_back(Arg);
			continue;
		}
		if(Cmd[i] == '\"') {
			i++;
			for(; i < Cmd.size(); i++) {
				if(Cmd[i] == '\"' && (i + 1) < Cmd.size() && Cmd[i + 1] == '\"') {
					Arg += '\"';
					i++;
				}
				else if(Cmd[i] == '\"') {
					break;
				}
				else {
					Arg += Cmd[i];
				}
			}
			Args.push_back(Arg);
			continue;
		}
		if(Cmd[i] != '\"'&&Cmd[i] != ' '&&Cmd[i] != '/') {
			while(i < Cmd.size() && Cmd[i] != ' ') {
				Arg += Cmd[i];
				i++;
			}
			Args.push_back(Arg);
			continue;
		}
		throw std::runtime_error("Input Error.");
	}

	//std::string tt;
	//for(auto t : Args) {
	//	tt += t;
	//	tt += " ";
	//}
	//Print(tt);
	//if(Args.size() >= 1 && Args[0] == "/version") {
	//	Print("DreamingWorld Version: 1.0");
	//}
}

void ConsoleManager::Print(std::string Msg) {
	CmdOutput += '\n';
	CmdOutput += Msg;
	OutputCallback(CmdOutput);
}