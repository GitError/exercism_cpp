#include "minesweeper.h"

namespace minesweeper {
	std::vector<std::string> annotate(const std::vector<std::string>& minefield) {

		// Handle empty input
		if (minefield.empty()) {
			return {};
		}

		const int height = minefield.size();
		const int width = minefield[0].size();

		// Create a copy of the input to modify
		std::vector<std::string> result = minefield;

		// Process each cell
		for (int row = 0; row < height; ++row) {
			for (int col = 0; col < width; ++col) {
				// Skip cells that already have a mine
				if (minefield[row][col] == '*') {
					continue;
				}

				// Count adjacent mines
				int count = 0;

				// Check all 8 adjacent cells
				for (int dr = -1; dr <= 1; ++dr) {
					for (int dc = -1; dc <= 1; ++dc) {
						// Skip the cell itself
						if (dr == 0 && dc == 0) {
							continue;
						}

						int new_row = row + dr;
						int new_col = col + dc;

						// Check bounds
						if (new_row >= 0 && new_row < height && new_col >= 0 && new_col < width) {
							// Count if there's a mine
							if (minefield[new_row][new_col] == '*') {
								count++;
							}
						}
					}
				}
				// Update the cell with count (if there are mines adjacent)
				if (count > 0) {
					result[row][col] = '0' + count; // Convert int to character
				}
			}
		}
		return result;
	}
}