#include "isbn_verifier.h"
#include <algorithm>

namespace isbn_verifier {
	bool is_valid(std::string isbn) {
		isbn.erase(std::remove(isbn.begin(), isbn.end(), '-'), isbn.end()); // Remove dashes
		if (isbn.size() != 10) {
			return false; // ISBN-10 must be 10 characters long
		}
		int sum = 0;
		for (int i = 0; i < 10; ++i) {
			if (isbn[i] == 'X' && i == 9) {
				sum += 10 * (10 - i);
			}
			else if (isdigit(isbn[i])) {
				sum += (isbn[i] - '0') * (10 - i);
			}
			else {
				return false; // Invalid character found
			}
		}
		return sum % 11 == 0;
	}
}