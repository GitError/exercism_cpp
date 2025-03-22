#include "binary.h"

namespace binary {
	int convert(std::string binary) {
		int decimal = 0;
		for (char c : binary) {
			if (c != '0' && c != '1') {
				return 0;
			}
			decimal = decimal * 2 + (c - '0');
		}
		return decimal;
	}
}