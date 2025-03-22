#include "darts.h"
#include <cmath>

namespace darts {
	int score(double x, double y) {
		double distance = std::sqrt(x * x + y * y);
		return (distance > 10.0) ? 0 : (distance > 5.0) ? 1 : (distance > 1.0) ? 5 : 10;
	}
}