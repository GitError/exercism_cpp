#include "phone_number.h"
#include <stdexcept>

namespace phone_number {
	phone_number::phone_number(const std::string& input) {
		// Extract only digits from the input
		std::string digits;
		for (char c : input) {
			if (std::isdigit(c)) {
				digits.push_back(c);
			}
		}
		// Check length and handle country code
		if (digits.length() == 11) {
			if (digits[0] != '1') {
				throw std::domain_error("11 digits must start with 1");
			}
			digits.erase(0, 1); // Remove country code
		}
		else if (digits.length() != 10) {
			throw std::domain_error("Invalid number of digits");
		}
		// Validate area code and exchange code
		if (digits[0] == '0' || digits[0] == '1') {
			throw std::domain_error("Area code cannot start with 0 or 1");
		}
		if (digits[3] == '0' || digits[3] == '1') {
			throw std::domain_error("Exchange code cannot start with 0 or 1");
		}
		cleaned_number = digits;
	}

	std::string phone_number::number() const {
		return cleaned_number;
	}
}