#include "rotational_cipher.h"

namespace rotational_cipher {
	std::string rotate(std::string input, int shift) {
		std::string rotated;
		for (char c : input) {
			if (isalpha(c)) {
				char base = islower(c) ? 'a' : 'A';
				rotated += base + (c - base + shift) % 26;
			}
			else {
				rotated += c;
			}
		}
		return rotated;
	}
}