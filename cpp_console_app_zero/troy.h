#pragma once

#include <string>
#include <memory>

namespace troy {
	struct artifact {
		artifact(std::string name) : name(name) {}
		std::string name;
	};

	struct power {
		power(std::string effect) : effect(effect) {}
		std::string effect;
	};

	struct human {
		human() : possession{ nullptr }, own_power{ nullptr }, influenced_by{ nullptr } {}
		std::unique_ptr<artifact> possession;
		std::shared_ptr<power>    own_power;
		std::shared_ptr<power>    influenced_by;
	};

	void give_new_artifact(human&, const std::string&);

	void exchange_artifacts(std::unique_ptr<artifact>&, std::unique_ptr<artifact>&);

	void manifest_power(human&, const std::string&);

	void use_power(human&, human&);

	long power_intensity(const human& h);
}