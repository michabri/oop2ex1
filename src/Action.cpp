#include "Action.h"

//-----------------------------------------------------------------------------
std::shared_ptr<Action> Action::getAction1() const {
	return m_action1;
}
//-----------------------------------------------------------------------------
std::shared_ptr<Action> Action::getAction2() const {
	return m_action2;
}
//-----------------------------------------------------------------------------
void Action::printAction() const {
	char group_name = 'A';
	if (m_action1 == nullptr && m_action2 == nullptr)
	{
		std::cout << "(" << group_name << " " << m_action_type  << " " << ++group_name << ")";
	}
	else
	{
		std::cout << "(";
		m_action1->printAction();
		std::cout << " " << m_action_type << " ";
		m_action2->printAction();
		std::cout << ")";
	}
}