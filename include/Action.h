#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Group.h"

class Action {
public:
	virtual Group evaluate(std::ostringstream* os) const = 0;
	virtual Group evaluate(std::ostringstream*, std::shared_ptr<Action>, std::shared_ptr<Action>) const = 0;
	std::shared_ptr<Action> getAction1() const;
	std::shared_ptr<Action> getAction2() const;
	void printAction() const;

protected:
	std::shared_ptr<Action> m_action1;
	std::shared_ptr<Action> m_action2;
	char m_action_type = '\0';
};