#include "Group.h"

//-----------------------------------------------------------------------------
Group::Group() 
{
	inputGroup();
}
//-----------------------------------------------------------------------------
Group::Group(const std::vector<int> group)
{
	for (int i = 0; i < group.size(); i++)
		m_group.push_back(group[i]);
}
//-----------------------------------------------------------------------------
void Group::inputGroup() 
{
	int size_of_vector, num;
	std::cin >> size_of_vector;
	for (int i = 0; i < size_of_vector; i++)
	{
		std::cin >> num;
		m_group.push_back(num);
	}
	std::ranges::sort(m_group);
	auto [newEnd, end] = std::ranges::unique(m_group);
	m_group.erase(newEnd, end);
}
//-----------------------------------------------------------------------------
std::vector<int> Group::getGroup() const 
{
	return m_group;
}
//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const Group& group)
{
	os << "{ ";
	for (int i = 0; i < group.getGroup().size(); i++)
	{
		os << group.getGroup()[i] ;
		if (i < group.getGroup().size() - 1)
			os << ", ";
	}
	os << " }";
	return os;
}