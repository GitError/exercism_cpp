#include "yacht.h"
#include <algorithm>
#include <numeric>
#include <map>

namespace yacht {
	int score(const std::vector<int>& dice, const std::string& category) {
		// Count occurrences of each dice value
		std::map<int, int> counts;
		for (int die : dice) {
			counts[die]++;
		}

		// Number categories (ones through sixes)
		if (category == "ones") return counts[1] * 1;
		if (category == "twos") return counts[2] * 2;
		if (category == "threes") return counts[3] * 3;
		if (category == "fours") return counts[4] * 4;
		if (category == "fives") return counts[5] * 5;
		if (category == "sixes") return counts[6] * 6;

		// Full house: Three of one number and two of another
		if (category == "full house") {
			bool has_three = false;
			bool has_two = false;

			for (const auto& pair : counts) {
				if (pair.second == 3) has_three = true;
				if (pair.second == 2) has_two = true;
			}

			if (has_three && has_two) {
				return std::accumulate(dice.begin(), dice.end(), 0);
			}
			return 0;
		}

		// Four of a kind: At least four dice showing the same face
		if (category == "four of a kind") {
			for (const auto& pair : counts) {
				if (pair.second >= 4) {
					return pair.first * 4;
				}
			}
			return 0;
		}

		// Little straight: 1-2-3-4-5
		if (category == "little straight") {
			std::vector<int> sorted_dice = dice;
			std::sort(sorted_dice.begin(), sorted_dice.end());
			if (sorted_dice == std::vector<int>{1, 2, 3, 4, 5}) {
				return 30;
			}
			return 0;
		}

		// Big straight: 2-3-4-5-6
		if (category == "big straight") {
			std::vector<int> sorted_dice = dice;
			std::sort(sorted_dice.begin(), sorted_dice.end());
			if (sorted_dice == std::vector<int>{2, 3, 4, 5, 6}) {
				return 30;
			}
			return 0;
		}

		// Choice: Sum of the dice
		if (category == "choice") {
			return std::accumulate(dice.begin(), dice.end(), 0);
		}

		// Yacht: All five dice showing the same face
		if (category == "yacht") {
			for (const auto& pair : counts) {
				if (pair.second == 5) {
					return 50;
				}
			}
			return 0;
		}

		// Default case (shouldn't happen with valid categories)
		return 0;
	}
}