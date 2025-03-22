#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace anagram {
	class anagram {
	private:
		std::string word;
		std::string normalized_word;

		// Helper function to convert a string to lowercase
		std::string to_lower(const std::string& s) const {
			std::string result = s;
			std::transform(result.begin(), result.end(), result.begin(),
				[](unsigned char c) { return std::tolower(c); });
			return result;
		}

		// Helper function to sort a string (for anagram comparison)
		std::string sort_string(const std::string& s) const {
			std::string result = s;
			std::sort(result.begin(), result.end());
			return result;
		}

	public:
		anagram(const std::string& word)
			: word(word), normalized_word(sort_string(to_lower(word))) {
		}

		// Overload for initializer list to handle {"hello", "world", ...} directly
		std::vector<std::string> matches(std::initializer_list<std::string> candidates) const {
			std::vector<std::string> result;
			for (const auto& candidate : candidates) {
				// Skip if the candidate is the same word (case-insensitive)
				if (to_lower(candidate) == to_lower(word)) {
					continue;
				}
				// Check if the sorted lowercase versions are the same
				if (sort_string(to_lower(candidate)) == normalized_word) {
					result.push_back(candidate);
				}
			}
			return result;
		}

		// Template version for other container types
		template <typename Container>
		Container matches(const Container& candidates) const {
			Container result;
			for (const auto& candidate : candidates) {
				// Skip if the candidate is the same word (case-insensitive)
				if (to_lower(candidate) == to_lower(word)) {
					continue;
				}
				// Check if the sorted lowercase versions are the same
				if (sort_string(to_lower(candidate)) == normalized_word) {
					result.insert(result.end(), candidate);
				}
			}
			return result;
		}
	};
}