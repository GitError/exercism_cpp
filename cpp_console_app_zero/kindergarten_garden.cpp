#include "kindergarten_garden.h"
#include <vector>
#include <algorithm>
#include <unordered_map>

namespace kindergarten_garden {
	std::unordered_map<char, Plants> plant_map = {
		{'C', Plants::clover},
		{'G', Plants::grass},
		{'V', Plants::violets},
		{'R', Plants::radishes}
	};

	std::vector<std::string> students = {
		"Alice", "Bob", "Charlie", "David", "Eve", "Fred", "Ginny", 
		"Harriet", "Ileana", "Joseph", "Kincaid", "Larry"
	};

	std::array<Plants, 4> plants(const std::string garden, const std::string student) {
		std::array<Plants, 4> result;
		size_t student_index = std::distance(students.begin(), std::find(students.begin(), students.end(), student));
		size_t plant_index = student_index * 2;
		result[0] = plant_map[garden[plant_index]];
		result[1] = plant_map[garden[plant_index + 1]];
		result[2] = plant_map[garden[garden.find('\n') + 1 + plant_index]];
		result[3] = plant_map[garden[garden.find('\n') + 1 + plant_index + 1]];
		return result;
	}
}