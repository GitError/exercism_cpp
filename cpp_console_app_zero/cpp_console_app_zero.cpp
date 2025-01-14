#include "cpp_console_app_zero.h"

int main()
{
	const space_age::space_age age(8210123456);

	std::cout << "Earth: " << age.on_earth() << '\n';
	std::cout << "Mercury: " << age.on_mercury() << '\n';
	std::cout << "Venus: " << age.on_venus() << '\n';

	return 0;
}

namespace raindrops {
	std::string convert(int drops) {
		std::string answer;
		if (drops % 3 == 0) answer += "Pling";
		if (drops % 5 == 0) answer += "Plang";
		if (drops % 7 == 0) answer += "Plong";
		if (answer.empty()) answer = std::to_string(drops);
		return answer;
	}
}

namespace log_line {
	std::string message(std::string line) {
		return line.substr(line.find("]:") + 3);
	}
	std::string log_level(std::string line) {
		return line.substr(1, line.find("]") - 1);
	}
	std::string reformat(std::string line) {
		return log_line::message(line) + " (" + log_line::log_level(line) + ")";
	}
}

namespace reverse_string {
	std::string reverse_string(std::string input) {
		return std::string(input.rbegin(), input.rend());
	}
}

namespace numbers_1 {
	double daily_rate(double hourly_rate) {
		return hourly_rate * 8;
	}
	double apply_discount(double before_discount, double discount) {
		return before_discount * (1 - discount / 100);
	}
	int monthly_rate(double hourly_rate, double discount) {
		return std::ceil(apply_discount(daily_rate(hourly_rate) * 22, discount));
	}
	int days_in_budget(int budget, double hourly_rate, double discount) {
		return budget / apply_discount(daily_rate(hourly_rate), discount);
	}
}

namespace vehicle_purchase {
	bool needs_license(std::string kind) {
		return kind == "car" || kind == "truck";
	}
	std::string choose_vehicle(std::string option1, std::string option2) {
		return (option1 < option2 ? option1 : option2) + " is clearly the better choice.";
	}
	double calculate_resell_price(double original_price, double age) {
		if (age < 3) return original_price * 0.8;
		if (age >= 10) return original_price * 0.5;
		return original_price * 0.7;
	}
}

namespace loops_1 {
	double interest_rate(double balance) {
		if (balance < 0) return 3.213;
		if (balance < 1000) return 0.5;
		if (balance < 5000) return 1.621;
		return 2.475;
	}
	double yearly_interest(double balance) {
		return balance * (interest_rate(balance) / 100);
	}
	double annual_balance_update(double balance) {
		return balance + yearly_interest(balance);
	}
	int years_until_desired_balance(double balance, double target_balance) {
		int years = 0;
		while (balance < target_balance) {
			balance = annual_balance_update(balance);
			years++;
		}
		return years;
	}
}

namespace atbash_cipher {
	char atbash(char c) {
		if (c >= 'a' && c <= 'z') return 'z' - c + 'a';
		if (c >= 'A' && c <= 'Z') return 'z' - tolower(c) + 'a';
		return c;
	}
	std::string transform(const std::string& input) {
		std::string answer;
		for (char c : input) {
			if (isalnum(c)) {
				answer += atbash(c);
			}
		}
		return answer;
	}
	std::string encode(const std::string& input) {
		std::string transformed = transform(input);
		std::string answer;
		for (size_t i = 0; i < transformed.size(); ++i) {
			if (i > 0 && i % 5 == 0) answer += ' ';
			answer += transformed[i];
		}
		return answer;
	}
	std::string decode(const std::string& input) {
		return transform(input);
	}
}

