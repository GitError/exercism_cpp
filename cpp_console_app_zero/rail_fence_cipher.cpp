#include "rail_fence_cipher.h"
#include <vector>

namespace rail_fence_cipher {
	std::string encode(const std::string& plaintext, int num_rails) {
		std::vector<std::string> rails(num_rails);
		int rail = 0;
		bool down = true;
		for (char c : plaintext) {
			rails[rail] += c;
			if (down) {
				rail++;
			}
			else {
				rail--;
			}
			if (rail == num_rails - 1) {
				down = false;
			}
			if (rail == 0) {
				down = true;
			}
		}
		std::string ciphertext;
		for (const std::string& rail : rails) {
			ciphertext += rail;
		}
		return ciphertext;
	}

	std::string decode(const std::string& ciphertext, int num_rails) {
		std::vector<std::string> rails(num_rails);
		int rail = 0;
		bool down = true;
		for (size_t i = 0; i < ciphertext.size(); ++i) {
			rails[rail] += ' ';
			if (down) {
				rail++;
			}
			else {
				rail--;
			}
			if (rail == num_rails - 1) {
				down = false;
			}
			if (rail == 0) {
				down = true;
			}
		}
		int index = 0;
		for (std::string& rail : rails) {
			for (char& c : rail) {
				c = ciphertext[index++];
			}
		}
		std::string plaintext;
		rail = 0;
		down = true;
		for (size_t i = 0; i < ciphertext.size(); ++i) {
			plaintext += rails[rail][0];
			rails[rail].erase(0, 1);
			if (down) {
				rail++;
			}
			else {
				rail--;
			}
			if (rail == num_rails - 1) {
				down = false;
			}
			if (rail == 0) {
				down = true;
			}
		}
		return plaintext;
	}
}