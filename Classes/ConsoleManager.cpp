#include"ConsoleManager.h"
#include"ConsoleLayer.h"
#include"Others.h"

ConsoleManager::ConsoleManager() {
	CmdOutput = "DreamingWorld Console.";
	AddCommand("/history",
			   [&](std::vector<std::string>)->bool {
				   for(auto &t : CmdInput) {
					   Print(t);
				   }
				   return true;
			   }
	);
	AddCommand("/author",
			   [&](std::vector<std::string>)->bool {
				   Print(AUTHOR);
				   return true;
			   }
	);
	AddCommand("/version",
			   [&](std::vector<std::string>)->bool {
				   Print(VERSION);
				   return true;
			   }
	);
}

ConsoleManager* ConsoleManager::Get() {
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
		if(Commands.find(Args[0]) != Commands.end()) {
			if(!Commands[Args[0]](std::vector<std::string>(Args.begin() + 1, Args.end()))) {
				Print("Error: Command.");
			}
		}
		else {
			Print("Error: Command name.");
		}
	}
	else {
		Print("Error: Arg size.");
	}
}

void ConsoleManager::Print(std::string Msg) {
	CmdOutput += '\n';
	CmdOutput += Msg;
	OutputCallback(CmdOutput);
}

bool ConsoleManager::AddCommand(std::string tCommandName, std::function<bool(std::vector<std::string>)> tCommandCallback) {
	if(Commands.find(tCommandName) != Commands.end()) {
		return false;
	}
	//TODO: add the arg counts.
	Commands[tCommandName] = tCommandCallback;
	return true;
}