#include "Proxy.h"

void Proxy::Init(Mode mode) {
	MODE = mode;
}

void Proxy::onAttack() {
	if(MODE == Client) {
		//call ±¾µØÂß¼­²ã
	}
	else {
		//call ÍøÂç²ã
	}
}

Proxy * Proxy::getProxy() {
	static Proxy proxy;
	return &proxy;
}