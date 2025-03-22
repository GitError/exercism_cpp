#include "election.h"

namespace election {
	int vote_count(const ElectionResult& candidate) {
		return candidate.votes;
	}

	void increment_vote_count(ElectionResult& candidate, int votes) {
		candidate.votes += votes;
	}

	ElectionResult& determine_result(std::vector<ElectionResult>& final_count) {
		size_t winner{};
		for (int i = 0; i < final_count.size(); ++i) {
			if (final_count.at(i).votes > final_count[winner].votes) {
				winner = i;
			}
		}
		final_count[winner].name = "President " + final_count[winner].name;
		return final_count.at(winner);
	}
}