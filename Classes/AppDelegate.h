#pragma once
#include "cocos2d.h"

class  AppDelegate: private cocos2d::Application {
public:
	AppDelegate();
	virtual ~AppDelegate();

	virtual void initGLContextAttrs();

	virtual bool applicationDidFinishLaunching();

	// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
	virtual void applicationDidEnterBackground();

	// this function will be called when the app is active again
	virtual void applicationWillEnterForeground();
};
