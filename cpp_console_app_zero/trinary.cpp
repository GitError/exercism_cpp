#include "trinary.h"

namespace trinary {
	int to_decimal(const std::string& trinary) {
		int decimal = 0;
		for (char c : trinary) {
			if (c < '0' || c > '2') return 0;
			decimal = decimal * 3 + (c - '0');
		}
		return decimal;
	}
}