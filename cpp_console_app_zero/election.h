#pragma once

#include <string>
#include <vector>

namespace election {
	struct ElectionResult {
		std::string name{};
		int votes{};
	};

	int vote_count(const ElectionResult& candidate);

	void increment_vote_count(ElectionResult& candidate, int votes);

	ElectionResult& determine_result(std::vector<ElectionResult>& final_count);
}