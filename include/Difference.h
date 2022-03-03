#pragma once
#include "Action.h"
class Difference : public Action {
public:
	Difference();
	Difference(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2);
	Group evaluate() const override;
	Group evaluate(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2) const override;
private:
};