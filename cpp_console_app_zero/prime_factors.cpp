#include "prime_factors.h"

namespace prime_factors {
	std::vector<long long int> of(long long int number) {
		std::vector<long long int> factors;
		for (long long int divisor = 2; number > 1; ++divisor) {
			while (number % divisor == 0) {
				factors.push_back(divisor);
				number /= divisor;
			}
		}
		return factors;
	}
}