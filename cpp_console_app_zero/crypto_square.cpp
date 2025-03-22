#include "crypto_square.h"
#include <cmath>
#include <cctype>

namespace crypto_square {
	cipher::cipher(const std::string& input) {
		normalized_text = normalize(input);
		calculate_dimensions();
	}

	std::string cipher::normalize(const std::string& input) {
		std::string result;
		// Keep only alphanumeric characters and convert to lowercase
		for (char c : input) {
			if (std::isalnum(c)) {
				result += std::tolower(c);
			}
		}
		return result;
	}

	void cipher::calculate_dimensions() {
		size_t length = normalized_text.length();
		// Default dimensions for empty string
		if (length == 0) {
			num_columns = 0;
			num_rows = 0;
			return;
		}
		// Calculate the number of columns:
		// We want the smallest c such that:
		// 1. r * c >= length
		// 2. c >= r
		// 3. c - r <= 1
		// Start with the square root (perfect square)
		num_columns = static_cast<int>(std::ceil(std::sqrt(static_cast<double>(length))));
		// Calculate rows based on columns
		num_rows = static_cast<int>(std::ceil(static_cast<double>(length) / num_columns));
		// Ensure c >= r
		if (num_columns < num_rows) {
			std::swap(num_columns, num_rows);
		}
		// Ensure c - r <= 1
		if (num_columns - num_rows > 1) {
			num_columns = num_rows + 1;
		}
	}

	std::string cipher::normalized_plain_text() const {
		return normalized_text;
	}

	std::string cipher::normalized_cipher_text() const {
		if (normalized_text.empty()) {
			return "";
		}
		std::string result;
		size_t text_length = normalized_text.length();
		// Read down the columns going left to right
		for (int col = 0; col < num_columns; col++) {
			for (int row = 0; row < num_rows; row++) {
				size_t index = static_cast<size_t>(row * num_columns + col);

				if (index < text_length) {
					result += normalized_text[index];
				}
				else {
					// Pad with space if we're short of the perfect rectangle
					result += ' ';
				}
			}
			// Add a space between chunks, but not after the last chunk
			if (col < num_columns - 1) {
				result += ' ';
			}
		}
		return result;
	}
}