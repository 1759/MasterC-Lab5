#pragma once
#include "DynamicVector.h"


class WatchList {
private:
	DynamicVector tutorials;
	int current;

public:
	WatchList() {}
	void likeTutorial(const Tutorial& tutorial);
	
	Tutorial getCurrentTutorial();
	void play();
	void next();
	bool isEmpty();
};


