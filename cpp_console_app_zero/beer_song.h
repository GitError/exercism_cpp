#pragma once

#include <string>

namespace beer_song {
	std::string verse(int bottle_count);

	std::string sing(int start, int end = 0);
}