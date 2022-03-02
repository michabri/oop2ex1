#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

class Group {
public:
	Group();
	Group(const std::vector<int>);
	std::vector<int> getGroup() const;

private:
	std::vector<int> m_group;
	void inputGroup();
};

std::ostream& operator<<(std::ostream& os, const Group&);