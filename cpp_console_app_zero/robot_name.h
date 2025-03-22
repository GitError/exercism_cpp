#pragma once

#include <string>
#include <unordered_set>
#include <random>

namespace robot_name {
	class robot {
	public:
		robot() {
			reset();
		}
		std::string name() const {
			return robot_name_;
		}
		void reset() {
			std::string new_name;
			do {
				new_name = generate_name();
			} while (used_names_.find(new_name) != used_names_.end());
			if (!robot_name_.empty()) {
				used_names_.erase(robot_name_);
			}
			robot_name_ = new_name;
			used_names_.insert(robot_name_);
		}
	private:
		std::string robot_name_;
		static std::unordered_set<std::string> used_names_;
		static std::string generate_name() {
			static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			static std::random_device rd;
			static std::mt19937 gen(rd());
			static std::uniform_int_distribution<> letter_dist(0, 25);
			static std::uniform_int_distribution<> digit_dist(0, 9);
			std::string name;
			name += letters[letter_dist(gen)];
			name += letters[letter_dist(gen)];
			name += std::to_string(digit_dist(gen));
			name += std::to_string(digit_dist(gen));
			name += std::to_string(digit_dist(gen));
			return name;
		}
	};
	bool validate_name(const std::string& name);
}