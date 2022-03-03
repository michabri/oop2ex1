#pragma once
#include <sstream>
#include "Action.h"

class Intersection : public Action {
public:
	Intersection();
	Intersection(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2);
	Group evaluate(std::ostringstream* os) const override;
	Group evaluate(std::ostringstream* os, std::shared_ptr<Action>, std::shared_ptr<Action>) const override;
private:
};