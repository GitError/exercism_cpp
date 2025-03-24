#include "word_count.h"
#include <algorithm>
#include <sstream>

namespace word_count {

    std::map<std::string, int> words(const std::string& input) {
        std::map<std::string, int> word_map;
        std::string processed_input = input;

        // Convert to lowercase
        std::transform(processed_input.begin(), processed_input.end(),
            processed_input.begin(), ::tolower);

        // Process the string character by character
        std::string result;
        bool in_word = false;

        for (size_t i = 0; i < processed_input.length(); ++i) {
            char c = processed_input[i];

            // Handle apostrophes
            if (c == '\'') {
                // Apostrophe in middle of word - keep it
                if (in_word && i > 0 && i < processed_input.length() - 1 &&
                    isalnum(processed_input[i - 1]) && isalnum(processed_input[i + 1])) {
                    result += c;
                }
                else {
                    // Not a contraction apostrophe - replace with space
                    result += ' ';
                }
            }
            // Keep alphanumeric characters
            else if (isalnum(c)) {
                result += c;
                in_word = true;
            }
            // Replace any other character with space
            else {
                result += ' ';
                in_word = false;
            }
        }

        // Create a string stream to split by whitespace
        std::istringstream ss(result);
        std::string word;

        while (ss >> word) {
            // Skip if the word is empty after processing
            if (word.empty()) {
                continue;
            }

            // Count the word
            word_map[word]++;
        }

        return word_map;
    }
}