namespace marking_grades {
	std::vector<int> round_down_scores(std::vector<double> student_scores) {
		std::vector<int> rounded_scores;
		for (double score : student_scores) {
			rounded_scores.push_back(static_cast<int>(score));
		}
		return rounded_scores;
	}
	int count_failed_students(std::vector<int> student_scores) {
		int failed_students = 0;
		for (int score : student_scores) {
			if (score <= 40) {
				++failed_students;
			}
		}
		return failed_students;
	}
	std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {
		std::vector<int> above_threshold;
		for (int score : student_scores) {
			if (score >= threshold) {
				above_threshold.push_back(score);
			}
		}
		return above_threshold;
	}
	std::array<int, 4> letter_grades(int highest_score) {
		int interval = (highest_score - 40) / 4;
		return { 41, 41 + interval, 41 + 2 * interval, 41 + 3 * interval };
	}
	std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names) {
		std::vector<std::string> rankings;
		for (size_t i = 0; i < student_scores.size(); ++i) {
			rankings.push_back(std::to_string(i + 1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
		}
		return rankings;
	}
	std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {
		for (size_t i = 0; i < student_scores.size(); ++i) {
			if (student_scores[i] == 100) {
				return student_names[i];
			}
		}
		return "";
	}
}

namespace leap {
	static bool is_leap_year(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}
}

namespace darts {
	int score(double x, double y);
}

namespace hexadecimal {
	int hex_char_to_decimal(char hex_char) {
		if (hex_char >= '0' && hex_char <= '9') return hex_char - '0';
		if (hex_char >= 'a' && hex_char <= 'f') return 10 + (hex_char - 'a');
		if (hex_char >= 'A' && hex_char <= 'F') return 10 + (hex_char - 'A');
		return -1;
	}
	long long convert(const std::string& hex_string) {
		long long decimal_value = 0;
		for (char hex_char : hex_string) {
			int digit_value = hex_char_to_decimal(hex_char);
			if (digit_value == -1) return 0;
			decimal_value = decimal_value * 16 + digit_value;
		}
		return decimal_value;
	}
}

namespace election {
	int vote_count(const ElectionResult& candidate) {
		return candidate.votes;
	}
	void increment_vote_count(ElectionResult& candidate, int votes) {
		candidate.votes += votes;
	}
	ElectionResult& determine_result(std::vector<ElectionResult>& final_count) {
		size_t winner{};
		for (int i = 0; i < final_count.size(); ++i) {
			if (final_count.at(i).votes > final_count[winner].votes) {
				winner = i;
			}
		}
		final_count[winner].name = "President " + final_count[winner].name;
		return final_count.at(winner);
	}
}

namespace hellmath {
	bool display_post(AccountStatus poster, AccountStatus viewer) {
		switch (poster) {
		case AccountStatus::troll:
			switch (viewer) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::guest:
			switch (viewer) {
			case AccountStatus::user:
				return false;
			default:
				return true;
			}
		case AccountStatus::user:
			switch (viewer) {
			case AccountStatus::guest:
				return true;
			default:
				return true;
			}
		case AccountStatus::mod:
			return true;
		default:
			return false;
		}
	}
	bool permission_check(Action action, AccountStatus account) {
		switch (action) {
		case Action::read:
			return true;
		case Action::write:
			switch (account) {
			case AccountStatus::guest:
				return false;
			default:
				return true;
			}
		case Action::remove:
			switch (account) {
			case AccountStatus::mod:
				return true;
			default:
				return false;
			}
		default:
			return false;
		}
	}
	bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
		switch (player1) {
		case AccountStatus::troll:
			switch (player2) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::guest:
			return false;
		default:
			switch (player2) {
			case AccountStatus::guest:
				return false;
			case AccountStatus::troll:
				return false;
			default:
				return true;
			}
		}
	}
	bool has_priority(AccountStatus account1, AccountStatus account2) {
		switch (account1) {
		case AccountStatus::troll:
			return false;
		case AccountStatus::guest:
			switch (account2) {
			case AccountStatus::troll:
				return true;
			default:
				return false;
			}
		case AccountStatus::user:
			switch (account2) {
			case AccountStatus::troll:
			case AccountStatus::guest:
				return true;
			default:
				return false;
			}
		case AccountStatus::mod:
			switch (account2) {
			case AccountStatus::troll:
			case AccountStatus::guest:
			case AccountStatus::user:
				return true;
			default:
				return false;
			}
		default:
			return false;
		}
	}
}

