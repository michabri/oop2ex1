#pragma once
#include "Action.h"


class Union : public Action{
public:
	Union();
	Union(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2);
	Group evaluate() const override;
	Group evaluate(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2) const override;
private:
};