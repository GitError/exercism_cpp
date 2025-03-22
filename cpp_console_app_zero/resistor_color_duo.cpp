#include "resistor_color_duo.h"
#include <unordered_map>

namespace resistor_color_duo {
	int value(const std::vector<std::string>& colors) {
		static const std::unordered_map<std::string, int> color_map = {
			{"black", 0},
			{"brown", 1},
			{"red", 2},
			{"orange", 3},
			{"yellow", 4},
			{"green", 5},
			{"blue", 6},
			{"violet", 7},
			{"grey", 8},
			{"white", 9}
		};
		int result = 0;
		if (!colors.empty()) {
			result = color_map.at(colors[0]) * 10;
		}
		if (colors.size() >= 2) {
			result += color_map.at(colors[1]);
		}
		return result;
	}
}