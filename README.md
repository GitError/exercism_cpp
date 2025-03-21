# Exercism C++ Exercises

This repository contains solutions to C++ exercises from [Exercism](https://exercism.org/), a platform for practicing and improving coding skills through interactive exercises. 

## Structure

The repository is organized into namespaces, each representing a specific exercise or topic. Each namespace is implemented in the `cpp_console_app_zero.cpp` and defined in `cpp_console_app_zero.h` file.

- [x] raindrops 
    - `std::string convert(int drops);`
- [x] log_line
    - `std::string message(std::string line);`
	- `std::string log_level(std::string line);`
	- `std::string reformat(std::string line);`
- [x] reverse_string
    - `std::string reverse_string(std::string input);`
- [x] numbers_1
    -  `double daily_rate(double hourly_rate);`
	-  `double apply_discount(double before_discount, double discount);`
	-  `int monthly_rate(double hourly_rate, double discount);`
	-  `int days_in_budget(int budget, double hourly_rate, double discount);`
- [x] vehicle_purchase
    - `bool needs_license(std::string kind);`
	- `std::string choose_vehicle(std::string option1, std::string option2);`
	- `double calculate_resell_price(double original_price, double age);`
- [x] loops_1
    - `double interest_rate(double balance);`
	- `double yearly_interest(double balance);`
	- `double annual_balance_update(double balance);`
	- `int years_until_desired_balance(double balance, double target_balance);`
- [x] targets
    - `class Alien {};`
- [x] atbash_cipher
    - `char atbash(char c);`
	- `std::string transform(const std::string& input);`
	- `std::string encode(const std::string& input);`
	- `std::string decode(const std::string& input);`
- [x] marking_grades
    - `std::vector<int> round_down_scores(std::vector<double> student_scores);`
	- `int count_failed_students(std::vector<int> student_scores);`
	- `std::vector<int> above_threshold(std::vector<int> student_scores, int threshold);`
	- `std::array<int, 4> letter_grades(int highest_score);`
	- `std::vector<std::string> student_ranking(const std::vector<int>& student_scores, const std::vector<std::string>& student_names);`
	- `std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names);`
- [x] darts
    - `int score(double x, double y);`
- [x] hexadecimal
    - `int hex_char_to_decimal(char hex_char);`
	- `long long convert(const std::string& hex_string);`
- [x] election
    - `int vote_count(const ElectionResult& candidate);`
	- `void increment_vote_count(ElectionResult& candidate, int votes);`
	- `ElectionResult& determine_result(std::vector<ElectionResult>& final_count);`
- [x] hellmath
    - `enum AccountStatus { troll, guest, user, mod };`
	- `enum Action { read, write, remove };`
	- `bool display_post(AccountStatus poster, AccountStatus viewer);`
	- `bool permission_check(Action action, AccountStatus account);`
	- `bool valid_player_combination(AccountStatus player1, AccountStatus player2);`
	- `bool has_priority(AccountStatus account1, AccountStatus account2);`
- [x] protein_translation
    - `std::vector<std::string> proteins(std::string rna);`
- [x] rotational_cipher
    - `std::string rotate(std::string input, int shift);`
- [x] pangram
    - `bool is_pangram(std::string sentence);`
- [x] star_map
    - `enum System`
- [x] heaven
    - `class Vessel {}`
	- `std::string get_older_bob(Vessel one, Vessel two);`
	- `bool in_the_same_system(Vessel one, Vessel two);`
- [x] lasagna_master
    - `struct amount;`
	- `int preparationTime(std::vector<std::string> layers, int minutes_per_layer=2);`
	- `amount quantities(std::vector<std::string> layers);`
	- `void addSecretIngredient(std::vector<std::string> &my_layers, std::vector<std::string> friend_layers);`
	- `void addSecretIngredient(std::vector<std::string>& my_layers, std::string secret_ingredient);`
	- `std::vector<double> scaleRecipe(std::vector<double> quantities_for_two_portions, int portions);`
- [x] speedywagon
    - `struct pillar_men_sensor;`
	- `int uv_light_heuristic(std::vector<int>* data_array);`
	- `bool connection_check(pillar_men_sensor* sensor);`
	- `int activity_counter(pillar_men_sensor* first_sensor, int capacity);`
	- `bool alarm_control(pillar_men_sensor* sensor);`
	- `bool uv_alarm(pillar_men_sensor* sensor);`
- [x] space_age
    - `class space_age {};`
- [x] triangle
    - `enum flavor;`
	- `bool is_equilateral(double a, double b, double c);`
- [x] two_fer
    - `std::string two_fer(std::string name = "you");`
- [x] grains
    - `unsigned long long square(int n);`
	- `unsigned long long total();`
- [x] grade_school
    - `class school {};`
- [x] hamming
	- `int compute(std::string a, std::string b);`
- [x] nucleotide_count
	- `std::map<char, int> count(const std::string sequence);`
- [x] rna_transcription
    - `char to_rna(char dna);`
	- `std::string to_rna(std::string dna);`
- [x] collatz_conjecture
    - `int steps(int n);`
- [x] difference_of_squares
    - `int square_of_sum(int n);`
    - `int sum_of_squares(int n);`
    - `int difference(int n);`
- [x] trinary
    - `int to_decimal(const std::string& trinary);`
- [x] isogram
    - `bool is_isogram(const std::string& word);`
- [x] luhn
    - `bool valid(std::string digits);`
- [x] nth_prime
    - `bool is_prime(int n);`
	- `int nth(int n);`
- [x] simple_linked_list
    - `class List {};`
- [x] kindergarten_garden
    - `enum Plants { clover, grass, violets, radishes };`
	- `std::array<Plants, 4> plants(std::string garden, std::string student);`
- [x] gigasecond
    - `boost::posix_time::ptime advance(const boost::posix_time::ptime inputTime);`
- [x] pascals_triangle
	- `std::vector<std::vector<int>> generate_rows(int n);`
- [x] armstrong_numbers
	- `bool is_armstrong_number(int n);`
- [x] acronym
	- `std::string acronym(std::string phrase);`
- [x] perfect_numbers
	- `enum class classification { perfect, abundant, deficient };`
	- `classification classify(int n);`
- [x] isbn_verifier
	- `bool is_valid(std::string isbn);`
- [x] binary
	- `int convert(std::string binary);`
- [x] scrabble_score
	- `int score(std::string word);`
- [x] pig_latin
	- `std::string translate(std::string phrase);`
- [x] sublist
	- `enum class comparison { equal, unequal, sublist, superlist };`
	- `comparison check_lists(std::vector<int> list1, std::vector<int> list2);`
- [x] secret_handshake
	- `std::vector<std::string> commands(int n);`
- [x] resistor_color
	- `int color_code(std::string color);`
	- `std::vector<std::string> colors();`
- [x] secret_handshake
	- `std::vector<std::string> commands(int n);`
- [x] resistor_color
	- `int color_code(std::string color);`
	- `std::vector<std::string> colors();`
- [x] say
	- `std::string convert_hundreds(long long number);`
	- `std::string in_english(long long number);`
- [x] Bankaccount
- [x] bob
	- `std::string hey(std::string phrase);`
- [x] chicken_coop
	- `positions_to_quantity(int number);`
- [x] prime_factors
	- `std::vector<long long int> of(long long int number);`
- [x] arcade
	- `class HighScores`
- [x] etl
	- `std::map<char, int> transform(const std::map<int, std::vector<char>>& old);`
- [x] sieve
	- `std::vector<int> primes(int n);`
- [x] troy
	- `void give_new_artifact(human&, const std::string&);`
	- `void exchange_artifacts(std::unique_ptr<artifact>&`
	- `std::unique_ptr<artifact>&);`
	- `void manifest_power(human&, const std::string&);`
	- `void use_power(human&, human&);`
	- `long power_intensity(const human& h);`
- [x] binary_search_tree
	- `class binary_tree`
- [x] rail_fence_cipher
	- `std::string encode(const std::string& plaintext, int num_rails);`
	- `std::string decode(const std::string& ciphertext, int num_rails);`
- [x] spiral_matrix
	- `std::vector<std::vector<uint32_t>> spiral_matrix(int size);`
- [x] sum_of_multiples
	- `int to(const std::vector<int>& bases, int level);`
- [x] robot_name
	- `class robot`
	- `bool validate_name(const std::string& name);`
- [x] date_independent
	- `class clock`
- [x] run_length_encoding
	- `std::string encode(const std::string& text);`
	- `std::string decode(const std::string& text);`
- [x] list_ops
	- `void append(std::vector<T>& list1, const std::vector<T>& list2);`
	- `std::vector<T> concat(const std::vector<std::vector<T>>& lists);`
	- `std::vector<T> filter(const std::vector<T>& list, Pred predicate);`
	- `size_t length(const std::vector<T>& list);`
	- `std::vector<T> map(const std::vector<T>& list, Func function);`
	- `Acc foldl(const std::vector<T>& list, Acc initial, Func function);`
	- `Acc foldr(const std::vector<T>& list, Acc initial, Func function);`
	- `std::vector<T> reverse(const std::vector<T>& list);`

## Prerequisites

To build and run this project, you need the following:

1. **Visual Studio**: Install Visual Studio with the C++ development workload.
2. **vcpkg**: Ensure `vcpkg` is installed and configured for dependency management.

## Getting Started

1. Clone the repository:
   ```sh
   git clone https://github.com/your-username/cpp_console_app_zero.git
   cd cpp_console_app_zero