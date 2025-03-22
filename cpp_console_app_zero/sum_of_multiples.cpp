#include "sum_of_multiples.h"
#include <unordered_set>
#include <numeric>

namespace sum_of_multiples {
	int to(const std::vector<int>& bases, int level) {
		std::unordered_set<int> multiples;
		for (int base : bases) {
			if (base == 0) continue;
			for (int multiple = base; multiple < level; multiple += base) {
				multiples.insert(multiple);
			}
		}
		return std::accumulate(multiples.begin(), multiples.end(), 0);
	}
}