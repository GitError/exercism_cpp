#pragma once

namespace dnd_character {
	struct Character {
		int strength;
		int dexterity;
		int constitution;
		int intelligence;
		int wisdom;
		int charisma;
		int hitpoints;
		Character();
	};

	int modifier(int ability_score);

	int ability();
}