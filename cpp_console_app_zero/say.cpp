#include "say.h"
#include <stdexcept>

namespace say {
	std::string convert_hundreds(long long number) {
		std::string result;
		if (number >= 100) {
			result += below_20[number / 100] + " hundred";
			number %= 100;
			if (number > 0) {
				result += " ";
			}
		}
		if (number >= 20) {
			result += tens[number / 10];
			number %= 10;
			if (number > 0) {
				result += "-" + below_20[number];
			}
		}
		else if (number > 0) {
			result += below_20[number];
		}
		return result;
	}

	std::string in_english(long long number) {
		if (number < 0 || number >= 1'000'000'000'000) {
			throw std::domain_error("Number out of range");
		}
		if (number == 0) {
			return "zero";
		}
		std::string result;
		int chunk_count = 0;
		while (number > 0) {
			long long chunk = number % 1000;
			if (chunk > 0) {
				std::string chunk_str = convert_hundreds(chunk);
				if (!result.empty()) {
					result = chunk_str + " " + thousands[chunk_count] + " " + result;
				}
				else {
					result = chunk_str + " " + thousands[chunk_count];
				}
			}
			number /= 1000;
			chunk_count++;
		}
		result.erase(result.find_last_not_of(" ") + 1);
		return result;
	}
}