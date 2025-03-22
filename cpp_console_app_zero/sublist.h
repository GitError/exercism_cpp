#include <vector>

namespace sublist {

    // Enum to represent the relationship between two lists
    enum class List_comparison {
        equal,
        sublist,
        superlist,
        unequal
    };

    /**
     * Determines the relationship between two lists.
     *
     * @param list_one The first list to compare
     * @param list_two The second list to compare
     * @return The relationship between the two lists (equal, sublist, superlist, or unequal)
     */
    List_comparison sublist(const std::vector<int>& list_one, const std::vector<int>& list_two);

    // Helper function to check if one list is a sublist of another
    bool is_sublist(const std::vector<int>& potential_sublist, const std::vector<int>& potential_superlist);

} // namespace sublist
