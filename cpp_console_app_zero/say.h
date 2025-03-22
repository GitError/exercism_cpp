#pragma once

#include <vector>
#include <string>

namespace say {
	const std::vector<std::string> below_20 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

	const std::vector<std::string> tens = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

	const std::vector<std::string> thousands = {"", "thousand", "million", "billion" };

	std::string convert_hundreds(long long number);

	std::string in_english(long long number);
}