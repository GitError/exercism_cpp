#include "sublist.h"
#include <algorithm>

namespace sublist {

	bool is_sublist(const std::vector<int>& potential_sublist, const std::vector<int>& potential_superlist) {
		// Empty list is a sublist of any list
		if (potential_sublist.empty()) {
			return true;
		}

		// If potential_sublist is longer than potential_superlist, it can't be a sublist
		if (potential_sublist.size() > potential_superlist.size()) {
			return false;
		}

		// Check each possible starting position in the potential superlist
		for (size_t i = 0; i <= potential_superlist.size() - potential_sublist.size(); ++i) {
			// Check if there's a match starting at position i
			bool match = true;
			for (size_t j = 0; j < potential_sublist.size(); ++j) {
				if (potential_superlist[i + j] != potential_sublist[j]) {
					match = false;
					break;
				}
			}

			if (match) {
				return true;
			}
		}

		return false;
	}

	List_comparison sublist(const std::vector<int>& list_one, const std::vector<int>& list_two) {
		// Check for equality first
		if (list_one == list_two) {
			return List_comparison::equal;
		}

		// Check if list_one is a sublist of list_two
		if (is_sublist(list_one, list_two)) {
			return List_comparison::sublist;
		}

		// Check if list_two is a sublist of list_one
		if (is_sublist(list_two, list_one)) {
			return List_comparison::superlist;
		}

		// If none of the above, the lists are unequal
		return List_comparison::unequal;
	}

}