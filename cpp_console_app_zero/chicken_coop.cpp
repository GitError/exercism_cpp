#include "chicken_coop.h"

namespace chicken_coop {
	int positions_to_quantity(int number) {
		int count = 0;
		while (number > 0) {
			if (number & 1) {
				count++;
			}
			number >>= 1;
		}
		return count;
	}
}