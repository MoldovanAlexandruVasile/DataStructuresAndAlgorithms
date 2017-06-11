#pragma once
#include "MultiMap.h"
#include <iostream>

class UI
{
private:
	MultiMap mm;

public:
	UI();

	void run();
	void init();
	void printMenu();
};