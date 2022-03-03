#pragma once
#include "Action.h"
class Intersection : public Action {
public:
	Intersection();
	Intersection(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2);
	Group evaluate() const override;
	Group evaluate(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2) const override;
private:
};