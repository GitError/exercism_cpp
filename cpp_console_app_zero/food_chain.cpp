#include "food_chain.h"
#include <vector>

namespace food_chain {
	const std::vector<std::string> animals = {
		"", "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
	};

	const std::vector<std::string> reactions = {
		"",
		"I don't know why she swallowed the fly. Perhaps she'll die.",
		"It wriggled and jiggled and tickled inside her.",
		"How absurd to swallow a bird!",
		"Imagine that, to swallow a cat!",
		"What a hog, to swallow a dog!",
		"Just opened her throat and swallowed a goat!",
		"I don't know how she swallowed a cow!",
		"She's dead, of course!"
	};

	std::string verse(int verse_number) {
		std::string result = "I know an old lady who swallowed a " + animals[verse_number] + ".\n";
		result += reactions[verse_number] + "\n";
		if (verse_number == 8 || verse_number == 1) {
			return result;
		}
		for (int i = verse_number; i > 1; i--) {
			if (i == 3) {
				result += "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
			}
			else {
				result += "She swallowed the " + animals[i] + " to catch the " + animals[i - 1] + ".\n";
			}
		}
		result += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
		return result;
	}

	std::string verses(int start_verse, int end_verse) {
		std::string result;
		for (int i = start_verse; i <= end_verse; i++) {
			result += verse(i);
			result += "\n";
		}
		return result;
	}

	std::string sing() {
		return verses(1, 8);
	}
}