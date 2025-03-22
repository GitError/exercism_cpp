#include "luhn.h"

namespace luhn {
	bool valid(std::string digits) {
		digits.erase(remove_if(digits.begin(), digits.end(), isspace), digits.end());
		if (digits.size() <= 1) return false;
		int sum = 0;
		bool even = digits.size() % 2 == 0;
		for (char c : digits) {
			if (!isdigit(c)) return false;
			int digit = c - '0';
			if (even) digit *= 2;
			if (digit > 9) digit -= 9;
			sum += digit;
			even = !even;
		}
		return sum % 10 == 0;
	}
}