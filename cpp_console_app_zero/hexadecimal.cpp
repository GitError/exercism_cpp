#include "hexadecimal.h"

namespace hexadecimal {
	int hex_char_to_decimal(char hex_char) {
		if (hex_char >= '0' && hex_char <= '9') return hex_char - '0';
		if (hex_char >= 'a' && hex_char <= 'f') return 10 + (hex_char - 'a');
		if (hex_char >= 'A' && hex_char <= 'F') return 10 + (hex_char - 'A');
		return -1;
	}

	long long convert(const std::string& hex_string) {
		long long decimal_value = 0;
		for (char hex_char : hex_string) {
			int digit_value = hex_char_to_decimal(hex_char);
			if (digit_value == -1) return 0;
			decimal_value = decimal_value * 16 + digit_value;
		}
		return decimal_value;
	}
}