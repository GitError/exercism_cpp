#pragma once

#include <vector>

namespace list_ops {

	// Append: Add all items from the second list to the end of the first list
	template <typename T>
	void append(std::vector<T>& list1, const std::vector<T>& list2) {
		for (const auto& item : list2) {
			list1.push_back(item);
		}
	}

	// Concat: Combine all items from a series of lists into one flattened list
	template <typename T>
	std::vector<T> concat(const std::vector<std::vector<T>>& lists) {
		std::vector<T> result;
		for (const auto& list : lists) {
			for (const auto& item : list) {
				result.push_back(item);
			}
		}
		return result;
	}

	// Filter: Return a list of items for which predicate(item) is true
	template <typename T, typename Pred>
	std::vector<T> filter(const std::vector<T>& list, Pred predicate) {
		std::vector<T> result;
		for (const auto& item : list) {
			if (predicate(item)) {
				result.push_back(item);
			}
		}
		return result;
	}

	// Length: Return the total number of items in the list
	template <typename T>
	size_t length(const std::vector<T>& list) {
		size_t count = 0;
		for (auto it = list.begin(); it != list.end(); ++it) {
			count++;
		}
		return count;
	}

	// Map: Apply a function to each item in the list and return the results
	template <typename T, typename Func>
	std::vector<T> map(const std::vector<T>& list, Func function) {
		std::vector<T> result;
		for (const auto& item : list) {
			result.push_back(function(item));
		}
		return result;
	}

	// Foldl: Fold each item into the accumulator from the left
	template <typename T, typename Acc, typename Func>
	Acc foldl(const std::vector<T>& list, Acc initial, Func function) {
		Acc accumulator = initial;
		for (const auto& item : list) {
			accumulator = function(accumulator, item);
		}
		return accumulator;
	}

	// Foldr: Fold each item into the accumulator from the right
	template <typename T, typename Acc, typename Func>
	Acc foldr(const std::vector<T>& list, Acc initial, Func function) {
		Acc accumulator = initial;
		for (auto it = list.rbegin(); it != list.rend(); ++it) {
			accumulator = function(accumulator, *it);
		}
		return accumulator;
	}

	// Reverse: Return a list with all items in reversed order
	template <typename T>
	std::vector<T> reverse(const std::vector<T>& list) {
		std::vector<T> result;
		for (auto it = list.rbegin(); it != list.rend(); ++it) {
			result.push_back(*it);
		}
		return result;
	}
}