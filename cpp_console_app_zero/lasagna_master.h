#pragma once
#include <vector>
#include <string>

namespace lasagna_master {
	struct amount { int noodles; double sauce; };

	int preparationTime(std::vector<std::string> layers, int minutes_per_layer = 2);

	amount quantities(std::vector<std::string> layers);

	void addSecretIngredient(std::vector<std::string>& my_layers, std::vector<std::string> friend_layers);

	void addSecretIngredient(std::vector<std::string>& my_layers, std::string secret_ingredient);

	std::vector<double> scaleRecipe(std::vector<double> quantities_for_two_portions, int portions);
}