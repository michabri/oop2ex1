#pragma once
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "Action.h"
#include "Union.h"
#include "Intersection.h"
#include "Difference.h"

class Calculator {
public:
	Calculator();
	void run();

private:
	std::vector<std::shared_ptr<Action>> m_menu_actions;
	void printMenu();
	void printHelp();
};