#include "perfect_numbers.h"
#include <cmath>
#include <stdexcept>

namespace perfect_numbers {
	classification classify(int n) {
		if (n <= 0) {
			throw std::domain_error("Classification is only possible for positive integers.");
		}
		int aliquot_sum = 1; // 1 is a factor of every positive integer
		for (int i = 2; i <= std::sqrt(n); ++i) {
			if (n % i == 0) {
				aliquot_sum += i;
				if (i != n / i) {
					aliquot_sum += n / i;
				}
			}
		}
		if (aliquot_sum == n) {
			return classification::perfect;
		}
		else if (aliquot_sum > n) {
			return classification::abundant;
		}
		else {
			return classification::deficient;
		}
	}
}