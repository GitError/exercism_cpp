#pragma once

#include <string>
#include <unordered_set>
#include <unordered_map>

namespace allergies {
    class allergy_test {
    private:
        unsigned int score;
        const std::unordered_map<int, std::string> allergenMap = {
            {1, "eggs"}, {2, "peanuts"}, {4, "shellfish"}, {8, "strawberries"},
            {16, "tomatoes"}, {32, "chocolate"}, {64, "pollen"}, {128, "cats"}
        };

    public:
        explicit allergy_test(unsigned int allergy_score) : score(allergy_score) {}
        bool is_allergic_to(const std::string& allergen) const {
            for (const auto& [value, name] : allergenMap) {
                if ((score & value) && name == allergen) {
                    return true;
                }
            }
            return false;
        }
        std::unordered_set<std::string> get_allergies() const {
            std::unordered_set<std::string> allergies;
            for (const auto& [value, name] : allergenMap) {
                if (score & value) {
                    allergies.emplace(name);
                }
            }
            return allergies;
        }
    };
}