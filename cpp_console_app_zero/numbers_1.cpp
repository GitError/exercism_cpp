#include "numbers_1.h"
#include <cmath>

namespace numbers_1 {
	double daily_rate(double hourly_rate) {
		return hourly_rate * 8;
	}

	double apply_discount(double before_discount, double discount) {
		return before_discount * (1 - discount / 100);
	}

	int monthly_rate(double hourly_rate, double discount) {
		return std::ceil(apply_discount(daily_rate(hourly_rate) * 22, discount));
	}

	int days_in_budget(int budget, double hourly_rate, double discount) {
		return budget / apply_discount(daily_rate(hourly_rate), discount);
	}
}