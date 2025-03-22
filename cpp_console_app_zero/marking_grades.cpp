#include "marking_grades.h"
#include <array>

namespace marking_grades {
	std::vector<int> round_down_scores(std::vector<double> student_scores) {
		std::vector<int> rounded_scores;
		for (double score : student_scores) {
			rounded_scores.push_back(static_cast<int>(score));
		}
		return rounded_scores;
	}

	int count_failed_students(std::vector<int> student_scores) {
		int failed_students = 0;
		for (int score : student_scores) {
			if (score <= 40) {
				++failed_students;
			}
		}
		return failed_students;
	}

	std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
		std::vector<int> above_threshold;
		for (int score : student_scores) {
			if (score >= threshold) {
				above_threshold.push_back(score);
			}
		}
		return above_threshold;
	}

	std::array<int, 4> letter_grades(int highest_score) {
		int interval = (highest_score - 40) / 4;
		return { 41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval };
	}

	std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) {
		std::vector<std::string> rankings;
		for (size_t i = 0; i < student_scores.size(); ++i) {
			rankings.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
		}
		return rankings;
	}

	std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
		for (size_t i = 0; i < student_scores.size(); ++i) {
			if (student_scores[i] == 100) {
				return student_names[i];
			}
		}
		return "";
	}
}