#pragma once

#include <numeric>
#include <stdexcept>

namespace two_bucket {
	enum class bucket_id { one, two };

	struct measure_result {
		int num_moves;
		bucket_id goal_bucket;
		int other_bucket_volume;
	};

	struct State {
		int b1;
		int b2;
		int moves;

		State(int b1, int b2, int m) : b1(b1), b2(b2), moves(m) {}
	};

	struct StateHash {
		size_t operator()(const State& state) const {
			return std::hash<int>()(state.b1) ^ (std::hash<int>()(state.b2) << 1);
		}
	};

	measure_result measure(int bucket1_capacity, int bucket2_capacity, int target_volume, bucket_id start_bucket);
}