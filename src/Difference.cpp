#include "Difference.h"

//-----------------------------------------------------------------------------
Difference::Difference()
{
	m_action_type = '-';
	m_action1 = nullptr;
	m_action2 = nullptr;
}
//-----------------------------------------------------------------------------
Difference::Difference(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2)
{
	m_action_type = '-';
	m_action1 = action1;
	m_action2 = action2;
}
//-----------------------------------------------------------------------------
Group Difference::evaluate(std::ostringstream* os) const
{
	std::vector<int> result_group;

	if (m_action1 == nullptr && m_action2 == nullptr)
	{
		Group a, b;
		*os << "(" << a << " - " << b << ")";
		std::ranges::set_difference(a.getGroup(), b.getGroup(), std::back_inserter(result_group));
	}
	else
		return evaluate(os, m_action1, m_action2);
	return Group(result_group);
}
//-----------------------------------------------------------------------------
Group Difference::evaluate(std::ostringstream* os, std::shared_ptr<Action> action1, std::shared_ptr<Action> action2) const
{
	Group a(action1->evaluate(os));
	*os << " - " ;
	Group b(action2->evaluate(os));
	
	std::vector<int> result_group;
	std::ranges::set_difference(a.getGroup(), b.getGroup(), std::back_inserter(result_group));
	return Group(result_group);
}