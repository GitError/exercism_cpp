#include "arcade.h"
#include <algorithm>

namespace arcade {
	std::vector<int> HighScores::list_scores() {
		return scores;
	}

	int HighScores::latest_score() {
		return scores.back();
	}

	int HighScores::personal_best() {
		return *std::max_element(scores.begin(), scores.end());
	}

	std::vector<int> HighScores::top_three() {
		std::vector<int> top_scores = scores;
		std::sort(top_scores.begin(), top_scores.end(), std::greater<int>());
		if (top_scores.size() > 3) {
			top_scores.resize(3);
		}
		return top_scores;
	}
}
