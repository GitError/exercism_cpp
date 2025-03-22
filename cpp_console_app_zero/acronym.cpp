#include "acronym.h"
#include <cctype>

namespace acronym {
	std::string acronym(std::string phrase) {
		std::string acronym;
		bool new_word = true;
		for (char c : phrase) {
			if (new_word && isalpha(c)) {
				acronym += toupper(c);
				new_word = false;
			}
			else if (isspace(c) || c == '-') {
				new_word = true;
			}
		}
		return acronym;
	}
}