#include "Union.h"

//-----------------------------------------------------------------------------
Union::Union() {
	m_action_type = 'U';
	m_action1 = nullptr;
	m_action2 = nullptr;
}
//-----------------------------------------------------------------------------
Union::Union(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2) {
	m_action_type = 'U';
	m_action1 = action1;
	m_action2 = action2;
}
//-----------------------------------------------------------------------------
Group Union::evaluate() const {
	std::vector<int> result_group;
	
	if (m_action1 == nullptr && m_action2 == nullptr)
	{
		Group a;
		Group b;
		std::cout << "(" << a << " U " << b << ")" << " = ";
		std::ranges::set_union(a.getGroup(), b.getGroup(), std::back_inserter(result_group));
	}
	else
		return evaluate(m_action1, m_action2);
}
//-----------------------------------------------------------------------------
Group Union::evaluate(const std::shared_ptr<Action> action1, const std::shared_ptr<Action> action2) const {
	Group a = m_action1->evaluate();
	Group b = m_action2->evaluate();
	std::vector<int> result_group;

	std::cout << a << " U " << b;
	std::ranges::set_union(a.getGroup(), b.getGroup(), std::back_inserter(result_group));

	return Group(result_group);
}