#pragma once
#include "GameMode.h"
#include "Hero.h"

enum Mode {
	Remote,
	Client
};

class Proxy {
public:
	void Init(Mode mode);
	void onAttack(Hero &from, Hero &to);

	Mode MODE;
private:
	Proxy();
	static Proxy* getProxy();
	static Proxy proxy;
	//Proxy* proxy = new Proxy();
};