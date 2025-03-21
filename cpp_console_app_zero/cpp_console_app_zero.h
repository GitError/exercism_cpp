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
#include <limits.h>
#include <map>
#include <stack>
#include <cstddef>
#include "boost/date_time/posix_time/posix_time.hpp"
#include <mutex>
#include <cctype>
#include <cstdint>
#include <numeric>
#include <random>
#include <regex>
#include <functional>
#include <cstddef>
#include <utility>
#include <queue>
#include <execution>
#include <string_view>

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
	int preparationTime(std::vector<std::string> layers, int minutes_per_layer = 2);
	amount quantities(std::vector<std::string> layers);
	void addSecretIngredient(std::vector<std::string>& my_layers, std::vector<std::string> friend_layers);
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
	enum flavor { equilateral, isosceles, scalene };
	flavor kind(double a, double b, double c);
}

namespace two_fer
{
	std::string two_fer(std::string name = "you");
}

namespace grains {
	unsigned long long square(int n);
	unsigned long long total();
}

namespace grade_school {
	class school {
	public:
		void add(const std::string& name, int grade);
		std::vector<std::string> grade(int grade) const;
		std::map<int, std::vector<std::string>> roster() const;
	private:
		std::map<int, std::vector<std::string>> students;
	};
}

namespace hamming {
	int compute(std::string dna1, std::string dna2);
}

namespace nucleotide_count {
	std::map<char, int> count(const std::string sequence);
}

namespace rna_transcription {
	char to_rna(char dna);
	std::string to_rna(std::string dna);
}

namespace collatz_conjecture {
	int steps(int n);
}

namespace difference_of_squares {
	int square_of_sum(int n);
	int sum_of_squares(int n);
	int difference(int n);
}

namespace matching_brackets {
	bool check(std::string brackets);
}

namespace trinary {
	int to_decimal(const std::string& trinary);
}

namespace isogram {
	bool is_isogram(const std::string& word);
}

namespace luhn {
	bool valid(std::string digits);
}

namespace nth_prime {
	bool is_prime(int n);
	int nth(int n);
}

namespace simple_linked_list {
	class List {
	public:
		List() = default;
		~List();
		List(const List&) = delete;
		List& operator=(const List&) = delete;
		List(List&&) = delete;
		List& operator=(List&&) = delete;
		std::size_t size() const;
		void push(int entry);
		int pop();
		void reverse();
	private:
		struct Element {
			Element(int data) : data{ data } {};
			int data{};
			Element* next{ nullptr };
		};
		Element* head{ nullptr };
		std::size_t current_size{ 0 };
	};

}

namespace kindergarten_garden {
	enum class Plants { clover, grass, violets, radishes };
	std::array<Plants, 4> plants(const std::string garden, const std::string student);
}

namespace gigasecond {
	boost::posix_time::ptime advance(const boost::posix_time::ptime inputTime);
}

namespace pascals_triangle {
	std::vector<std::vector<int>> generate_rows(int n);
}

namespace armstrong_numbers {
	bool is_armstrong_number(int n);
}

namespace acronym {
	std::string acronym(std::string phrase);
}

namespace perfect_numbers {
	enum class classification { perfect, abundant, deficient };
	classification classify(int n);
}

namespace isbn_verifier {
	bool is_valid(std::string isbn);
}

namespace binary {
	int convert(std::string binary);
}

namespace scrabble_score {
	int score(std::string word);
}

namespace pig_latin {
	std::string translate(std::string phrase);
}

namespace sublist {
	enum class comparison { equal, unequal, sublist, superlist };
	comparison check_lists(std::vector<int> list1, std::vector<int> list2);
}

namespace secret_handshake {
	std::vector<std::string> commands(int n);
}

namespace resistor_color {
	int color_code(std::string color);
	std::vector<std::string> colors();
}

namespace say {
	const std::vector<std::string> below_20 = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	const std::vector<std::string> tens = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	const std::vector<std::string> thousands = { "", "thousand", "million", "billion" };
	std::string convert_hundreds(long long number);
	std::string in_english(long long number);
}

