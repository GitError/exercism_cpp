#include "isogram.h"
#include <unordered_set>

namespace isogram {
	bool is_isogram(const std::string& word) {
		std::unordered_set<char> seen;
		for (char c : word) {
			if (isalpha(c) && !seen.insert(tolower(c)).second) {
				return false;
			}
		}
		return true;
	}
}