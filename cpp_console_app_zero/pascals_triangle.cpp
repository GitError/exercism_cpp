#include "pascals_triangle.h"

namespace pascals_triangle {
	std::vector<std::vector<int>> generate_rows(int N) {
		std::vector<std::vector<int>> triangle(N);
		for (int i = 0; i < N; ++i) {
			triangle[i].resize(i + 1, 1);
			for (int j = 1; j < i; ++j) {
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
			}
		}
		return triangle;
	}
}