#include "all_your_base.h"
#include <stdexcept>

namespace all_your_base {
	std::vector<unsigned int> convert(int from_base, const std::vector<unsigned int>& digits, int to_base) {
		// Validate bases
		if (from_base <= 1) {
			throw std::invalid_argument("Input base must be >= 2");
		}
		if (to_base <= 1) {
			throw std::invalid_argument("Output base must be >= 2");
		}

		// Handle empty input
		if (digits.empty()) {
			return {};
		}

		// Convert from input base to decimal
		unsigned int decimal_value = 0;
		for (unsigned int digit : digits) {
			// Validate each digit is valid for the input base
			if (digit >= static_cast<unsigned int>(from_base)) {
				throw std::invalid_argument("All digits must be less than the input base");
			}
			decimal_value = decimal_value * from_base + digit;
		}

		// Handle special case of zero
		if (decimal_value == 0) {
			return {};
		}

		// Convert from decimal to output base
		std::vector<unsigned int> result;
		while (decimal_value > 0) {
			result.insert(result.begin(), decimal_value % to_base);
			decimal_value /= to_base;
		}

		return result;
	}
}