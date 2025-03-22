#pragma once

namespace targets {
	class Alien {
	private:
		int health;

	public:
		int x_coordinate;
		int y_coordinate;
		Alien(int x, int y) : x_coordinate(x), y_coordinate(y), health(3) {}
		int get_health() const { return health; }
		bool hit() {
			if (health > 0) {
				--health;
				return true;
			}
			return false;
		}
		bool is_alive() const { return health > 0; }
		bool teleport(int new_x, int new_y) {
			if (is_alive()) {
				x_coordinate = new_x;
				y_coordinate = new_y;
				return true;
			}
			return false;
		}
		bool collision_detection(const Alien& player) const {
			return x_coordinate == player.x_coordinate && y_coordinate == player.y_coordinate;
		}
	};
}