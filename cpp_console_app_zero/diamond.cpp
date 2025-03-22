#include "diamond.h"

namespace diamond {
	std::vector<std::string> rows(char letter) {
		// Calculate dimensions
		int letter_pos = letter - 'A';
		int width = 2 * letter_pos + 1;
		std::vector<std::string> result;
		// Generate top half (including middle row)
		for (int i = 0; i <= letter_pos; ++i) {
			std::string row(width, ' ');
			char current_letter = 'A' + i;
			// Place letters in the row
			if (i == 0) {
				// Special case for 'A'
				row[letter_pos] = 'A';
			}
			else {
				// Two letters with spaces between
				row[letter_pos - i] = current_letter;
				row[letter_pos + i] = current_letter;
			}
			result.push_back(row);
		}
		// Generate bottom half (excluding middle row)
		for (int i = letter_pos - 1; i >= 0; --i) {
			result.push_back(result[i]);
		}
		return result;
	}
}