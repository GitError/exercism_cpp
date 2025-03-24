#include "run_length_encoding.h"

namespace run_length_encoding {
	std::string encode(const std::string& text) {
		if (text.empty()) {
			return "";
		}
		std::string result;
		char current_char = text[0];
		int count = 1;
		for (size_t i = 1; i < text.length(); ++i) {
			if (text[i] == current_char) {
				// Same character, increment count
				count++;
			}
			else {
				// Different character, append the run and reset
				if (count > 1) {
					result += std::to_string(count);
				}
				result += current_char;
				current_char = text[i];
				count = 1;
			}
		}
		// Don't forget the last run
		if (count > 1) {
			result += std::to_string(count);
		}
		result += current_char;
		return result;
	}

	std::string decode(const std::string& text) {
		if (text.empty()) {
			return "";
		}
		std::string result;
		std::string count_str;
		for (char c : text) {
			if (std::isdigit(c)) {
				// Collect digits for the count
				count_str += c;
			}
			else {
				// Non-digit character encountered
				int count = count_str.empty() ? 1 : std::stoi(count_str);
				result.append(count, c); // Append 'c' repeated 'count' times
				count_str.clear();
			}
		}
		return result;
	}
}