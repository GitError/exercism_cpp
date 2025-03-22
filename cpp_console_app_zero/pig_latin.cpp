#include "pig_latin.h"
#include <sstream>
#include <vector>

namespace pig_latin {
	std::string translate(const std::string phrase) {
		const std::string vowels = "aeiou";
		std::vector<std::string> result;
		std::istringstream iss(phrase);
		std::string word;

		while (iss >> word) {
			// Rule 1: Starts with a vowel or "xr"/"yt"
			if (vowels.find(word[0]) != std::string::npos ||
				(word.size() >= 2 && (word.substr(0, 2) == "xr" || word.substr(0, 2) == "yt"))) {
				result.push_back(word + "ay");
			}

			// Rule 3: Starts with consonants followed by "qu"
			else if ((word.size() >= 2 && word.substr(0, 2) == "qu") ||
				(word.size() >= 3 && word.substr(1, 2) == "qu")) {
				size_t qu_index = word.find("qu") + 2;
				result.push_back(word.substr(qu_index) + word.substr(0, qu_index) + "ay");
			}

			// Rule 4: Starts with consonants followed by "y"
			else if (word.find('y') != std::string::npos && word.find('y') > 0) {
				size_t y_index = word.find('y');
				bool all_consonants = true;

				for (size_t i = 0; i < y_index; i++) {
					if (vowels.find(word[i]) != std::string::npos) {
						all_consonants = false;
						break;
					}
				}
				if (all_consonants) {
					result.push_back(word.substr(y_index) + word.substr(0, y_index) + "ay");
				}
				else {
					for (size_t i = 0; i < word.size(); i++) {
						if (vowels.find(word[i]) != std::string::npos) {
							result.push_back(word.substr(i) + word.substr(0, i) + "ay");
							break;
						}
					}
				}
			}
			// Rule 2: Starts with one or more consonants
			else {
				for (size_t i = 0; i < word.size(); i++) {
					if (vowels.find(word[i]) != std::string::npos) {
						result.push_back(word.substr(i) + word.substr(0, i) + "ay");
						break;
					}
				}
			}
		}

		// Join the results
		std::string translated;
		for (size_t i = 0; i < result.size(); i++) {
			if (i > 0) translated += " ";
			translated += result[i];
		}

		return translated;
	}
}