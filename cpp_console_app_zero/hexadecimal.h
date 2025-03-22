#pragma once
#include <string>

namespace hexadecimal {
	int hex_char_to_decimal(char hex_char);

	long long convert(const std::string& hex_string);
}