namespace Bankaccount {
	class Bankaccount {
	public:
		Bankaccount() : is_open(false), balance_amount(0) {}

		void open() {
			std::lock_guard<std::mutex> lock(mtx);
			if (is_open) {
				throw std::runtime_error("Account is already open");
			}
			is_open = true;
			balance_amount = 0;
		}

		void close() {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Account is already closed");
			}
			is_open = false;
		}

		void deposit(int amount) {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot deposit to a closed account");
			}
			if (amount < 0) {
				throw std::runtime_error("Cannot deposit a negative amount");
			}
			balance_amount += amount;
		}

		void withdraw(int amount) {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot withdraw from a closed account");
			}
			if (amount < 0) {
				throw std::runtime_error("Cannot withdraw a negative amount");
			}
			if (amount > balance_amount) {
				throw std::runtime_error("Insufficient funds");
			}
			balance_amount -= amount;
		}

		int balance() const {
			std::lock_guard<std::mutex> lock(mtx);
			if (!is_open) {
				throw std::runtime_error("Cannot check balance of a closed account");
			}
			return balance_amount;
		}

	private:
		mutable std::mutex mtx;
		bool is_open;
		int balance_amount;
	};
}

namespace bob {
	std::string hey(std::string phrase);
}

namespace chicken_coop {
	int positions_to_quantity(int number);
}

namespace prime_factors {
	std::vector<long long int> of(long long int number);
}

namespace arcade {
	class HighScores {
	private:
		std::vector<int> scores;
	public:
		HighScores(std::vector<int> scores) : scores(scores) {};
		std::vector<int> list_scores();
		int latest_score();
		int personal_best();
		std::vector<int> top_three();
	};
}

namespace etl {
	std::map<char, int> transform(const std::map<int, std::vector<char>>& old);
}

namespace sieve {
	std::vector<int> primes(int n);
}

namespace troy {
	struct artifact {
		// constructors needed (until C++20)
		artifact(std::string name) : name(name) {}
		std::string name;
	};
	struct power {
		// constructors needed (until C++20)
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

namespace binary_search_tree {
	template <typename T>
	class binary_tree {
	public:
		binary_tree(T value) : data_(value) {}

		void insert(T value) {
			if (value <= data_) {
				if (left_) {
					left_->insert(value);
				}
				else {
					left_ = std::make_unique<binary_tree>(value);
				}
			}
			else {
				if (right_) {
					right_->insert(value);
				}
				else {
					right_ = std::make_unique<binary_tree>(value);
				}
			}
		}

		const T& data() const {
			return data_;
		}

		const std::unique_ptr<binary_tree>& left() const {
			return left_;
		}

		const std::unique_ptr<binary_tree>& right() const {
			return right_;
		}

		// Iterator class for in-order traversal
		class iterator {
		public:
			using iterator_category = std::input_iterator_tag;
			using value_type = T;
			using difference_type = std::ptrdiff_t;
			using pointer = T*;
			using reference = T&;

			iterator() = default;
			iterator(binary_tree* node) {
				traverse_left(node);
			}

			iterator& operator++() {
				if (!stack_.empty()) {
					auto node = stack_.top();
					stack_.pop();
					traverse_left(node->right_.get());
				}
				return *this;
			}

			bool operator!=(const iterator& other) const {
				return !(*this == other);
			}

			bool operator==(const iterator& other) const {
				if (stack_.empty() && other.stack_.empty()) {
					return true;
				}
				if (stack_.empty() || other.stack_.empty()) {
					return false;
				}
				return stack_.top() == other.stack_.top();
			}

			const T& operator*() const {
				return stack_.top()->data_;
			}

		private:
			std::stack<binary_tree*> stack_;

			void traverse_left(binary_tree* node) {
				while (node) {
					stack_.push(node);
					node = node->left_.get();
				}
			}
		};

		iterator begin() {
			return iterator(this);
		}

		iterator end() {
			return iterator();
		}

