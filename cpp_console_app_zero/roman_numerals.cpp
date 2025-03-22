#include "roman_numerals.h"
#include <vector>
#include <utility>

namespace roman_numerals {

    std::string convert(int number) {
        // Define the mapping of values to Roman numerals
        // We include the special cases (4, 9, 40, 90, 400, 900) to handle subtraction notation
        const std::vector<std::pair<int, std::string>> roman_map = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        std::string result;

        // Iterate through the roman_map in descending order of values
        for (const auto& pair : roman_map) {
            int value = pair.first;
            const std::string& symbol = pair.second;

            // While the current number is greater than or equal to the current Roman numeral value
            while (number >= value) {
                // Add the Roman numeral to the result
                result += symbol;
                // Subtract the value from the number
                number -= value;
            }
        }
        return result;
    }
}