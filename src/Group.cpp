#include "Group.h"

//-----------------------------------------------------------------------------
Group::Group() {
	inputGroup;
}
//-----------------------------------------------------------------------------
void Group::inputGroup() 
{
	int num_of_number, num;
	std::cin >> num_of_number;
	for (int i = 0; i < num_of_number; i++)
	{
		std::cin >> num;
		m_group.push_back(num);
	}
}
//-----------------------------------------------------------------------------
Group::Group(const std::vector<int> group) {
	m_group = group;
}
//-----------------------------------------------------------------------------
std::vector<int> Group::getGroup() const {
	return m_group;
}
//-----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os2, const Group& group)
{
	os2 << "{ ";
	for (int i = 0; i < group.getGroup().size(); i++)
	{
		os2 << group.getGroup()[i] ;
		if (i < group.getGroup().size() - 1)
			os2 << ", ";
	}
	os2 << " }";
}