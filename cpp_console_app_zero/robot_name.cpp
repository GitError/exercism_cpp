#include "robot_name.h"
#include <regex>

namespace robot_name {
	std::unordered_set<std::string> robot_name::robot::used_names_;

	bool validate_name(const std::string& name) {
		std::regex name_pattern("[A-Z]{2}[0-9]{3}");
		return std::regex_match(name, name_pattern);
	}
}