namespace protein_translation {
	const std::unordered_map<std::string, std::string> codon_to_protein = {
		{"AUG", "Methionine"},
		{"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
		{"UUA", "Leucine"}, {"UUG", "Leucine"},
		{"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
		{"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
		{"UGU", "Cysteine"}, {"UGC", "Cysteine"},
		{"UGG", "Tryptophan"},
		{"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}
	};
	std::vector<std::string> proteins(const std::string rna) {
		std::vector<std::string> result;
		for (size_t i = 0; i < rna.size(); i += 3) {
			std::string codon = rna.substr(i, 3);
			auto it = codon_to_protein.find(codon);
			if (it == codon_to_protein.end() || it->second == "STOP") {
				break;
			}
			result.push_back(it->second);
		}
		return result;
	}
}

namespace rotational_cipher {
	std::string rotate(std::string input, int shift) {
		std::string rotated;
		for (char c : input) {
			if (isalpha(c)) {
				char base = islower(c) ? 'a' : 'A';
				rotated += base + (c - base + shift) % 26;
			}
			else {
				rotated += c;
			}
		}
		return rotated;
	}
}

namespace pangram {
	bool is_pangram(std::string sentence) {
		std::array<bool, 26> letters{};
		for (char c : sentence) {
			if (isalpha(c)) {
				letters[static_cast<std::array<bool, 26Ui64>::size_type>(tolower(c)) - 'a'] = true;
			}
		}
		return std::all_of(letters.begin(), letters.end(), [](bool b) { return b; });
	}
}

namespace heaven {
	Vessel::Vessel(std::string name) { this->name = name; this->generation = 1; this->busters = 0; this->current_system = star_map::System::Sol; }
	Vessel::Vessel(std::string name, int generation) { this->name = name; this->generation = generation; this->busters = 0; this->current_system = star_map::System::Sol; }
	Vessel::Vessel(std::string name, int generation, star_map::System current_system) { this->name = name; this->generation = generation; this->busters = 0; this->current_system = current_system; }
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

namespace lasagna_master {
	int preparationTime(std::vector<std::string> layers, int minutes_per_layer) {
		return layers.size() * minutes_per_layer;
	}
	amount quantities(std::vector<std::string> layers)
	{
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

namespace speedywagon {
	int uv_light_heuristic(std::vector<int>* data_array) {
		double avg{};
		for (auto element : *data_array) {
			avg += element;
		}
		avg /= data_array->size();
		int uv_index{};
		for (auto element : *data_array) {
			if (element > avg) ++uv_index;
		}
		return uv_index;
	}
	bool connection_check(pillar_men_sensor* sensor)
	{
		return sensor != nullptr;
	}
	int activity_counter(pillar_men_sensor* first_sensor, int capacity) {
		int total_activity = 0;
		for (pillar_men_sensor* sensor = first_sensor; sensor < first_sensor + capacity; ++sensor) {
			total_activity += sensor->activity;
		}
		return total_activity;
	}
	bool alarm_control(pillar_men_sensor* sensor)
	{
		return connection_check(sensor) && sensor->activity > 0;
	}
	bool uv_alarm(pillar_men_sensor* sensor)
	{
		return connection_check(sensor) && uv_light_heuristic(&sensor->data) > sensor->activity;
	}
}

namespace space_age {
	space_age::space_age(long int seconds) : secs(seconds) {}
	long int space_age::seconds() const { return secs; }
	float space_age::on_earth() const { return secs / EARTH_YEAR_IN_SECONDS; }
	float space_age::on_mercury() const { return on_earth() / MERCURY_YEAR_RATIO; }
	float space_age::on_venus() const {	return on_earth() / VENUS_YEAR_RATIO; }
	float space_age::on_mars() const { return on_earth() / MARS_YEAR_RATIO; }
	float space_age::on_jupiter() const { return on_earth() / JUPITER_YEAR_RATIO; }
	float space_age::on_saturn() const { return on_earth() / SATURN_YEAR_RATIO; }
	float space_age::on_uranus() const { return on_earth() / URANUS_YEAR_RATIO; }
	float space_age::on_neptune() const { return on_earth() / NEPTUNE_YEAR_RATIO; }
}

namespace triangle {
	flavor kind(double a, double b, double c) {
		if (a <= 0 || b <= 0 || c <= 0)
			throw std::domain_error("all sides need to be greater than zero");
		if (a + b <= c || b + c <= a || a + c <= b)
			throw std::domain_error("the sum of 2 sides should be greater than the third side");
		if (a == b && b == c)
			return flavor::equilateral;
		if (a == b || b == c || a == c)
			return flavor::isosceles;
		return flavor::scalene;
	}
}
