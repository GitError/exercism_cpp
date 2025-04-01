#include "parallel_letter_frequency.h"
#include <execution>
#include <algorithm>
#include <mutex>
#include <cctype>

namespace parallel_letter_frequency {
    std::unordered_map<char, int> frequency(const std::vector<std::string_view>& texts) {
        // Early return for empty input
        if (texts.empty()) {
            return {};
        }

        // Create a mutex for thread-safe updates to the frequencies map
        std::mutex map_mutex;

        // Result map for letter frequencies
        std::unordered_map<char, int> frequencies;

        // Process each text in parallel

        /* windows implementation -- requirec C++17, gcc 9.0 or higher
        std::for_each(std::execution::par, texts.begin(), texts.end(), [&](const std::string_view& text) {
                // Create a local map for this text's frequencies
                std::unordered_map<char, int> local_frequencies;

                // Process each character in the text
                for (char c : text) {
                    // Convert to lowercase and check if it's a letter
                    if (std::isalpha(c)) {
                        char lower_c = std::tolower(c);
                        local_frequencies[lower_c]++;
                    }
                }

                // Merge local results into the global map
                if (!local_frequencies.empty()) {
                    std::lock_guard<std::mutex> lock(map_mutex);
                    for (const auto& [letter, count] : local_frequencies) {
                        frequencies[letter] += count;
                    }
                }
            }
        );
        */

        return frequencies;
    }
}