	private:
		T data_;
		std::unique_ptr<binary_tree> left_;
		std::unique_ptr<binary_tree> right_;
	};
}

namespace rail_fence_cipher {
	std::string encode(const std::string& plaintext, int num_rails);
	std::string decode(const std::string& ciphertext, int num_rails);
}

namespace spiral_matrix {
	std::vector<std::vector<uint32_t>> spiral_matrix(int size);
}

namespace sum_of_multiples {
	int to(const std::vector<int>& bases, int level);
}

namespace robot_name {
	class robot {
	public:
		robot() {
			reset();
		}
		std::string name() const {
			return robot_name_;
		}
		void reset() {
			std::string new_name;
			do {
				new_name = generate_name();
			} while (used_names_.find(new_name) != used_names_.end());
			if (!robot_name_.empty()) {
				used_names_.erase(robot_name_);
			}
			robot_name_ = new_name;
			used_names_.insert(robot_name_);
		}
	private:
		std::string robot_name_;
		static std::unordered_set<std::string> used_names_;
		static std::string generate_name() {
			static const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			static std::random_device rd;
			static std::mt19937 gen(rd());
			static std::uniform_int_distribution<> letter_dist(0, 25);
			static std::uniform_int_distribution<> digit_dist(0, 9);
			std::string name;
			name += letters[letter_dist(gen)];
			name += letters[letter_dist(gen)];
			name += std::to_string(digit_dist(gen));
			name += std::to_string(digit_dist(gen));
			name += std::to_string(digit_dist(gen));
			return name;
		}
	};
	bool validate_name(const std::string& name);
}

namespace date_independent {
	class clock {
	private:
		int hours_;
		int minutes_;
		// Normalize time to ensure hours are in [0,23] and minutes in [0,59]
		void normalize() {
			int total_minutes = hours_ * 60 + minutes_;
			// Handle negative total minutes
			while (total_minutes < 0) {
				total_minutes += 24 * 60; // Add a full day
			}
			// Normalize to a day
			total_minutes %= (24 * 60);
			hours_ = (total_minutes / 60) % 24;
			minutes_ = total_minutes % 60;
		}
	public:
		// Static factory method to create a clock
		static clock at(int hours, int minutes) {
			return clock(hours, minutes);
		}
		// Constructor
		clock(int hours, int minutes) : hours_(hours), minutes_(minutes) {
			normalize();
		}
		// Add minutes to the clock
		clock plus(int minutes) const {
			return clock(hours_, minutes_ + minutes);
		}
		// Convert to string in "HH:MM" format
		operator std::string() const {
			std::ostringstream oss;
			oss << std::setw(2) << std::setfill('0') << hours_ << ":"
				<< std::setw(2) << std::setfill('0') << minutes_;
			return oss.str();
		}
		// Equality operator
		bool operator==(const clock& other) const {
			return hours_ == other.hours_ && minutes_ == other.minutes_;
		}
		// Inequality operator
		bool operator!=(const clock& other) const {
			return !(*this == other);
		}
	};
}

namespace run_length_encoding {
	std::string encode(const std::string& text);
	std::string decode(const std::string& text);
}

namespace list_ops {
	// Append: Add all items from the second list to the end of the first list
	template <typename T>
	void append(std::vector<T>& list1, const std::vector<T>& list2) {
		for (const auto& item : list2) {
			list1.push_back(item);
		}
	}

	// Concat: Combine all items from a series of lists into one flattened list
	template <typename T>
	std::vector<T> concat(const std::vector<std::vector<T>>& lists) {
		std::vector<T> result;
		for (const auto& list : lists) {
			for (const auto& item : list) {
				result.push_back(item);
			}
		}
		return result;
	}

	// Filter: Return a list of items for which predicate(item) is true
	template <typename T, typename Pred>
	std::vector<T> filter(const std::vector<T>& list, Pred predicate) {
		std::vector<T> result;
		for (const auto& item : list) {
			if (predicate(item)) {
				result.push_back(item);
			}
		}
		return result;
	}

	// Length: Return the total number of items in the list
	template <typename T>
	size_t length(const std::vector<T>& list) {
		size_t count = 0;
		for (auto it = list.begin(); it != list.end(); ++it) {
			count++;
		}
		return count;
	}

