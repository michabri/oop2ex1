#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <string>
#include "Action.h"
#include "Union.h"

class Calculator {
public:
	Calculator();
	void run();

private:
	std::vector<std::shared_ptr<Action>> m_menu_actions;
	void printMenu();
	void printHelp();
};