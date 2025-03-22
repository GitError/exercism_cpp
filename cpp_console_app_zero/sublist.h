#pragma once
#include <vector>

namespace sublist {
	enum class comparison { equal, unequal, sublist, superlist };

	comparison check_lists(std::vector<int> list1, std::vector<int> list2);
}