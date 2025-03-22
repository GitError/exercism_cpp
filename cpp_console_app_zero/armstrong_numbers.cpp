#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers {
	bool is_armstrong_number(int n) {
		int sum = 0;
		int num = n;
		int digits = static_cast<int>(std::log10(n)) + 1;
		while (n > 0) {
			sum += std::pow(n % 10, digits);
			n /= 10;
		}
		return sum == num;
	}
}