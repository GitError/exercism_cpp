#include "binary_search.h"
#include <stdexcept>

namespace binary_search {
	std::size_t find(const std::vector<int>& data, int target) {
		if (data.empty()) {
			throw std::domain_error("Value not in array");
		}
		std::size_t left = 0;
		std::size_t right = data.size() - 1;
		while (left <= right) {
			// Calculate middle index (using this formula to prevent overflow)
			std::size_t middle = left + (right - left) / 2;
			// Found the target
			if (data[middle] == target) {
				return middle;
			}
			// If target is greater, ignore left half
			if (data[middle] < target) {
				left = middle + 1;
			}
			// If target is smaller, ignore right half
			else {
				// Check for underflow (only an issue when middle is 0)
				if (middle == 0) {
					break;
				}
				right = middle - 1;
			}
		}
		// Target not found
		throw std::domain_error("Value not in array");
	}
}