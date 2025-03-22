#include "pangram.h"
#include <unordered_set>

namespace pangram {
    bool is_pangram(const std::string sentence) {
        std::unordered_set<char> letters;
        for (char c : sentence) {
            if (isalpha(c)) {
                letters.insert(tolower(c));
            }
        }
        return letters.size() == 26;
    }
}