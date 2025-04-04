#pragma once

#include <string>

namespace rail_fence_cipher {
	std::string encode(const std::string& plaintext, int num_rails);

	std::string decode(const std::string& ciphertext, int num_rails);
}