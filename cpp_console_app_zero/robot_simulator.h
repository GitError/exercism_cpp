#pragma once
#include <utility>
#include <string>

namespace robot_simulator {
	enum class Bearing { NORTH, EAST, SOUTH, WEST };

	class Robot {
	private:
		std::pair<int, int> position;
		Bearing bearing;
	public:
		Robot() : position(0, 0), bearing(Bearing::NORTH) {}
		Robot(const std::pair<int, int>& pos, Bearing dir) : position(pos), bearing(dir) {}

		std::pair<int, int> get_position() const {
			return position;
		}

		Bearing get_bearing() const {
			return bearing;
		}

		void turn_right() {
			switch (bearing) {
			case Bearing::NORTH: bearing = Bearing::EAST; break;
			case Bearing::EAST: bearing = Bearing::SOUTH; break;
			case Bearing::SOUTH: bearing = Bearing::WEST; break;
			case Bearing::WEST: bearing = Bearing::NORTH; break;
			}
		}

		void turn_left() {
			switch (bearing) {
			case Bearing::NORTH: bearing = Bearing::WEST; break;
			case Bearing::WEST: bearing = Bearing::SOUTH; break;
			case Bearing::SOUTH: bearing = Bearing::EAST; break;
			case Bearing::EAST: bearing = Bearing::NORTH; break;
			}
		}

		void advance() {
			switch (bearing) {
			case Bearing::NORTH: position.second++; break;
			case Bearing::EAST: position.first++; break;
			case Bearing::SOUTH: position.second--; break;
			case Bearing::WEST: position.first--; break;
			}
		}

		void execute_sequence(const std::string& instructions) {
			for (char instruction : instructions) {
				switch (instruction) {
				case 'R': turn_right(); break;
				case 'L': turn_left(); break;
				case 'A': advance(); break;
				}
			}
		}
	};
}