#include "series.h"
#include <stdexcept>

namespace series {
	std::vector<std::string> slice(const std::string& digits, int length) {
		if (digits.empty()) {
			throw std::domain_error("Cannot slice an empty series");
		}
		if (length <= 0) {
			throw std::domain_error("Slice length cannot be zero or negative");
		}
		if (length > static_cast<int>(digits.length())) {
			throw std::domain_error("Slice length cannot be greater than series length");
		}
		std::vector<std::string> result;
		for (size_t i = 0; i <= digits.length() - length; ++i) {
			result.push_back(digits.substr(i, length));
		}
		return result;
	}
}