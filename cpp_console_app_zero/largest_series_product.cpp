#include "largest_series_product.h"
#include <stdexcept>
#include <algorithm>

namespace largest_series_product {
	int largest_product(const std::string& digits, int span) {
		if (span < 0) {
			throw std::domain_error("Span cannot be negative");
		}
		if (span > static_cast<int>(digits.length())) {
			throw std::domain_error("Span cannot be longer than string length");
		}
		if (digits.empty() && span > 0) {
			throw std::domain_error("Cannot use non-zero span on empty string");
		}
		for (char c : digits) {
			if (!std::isdigit(c)) {
				throw std::domain_error("Input contains non-digit character");
			}
		}
		if (span == 0) {
			return 1;
		}
		int max_product = 0;
		for (size_t i = 0; i <= digits.length() - span; ++i) {
			int product = 1;
			for (int j = 0; j < span; ++j) {
				int digit = digits[i + j] - '0';
				if (digit == 0) {
					product = 0;
					break;
				}
				product *= digit;
			}
			max_product = std::max(max_product, product);
		}
		return max_product;
	}
}