#include "leap.h"

namespace leap {
	static bool is_leap_year(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
}