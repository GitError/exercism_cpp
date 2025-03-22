#include "grade_school.h"
#include <algorithm>

namespace grade_school {
	void school::add(const std::string& name, int grade)
	{
		students[grade].push_back(name);
		std::sort(students[grade].begin(), students[grade].end());
	}

	std::map<int, std::vector<std::string>> school::roster() const
	{
		return students;
	}

	std::vector<std::string> school::grade(int grade) const {
		if (students.find(grade) == students.end())
			return {};
		return students.at(grade);
	}
}