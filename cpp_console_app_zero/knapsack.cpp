#include "knapsack.h"
#include <algorithm>

namespace knapsack {
	int maximum_value(int max_weight, const std::vector<Item>& items) {
		// Handle edge case: no items or zero max weight
		if (items.empty() || max_weight <= 0) {
			return 0;
		}

		// Create a dynamic programming table
		// dp[i][w] represents the maximum value when considering
		// the first i items with a maximum weight w
		std::vector<std::vector<int>> dp(items.size() + 1,
			std::vector<int>(max_weight + 1, 0));

		// Fill the dynamic programming table
		for (size_t i = 1; i <= items.size(); ++i) {
			for (int w = 0; w <= max_weight; ++w) {
				// If the current item is too heavy, skip it
				if (items[i - 1].weight > w) {
					dp[i][w] = dp[i - 1][w];
				}
				else {
					// Choose the maximum of:
					// 1. Not taking the current item
					// 2. Taking the current item + optimal value of remaining weight
					dp[i][w] = std::max(dp[i - 1][w],
						items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
				}
			}
		}

		// Return the maximum value that can be obtained
		return dp[items.size()][max_weight];
	}
}