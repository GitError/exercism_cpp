#include "lasagna_master.h"

namespace lasagna_master {
	int preparationTime(std::vector<std::string> layers, int minutes_per_layer) {
		return layers.size() * minutes_per_layer;
	}

	amount quantities(std::vector<std::string> layers) {
		amount needed{ 0, 0.0 };
		for (const std::string& layer : layers) {
			if (layer == "noodles") {
				needed.noodles += 50;
			}
			else if (layer == "sauce") {
				needed.sauce += 0.2;
			}
		}
		return needed;
	}

	void addSecretIngredient(std::vector<std::string>& my_layers, std::vector<std::string> friend_layers)
	{
		if (!friend_layers.empty())
			my_layers.back() = friend_layers.back();
	}

	void addSecretIngredient(std::vector<std::string>& my_layers, std::string secret_ingredient)
	{
		my_layers.back() = secret_ingredient;
	}

	std::vector<double> scaleRecipe(std::vector<double> quantities_for_two, int portions)
	{
		std::vector<double> scaled;
		for (double quantity : quantities_for_two) {
			scaled.push_back(quantity * portions / 2);
		}
		return scaled;
	}
}