#include "nth_prime.h"
#include <stdexcept>

namespace nth_prime {
	bool is_prime(int num) {
		if (num <= 1) return false;
		if (num == 2) return true;
		if (num % 2 == 0) return false;
		for (int i = 3; i * i <= num; i += 2) {
			if (num % i == 0) return false;
		}
		return true;
	}

	int nth(int n) {
		if (n <= 0) throw std::domain_error("n must be positive");
		int count = 0;
		int num = 1;
		while (count < n) {
			++num;
			if (is_prime(num)) {
				++count;
			}
		}
		return num;
	}
}