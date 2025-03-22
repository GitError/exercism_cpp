#pragma once
#include <string>

namespace atbash_cipher {
	char atbash(char c);

	std::string transform(const std::string& input);

	std::string encode(const std::string& input);

	std::string decode(const std::string& input);
}