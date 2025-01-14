#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

int main();

namespace raindrops {
	std::string convert(int drops);
}

namespace log_line {
	std::string message(std::string line);
	std::string log_level(std::string line);
	std::string reformat(std::string line);
}

namespace reverse_string {
	std::string reverse_string(std::string input);
}

namespace numbers_1 {
	double daily_rate(double hourly_rate);
	double apply_discount(double before_discount, double discount);
	int monthly_rate(double hourly_rate, double discount);
	int days_in_budget(int budget, double hourly_rate, double discount);
}

namespace vehicle_purchase {
	bool needs_license(std::string kind);
	std::string choose_vehicle(std::string option1, std::string option2);
	double calculate_resell_price(double original_price, double age);
}

namespace loops_1 {
	double interest_rate(double balance);
	double yearly_interest(double balance);
	double annual_balance_update(double balance);
	int years_until_desired_balance(double balance, double target_balance);
}

namespace targets {
	class Alien {
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
	private:
		int health;
	};
}

namespace atbash_cipher {
	char atbash(char c);
	std::string transform(const std::string& input);
	std::string encode(const std::string& input);
	std::string decode(const std::string& input);
}

namespace marking_grades {
	std::vector<int> round_down_scores(std::vector<double> student_scores);
	int count_failed_students(std::vector<int> student_scores);
	std::vector<int> above_threshold(std::vector<int> student_scores, int threshold);
	std::array<int, 4> letter_grades(int highest_score);
	std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names);
	std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names);
}

namespace darts {
	int score(double x, double y) {
		double distance = std::sqrt(x * x + y * y);
		return (distance > 10.0) ? 0 : (distance > 5.0) ? 1 : (distance > 1.0) ? 5 : 10;
	}
}

namespace hexadecimal {
	int hex_char_to_decimal(char hex_char);
	long long convert(const std::string& hex_string);
}

namespace election {
	struct ElectionResult {
		std::string name{};
		int votes{};
	};
	int vote_count(const ElectionResult& candidate);
	void increment_vote_count(ElectionResult& candidate, int votes);
	ElectionResult& determine_result(std::vector<ElectionResult>& final_count);
}

namespace hellmath {
	enum class AccountStatus { troll, guest, user, mod };
	enum class Action { read, write, remove };
	bool display_post(AccountStatus poster, AccountStatus viewer);
	bool permission_check(Action action, AccountStatus account);
	bool valid_player_combination(AccountStatus player1, AccountStatus player2);
	bool has_priority(AccountStatus account1, AccountStatus account2);
}

namespace protein_translation {
	std::vector<std::string> proteins(std::string rna);
}

namespace rotational_cipher {
	std::string rotate(std::string input, int shift);
}

namespace pangram {
	bool is_pangram(std::string sentence);
}

namespace star_map {
	enum System { EpsilonEridani, BetaHydri, Sol, AlphaCentauri, DeltaEridani, Omicron2Eridani };
}

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

namespace lasagna_master {
	struct amount { int noodles; double sauce; };
	int preparationTime(std::vector<std::string> layers, int minutes_per_layer=2);
	amount quantities(std::vector<std::string> layers);
	void addSecretIngredient(std::vector<std::string> &my_layers, std::vector<std::string> friend_layers);
	void addSecretIngredient(std::vector<std::string>& my_layers, std::string secret_ingredient);
	std::vector<double> scaleRecipe(std::vector<double> quantities_for_two_portions, int portions);
}

namespace speedywagon {
	struct pillar_men_sensor {
		int activity{};
		std::string location{};
		std::vector<int> data{};
	};
	int uv_light_heuristic(std::vector<int>* data_array);
	bool connection_check(pillar_men_sensor* sensor);
	int activity_counter(pillar_men_sensor* first_sensor, int capacity);
	bool alarm_control(pillar_men_sensor* sensor);
	bool uv_alarm(pillar_men_sensor* sensor);
}

namespace space_age {
	class space_age {
	public:
		explicit space_age(long int seconds);
		long int seconds() const;
		float on_earth() const;
		float on_mercury() const;
		float on_venus() const;
		float on_mars() const;
		float on_jupiter() const;
		float on_saturn() const;
		float on_uranus() const;
		float on_neptune() const;
	private:
		long int secs;
		static constexpr float EARTH_YEAR_IN_SECONDS = 31557600.0f;
		static constexpr float MERCURY_YEAR_RATIO = 0.2408467f;
		static constexpr float VENUS_YEAR_RATIO = 0.61519726f;
		static constexpr float MARS_YEAR_RATIO = 1.8808158f;
		static constexpr float JUPITER_YEAR_RATIO = 11.862615f;
		static constexpr float SATURN_YEAR_RATIO = 29.447498f;
		static constexpr float URANUS_YEAR_RATIO = 84.016846f;
		static constexpr float NEPTUNE_YEAR_RATIO = 164.79132f;
	};
}

namespace triangle {
	enum flavor { equilateral , isosceles, scalene };
	flavor kind(double a, double b, double c);
}
