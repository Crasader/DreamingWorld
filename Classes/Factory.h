#pragma once
#include "GameState.h"
#include <JsonCpp/json/value.h>

class Factory {
public:
	GameState::ItemState getItem(Json::Value &root);
};