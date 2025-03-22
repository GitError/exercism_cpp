#include "spiral_matrix.h"

namespace spiral_matrix {
	std::vector<std::vector<uint32_t>> spiral_matrix(int size) {
		if (size == 0) return {};
		std::vector<std::vector<uint32_t>> matrix(size, std::vector<uint32_t>(size));
		int value = 1;
		int top = 0, bottom = size - 1;
		int left = 0, right = size - 1;
		while (top <= bottom && left <= right) {
			for (int i = left; i <= right; ++i) {
				matrix[top][i] = value++;
			}
			++top;

			for (int i = top; i <= bottom; ++i) {
				matrix[i][right] = value++;
			}
			--right;

			if (top <= bottom) {
				for (int i = right; i >= left; --i) {
					matrix[bottom][i] = value++;
				}
				--bottom;
			}

			if (left <= right) {
				for (int i = bottom; i >= top; --i) {
					matrix[i][left] = value++;
				}
				++left;
			}
		}
		return matrix;
	}
}