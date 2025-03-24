#include "bob.h"
#include <algorithm>

namespace bob {
	std::string hey(std::string phrase) {
		phrase.erase(std::remove_if(phrase.begin(), phrase.end(), isspace), phrase.end());
		if (phrase.empty()) {
			return "Fine. Be that way!";
		}
		bool is_question = phrase.back() == '?';
		bool has_letters = std::any_of(phrase.begin(), phrase.end(), ::isalpha);
		bool is_yelling = has_letters && std::all_of(phrase.begin(), phrase.end(), [](char c) { return !isalpha(c) || isupper(c); });
		if (is_question && is_yelling) {
			return "Calm down, I know what I'm doing!";
		}
		if (is_question) {
			return "Sure.";
		}
		if (is_yelling) {
			return "Whoa, chill out!";
		}
		return "Whatever.";
	}
}