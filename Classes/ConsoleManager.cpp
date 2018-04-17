#include"ConsoleManager.h"
#include"ConsoleLayer.h"
#include"Others.h"

ConsoleManager::ConsoleManager() {
	CmdOutput = "DreamingWorld Console";
	//CmdInput.push_back("");
	AddCommand("/help", 0,
			   [&](std::vector<std::string>)->bool {
				   Print(CommandHelp());
				   return true;
			   }
	);
}

ConsoleManager* ConsoleManager::Get() {
	static ConsoleManager t;
	return &t;
}

bool ConsoleManager::AddConsole(ConsoleLayer* tConsoleLayer, std::function<void()> tOutputCallback) {
	if(std::find_if(Consoles.begin(), Consoles.end(), [tConsoleLayer](Console& t)->bool {return t.pConsole == tConsoleLayer; }) != Consoles.end()) {
		return false;
	}
	Consoles.push_back({tConsoleLayer, tOutputCallback});
	for(auto &t : Consoles) {
		t.OutputCallback();
	}
	return true;
}

bool ConsoleManager::RemoveConsole(ConsoleLayer * tConsoleLayer) {
	std::vector<Console>::iterator i;
	if((i = std::find_if(Consoles.begin(), Consoles.end(), [tConsoleLayer](Console& t)->bool {return t.pConsole == tConsoleLayer; })) == Consoles.end()) {
		return false;
	}
	Consoles.erase(i);
	for(auto &t : Consoles) {
		t.OutputCallback();
	}
	return true;
}

const std::vector<std::string>* ConsoleManager::GetInput() {
	return &CmdInput;
}

const std::string * ConsoleManager::GetOutput() {
	return &CmdOutput;
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
		Arg.reserve(Args.size());
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

	Print(std::string("Command: ") + Cmd);
	if(Args.size() > 0) {
		if((Commands.find(Args[0])) != Commands.end()) {
			Args.resize(Commands[Args[0]].ArgCount + 1);
			if(!Commands[Args[0]].Callback(std::vector<std::string>(Args.begin() + 1, Args.end()))) {
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
	for(auto &t : Consoles) {
		t.OutputCallback();
	}
}

bool ConsoleManager::AddCommand(std::string tCommandName, std::size_t tArgCount, std::function<bool(std::vector<std::string>)> tCommandCallback) {
	if(Commands.find(tCommandName) != Commands.end()) {
		return false;
	}
	Commands[tCommandName] = Command({tCommandCallback, tArgCount});
	return true;
}

bool ConsoleManager::RemoveCommand(std::string tCommandName) {
	if(Commands.find(tCommandName) == Commands.end()) {
		return false;
	}
	Commands.erase(tCommandName);
	return true;
}

std::string ConsoleManager::CommandHelp() {
	std::string t;
	for(auto &c : Commands) {
		t += c.first;
		t += '\n';
	}
	t.erase(t.end() - 1);
	return t;
}