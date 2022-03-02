#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include "Action.h"
#include "Union.h"

class Calculator {
public:
	Calculator();
	void run();
	void printMenu();
	void printAction();

private:
	std::vector<std::shared_ptr<Action>> m_menu_actions;
	void printHelp();
};