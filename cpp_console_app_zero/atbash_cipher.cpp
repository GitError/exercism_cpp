#include "atbash_cipher.h"

namespace atbash_cipher {
	char atbash(char c) {
		if (c >= 'a' && c <= 'z') return 'z' - c + 'a';
		if (c >= 'A' && c <= 'Z') return 'z' - tolower(c) + 'a';
		return c;
	}

	std::string transform(const std::string& input) {
		std::string answer;
		for (char c : input) {
			if (isalnum(c)) {
				answer += atbash(c);
			}
		}
		return answer;
	}

	std::string encode(const std::string& input) {
		std::string transformed = transform(input);
		std::string answer;
		for (size_t i = 0; i < transformed.size(); ++i) {
			if (i > 0 && i % 5 == 0) answer += ' ';
			answer += transformed[i];
		}
		return answer;
	}

	std::string decode(const std::string& input) {
		return transform(input);
	}
}