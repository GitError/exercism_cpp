#pragma once
#include <string>
#include "star_map.h"

namespace heaven {
	class Vessel {
	public:
		std::string name{};
		int generation{};
		int busters{};
		star_map::System current_system;
		Vessel(std::string name);
		Vessel(std::string name, int generation);
		Vessel(std::string name, int generation, star_map::System current_system);
		Vessel replicate(std::string name);
		void make_buster();
		bool shoot_buster();
	};

	std::string get_older_bob(Vessel one, Vessel two);

	bool in_the_same_system(Vessel one, Vessel two);
}