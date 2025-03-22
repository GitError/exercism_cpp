#pragma once

#include <vector>
#include <string>

namespace marking_grades {
	std::vector<int> round_down_scores(std::vector<double> student_scores);

	int count_failed_students(std::vector<int> student_scores);

	std::vector<int> above_threshold(std::vector<int> student_scores, int threshold);

	std::array<int, 4> letter_grades(int highest_score);

	std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names);

	std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names);
}