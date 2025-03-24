#include "troy.h"

namespace troy {
	void give_new_artifact(human& human, const std::string& artifact_name) {
		human.possession = std::move(std::make_unique<artifact>(artifact_name));
	}

	void exchange_artifacts(std::unique_ptr<artifact>& a, std::unique_ptr<artifact>& b) {
		std::swap(a, b);
	}

	void manifest_power(human& human, const std::string& power_name) {
		human.own_power = std::make_shared<power>(power_name);
	}

	void use_power(human& caster, human& target) {
		target.influenced_by = caster.own_power;
	}

	long power_intensity(const human& human) {
		return human.own_power ? human.own_power.use_count() : 0;
	}
}