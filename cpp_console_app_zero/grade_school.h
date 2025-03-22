#pragma once

#include <map>
#include <vector>
#include <string>

namespace grade_school {
	class school {
	private:
		std::map<int, std::vector<std::string>> students;

	public:
		void add(const std::string& name, int grade);
		std::vector<std::string> grade(int grade) const;
		std::map<int, std::vector<std::string>> roster() const;
	};
}