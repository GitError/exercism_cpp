#include "sieve.h"

namespace sieve {
	std::vector<int> primes(int n) {
		std::vector<int> primes;
		std::vector<bool> is_prime(n + 1, true);
		for (int p = 2; p * p <= n; ++p) {
			if (is_prime[p]) {
				for (int i = p * p; i <= n; i += p) {
					is_prime[i] = false;
				}
			}
		}
		for (int p = 2; p <= n; ++p) {
			if (is_prime[p]) {
				primes.push_back(p);
			}
		}
		return primes;
	}
}