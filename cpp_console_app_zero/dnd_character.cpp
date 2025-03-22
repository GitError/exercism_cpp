#include "dnd_character.h"
#include <algorithm>
#include <cmath>
#include <random>
#include <vector>

namespace dnd_character {
	int modifier(int ability_score) {
		return static_cast<int>(std::floor((ability_score - 10) / 2.0));
	}

	int ability() {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		static std::uniform_int_distribution<> dice(1, 6);
		std::vector<int> rolls = { dice(gen), dice(gen), dice(gen), dice(gen) };
		std::sort(rolls.begin(), rolls.end());
		return rolls[1] + rolls[2] + rolls[3];
	}

	Character::Character() :
		strength(ability()),
		dexterity(ability()),
		constitution(ability()),
		intelligence(ability()),
		wisdom(ability()),
		charisma(ability()) {
		hitpoints = 10 + modifier(constitution);
	}
}