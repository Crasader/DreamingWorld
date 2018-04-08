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
	CmdInput.push_back(Cmd);

	Print("");

	char tL, nL;
	std::size_t i = 0;

	auto Set = [&]() {
		tL = Cmd[i];
		nL = (i + 1) < Cmd.size() ? Cmd[i + 1] : ' ';
	};
	auto Next = [&]()->bool {
		i++;
		if(i >= Cmd.size()) {
			return false;
		}
		Set();
		return true;
	};

	Set();
	std::vector<std::string> Args;
	for(; i < Cmd.size(); Next()) {
		std::string Arg;
		if(tL == ' ') {
			while(nL == ' ' && Next()) {
			}
		}
		else if(tL == '/') {
			Arg += tL;
			while(nL != ' ' && Next()) {
				Arg += tL;
			}
			Args.push_back(Arg);
		}
		else if(tL == '\"') {
			while(Next()) {
				if(tL == '\"' && nL == '\"') {
					Arg += '\"';
					Next();
				}
				else if(tL == '\"') {
					break;
				}
				else {
					Arg += tL;
				}
			}
			Args.push_back(Arg);
		}
		else {
			Arg += tL;
			while(nL != ' ' && Next()) {
				Arg += tL;
			}
			Args.push_back(Arg);
		}
	}

	for(auto &t : Args) {
		Print(t);
	}
	if(Args.size() > 0) {
		if(Args[0] == "/history") {
			for(auto &t : CmdInput) {
				Print(t);
			}
		}
		if(Args[0] == "/version") {
			Print("1.0.0");
		}
		if(Args[0] == "/author") {
			Print("DiedRadish & SherryGuantou");
		}
	}
}

void ConsoleManager::Print(std::string Msg) {
	CmdOutput += '\n';
	CmdOutput += Msg;
	OutputCallback(CmdOutput);
}