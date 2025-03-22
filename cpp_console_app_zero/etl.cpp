#include "etl.h"
#include <cctype>

namespace etl {
	namespace etl {
		std::map<char, int> transform(const std::map<int, std::vector<char>>& old) {
			std::map<char, int> new_format;
			for (const auto& pair : old) {
				int points = pair.first;
				const std::vector<char>& letters = pair.second;
				for (char letter : letters) {
					new_format[std::tolower(letter)] = points;
				}
			}
			return new_format;
		}
	}
}
