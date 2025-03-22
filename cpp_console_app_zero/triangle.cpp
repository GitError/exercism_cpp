#include "triangle.h"
#include <stdexcept>

namespace triangle {
	flavor kind(double a, double b, double c) {
		if (a <= 0 || b <= 0 || c <= 0)
			throw std::domain_error("all sides need to be greater than zero");
		if (a + b <= c || b + c <= a || a + c <= b)
			throw std::domain_error("the sum of 2 sides should be greater than the third side");
		if (a == b && b == c)
			return flavor::equilateral;
		if (a == b || b == c || a == c)
			return flavor::isosceles;
		return flavor::scalene;
	}
}