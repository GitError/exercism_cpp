#include "heaven.h"

namespace heaven {
	Vessel::Vessel(std::string name) {
		this->name = name;
		this->generation = 1;
		this->busters = 0;
		this->current_system = star_map::System::Sol;
	}

	Vessel::Vessel(std::string name, int generation) {
		this->name = name;
		this->generation = generation;
		this->busters = 0;
		this->current_system = star_map::System::Sol;
	}

	Vessel::Vessel(std::string name, int generation, star_map::System current_system) {
		this->name = name;
		this->generation = generation;
		this->busters = 0;
		this->current_system = current_system;
	}

	Vessel Vessel::replicate(std::string name) {
		return Vessel(name, this->generation + 1, this->current_system);
	}

	void Vessel::make_buster() {
		this->busters++;
	}

	bool Vessel::shoot_buster() {
		if (this->busters > 0) {
			this->busters--;
			return true;
		}
		return false;
	}

	std::string get_older_bob(Vessel one, Vessel two) {
		return (one.generation < two.generation) ? one.name : two.name;
	}

	bool in_the_same_system(Vessel one, Vessel two) {
		return one.current_system == two.current_system;
	}
}