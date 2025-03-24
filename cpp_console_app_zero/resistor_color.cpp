#include "resistor_color.h"
#include <algorithm>
#include <stdexcept>

namespace resistor_color {
	std::vector<std::string> COLORS = {
		"black", "brown", "red", "orange", "yellow",
		"green", "blue", "violet", "grey", "white"
	};

	int color_code(std::string color) {
		auto it = std::find(COLORS.begin(), COLORS.end(), color);
		if (it == COLORS.end()) {
			throw std::invalid_argument("Invalid color: " + color);
		}
		return std::distance(COLORS.begin(), it);
	}

	std::vector<std::string> colors() {
		return COLORS;
	}
}