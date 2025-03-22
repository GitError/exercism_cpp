#include "sublist.h"
#include <algorithm>

namespace sublist {
	comparison check_lists(std::vector<int> list1, std::vector<int> list2) {
		if (list1 == list2) {
			return comparison::equal;
		}
		else if (std::includes(list1.begin(), list1.end(), list2.begin(), list2.end())) {
			return comparison::sublist;
		}
		else if (std::includes(list2.begin(), list2.end(), list1.begin(), list1.end())) {
			return comparison::superlist;
		}
		return comparison::unequal;
	}
}