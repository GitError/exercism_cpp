#include "log_line.h"

namespace log_line {
	std::string message(std::string line) {
		return line.substr(line.find("]:") + 3);
	}

	std::string log_level(std::string line) {
		return line.substr(1, line.find("]") - 1);
	}

	std::string reformat(std::string line) {
		return log_line::message(line) + " (" + log_line::log_level(line) + ")";
	}
}