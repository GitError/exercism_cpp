#pragma once
#include <string>

namespace crypto_square {
	class cipher {
	private:
		std::string normalized_text;
		int num_columns;
		int num_rows;
		std::string normalize(const std::string& input);
		void calculate_dimensions();

	public:
		cipher(const std::string& input);
		std::string normalized_plain_text() const;
		std::string normalized_cipher_text() const;
	};
}