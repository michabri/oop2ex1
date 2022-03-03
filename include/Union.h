#pragma once
#include "Action.h"
#include <sstream>

class Union : public Action{
public:
	Union();
	Union(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2);
	Group evaluate(std::ostringstream* os) const override;
	Group evaluate(std::ostringstream* os, std::shared_ptr<Action> action1, std::shared_ptr<Action> action2) const override;
private:
};