	// Map: Apply a function to each item in the list and return the results
	template <typename T, typename Func>
	std::vector<T> map(const std::vector<T>& list, Func function) {
		std::vector<T> result;
		for (const auto& item : list) {
			result.push_back(function(item));
		}
		return result;
	}

	// Foldl: Fold each item into the accumulator from the left
	template <typename T, typename Acc, typename Func>
	Acc foldl(const std::vector<T>& list, Acc initial, Func function) {
		Acc accumulator = initial;
		for (const auto& item : list) {
			accumulator = function(accumulator, item);
		}
		return accumulator;
	}

	// Foldr: Fold each item into the accumulator from the right
	template <typename T, typename Acc, typename Func>
	Acc foldr(const std::vector<T>& list, Acc initial, Func function) {
		Acc accumulator = initial;
		for (auto it = list.rbegin(); it != list.rend(); ++it) {
			accumulator = function(accumulator, *it);
		}
		return accumulator;
	}

	// Reverse: Return a list with all items in reversed order
	template <typename T>
	std::vector<T> reverse(const std::vector<T>& list) {
		std::vector<T> result;
		for (auto it = list.rbegin(); it != list.rend(); ++it) {
			result.push_back(*it);
		}
		return result;
	}
}

namespace beer_song {
	std::string verse(int bottle_count);
	std::string sing(int start, int end = 0);
}

namespace diamond {
	std::vector<std::string> rows(char letter);
}

namespace phone_number {
	class phone_number {
	private:
		std::string cleaned_number;
	public:
		phone_number(const std::string& input);
		std::string number() const;
	};
}

namespace yacht {
	int score(const std::vector<int>& dice, const std::string& category);
}

namespace all_your_base {
	std::vector<unsigned int> convert(int from_base, const std::vector<unsigned int>& digits, int to_base);
}

namespace anagram {
	class anagram {
	private:
		std::string word;
		std::string normalized_word;

		// Helper function to convert a string to lowercase
		std::string to_lower(const std::string& s) const {
			std::string result = s;
			std::transform(result.begin(), result.end(), result.begin(),
				[](unsigned char c) { return std::tolower(c); });
			return result;
		}

		// Helper function to sort a string (for anagram comparison)
		std::string sort_string(const std::string& s) const {
			std::string result = s;
			std::sort(result.begin(), result.end());
			return result;
		}
	public:
		anagram(const std::string& word)
			: word(word), normalized_word(sort_string(to_lower(word))) {
		}

		// Overload for initializer list to handle {"hello", "world", ...} directly
		std::vector<std::string> matches(std::initializer_list<std::string> candidates) const {
			std::vector<std::string> result;
			for (const auto& candidate : candidates) {
				// Skip if the candidate is the same word (case-insensitive)
				if (to_lower(candidate) == to_lower(word)) {
					continue;
				}
				// Check if the sorted lowercase versions are the same
				if (sort_string(to_lower(candidate)) == normalized_word) {
					result.push_back(candidate);
				}
			}
			return result;
		}

		// Template version for other container types
		template <typename Container>
		Container matches(const Container& candidates) const {
			Container result;
			for (const auto& candidate : candidates) {
				// Skip if the candidate is the same word (case-insensitive)
				if (to_lower(candidate) == to_lower(word)) {
					continue;
				}
				// Check if the sorted lowercase versions are the same
				if (sort_string(to_lower(candidate)) == normalized_word) {
					result.insert(result.end(), candidate);
				}
			}
			return result;
		}
	};
}

namespace dnd_character {
	int modifier(int ability_score);
	int ability();
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
}

namespace binary_search {
	std::size_t find(const std::vector<int>& data, int target);
}

namespace complex_numbers {
	class Complex {
	private:
		double real_part;
		double imaginary_part;
	public:
		// Constructor
		Complex(double real = 0.0, double imag = 0.0)
			: real_part(real), imaginary_part(imag) {
		}

