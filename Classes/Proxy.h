#pragma once
enum Mode {
	Remote,
	Client
};

class Proxy {
public:
	void Init(Mode mode);
	void onAttack();

	Mode MODE;
private:
	Proxy() = default;
	static Proxy* getProxy();
};