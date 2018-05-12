#include "Proxy.h"

void Proxy::Init(Mode mode) {
	MODE = mode;
}

void Proxy::onAttack(Hero &from,Hero &to) {
	if(MODE == Client) {
		GameMode::getGameMode()->onAttack(from,to);
	}
	else {
		//call �����
	}
}

Proxy * Proxy::getProxy() {
	//static Proxy* proxy = new Proxy();
	return &proxy;
}