		// Accessor methods
		double real() const { return real_part; }
		double imag() const { return imaginary_part; }

		// Basic operations
		Complex conj() const;
		double abs() const;
		Complex exp() const;

		// Arithmetic operators
		Complex operator+(const Complex& other) const;
		Complex operator-(const Complex& other) const;
		Complex operator*(const Complex& other) const;
		Complex operator/(const Complex& other) const;

		// Operations with real numbers
		Complex operator+(double scalar) const;
		Complex operator-(double scalar) const;
		Complex operator*(double scalar) const;
		Complex operator/(double scalar) const;

		// Friend functions for operations where real number is on the left
		friend Complex operator+(double scalar, const Complex& complex);
		friend Complex operator-(double scalar, const Complex& complex);
		friend Complex operator*(double scalar, const Complex& complex);
		friend Complex operator/(double scalar, const Complex& complex);
	};
}

namespace minesweeper {
	std::vector<std::string> annotate(const std::vector<std::string>& minefield);
}

namespace series {
	std::vector<std::string> slice(const std::string& digits, int length);
}

namespace food_chain {
	const std::vector<std::string> animals = {
		"", "fly", "spider", "bird", "cat", "dog", "goat", "cow", "horse"
	};

	const std::vector<std::string> reactions = {
		"",
		"I don't know why she swallowed the fly. Perhaps she'll die.",
		"It wriggled and jiggled and tickled inside her.",
		"How absurd to swallow a bird!",
		"Imagine that, to swallow a cat!",
		"What a hog, to swallow a dog!",
		"Just opened her throat and swallowed a goat!",
		"I don't know how she swallowed a cow!",
		"She's dead, of course!"
	};

	std::string verse(int verse_number) {
		std::string result = "I know an old lady who swallowed a " + animals[verse_number] + ".\n";
		result += reactions[verse_number] + "\n";
		if (verse_number == 8 || verse_number == 1) {
			return result;
		}
		for (int i = verse_number; i > 1; i--) {
			if (i == 3) {
				result += "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n";
			}
			else {
				result += "She swallowed the " + animals[i] + " to catch the " + animals[i - 1] + ".\n";
			}
		}
		result += "I don't know why she swallowed the fly. Perhaps she'll die.\n";
		return result;
	}

	std::string verses(int start_verse, int end_verse) {
		std::string result;
		for (int i = start_verse; i <= end_verse; i++) {
			result += verse(i);
			result += "\n";
		}
		return result;
	}

	std::string sing() {
		return verses(1, 8);
	}
}

namespace robot_simulator {
	enum class Bearing {
		NORTH,
		EAST,
		SOUTH,
		WEST
	};

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

namespace resistor_color_duo {
	int value(const std::vector<std::string>& colors);
}

namespace largest_series_product {
	int largest_product(const std::string& digits, int span);
}

namespace two_bucket {
	enum class bucket_id { one, two };

	struct measure_result {
		int num_moves;
		bucket_id goal_bucket;
		int other_bucket_volume;
	};

	struct State {
		int b1; 
		int b2;
		int moves;

		State(int b1, int b2, int m) : b1(b1), b2(b2), moves(m) {}
	};

	struct StateHash {
		size_t operator()(const State& state) const {
			return std::hash<int>()(state.b1) ^
				(std::hash<int>()(state.b2) << 1);
		}
	};

	measure_result measure(int bucket1_capacity, int bucket2_capacity,
		int target_volume, bucket_id start_bucket);
}

namespace knapsack {
	struct Item {
		int weight;
		int value;
	};
	int maximum_value(int max_weight, const std::vector<Item>& items);
}

namespace parallel_letter_frequency {
	std::unordered_map<char, int> frequency(const std::vector<std::string_view>& texts);
}

namespace crypto_square {
	class cipher {
	private:
		std::string normalized_text;
		int num_columns;
		int num_rows;
		std::string normalize(const std::string& input);
		void calculate_dimensions();

	public:
		cipher(const std::string& input);
		std::string normalized_plain_text() const;
		std::string normalized_cipher_text() const;
	};
}
