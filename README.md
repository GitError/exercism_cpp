# Exercism C++ Solutions

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Exercises](https://img.shields.io/badge/exercises-100%2B-orange)

This repository contains my solutions to C++ exercises from [Exercism](https://exercism.org/), a platform for practicing and improving coding skills through interactive exercises.

## 📋 Overview

These solutions demonstrate various C++ concepts including:
- Object-oriented programming
- Algorithm implementation
- Template programming
- Standard Library usage
- Problem-solving techniques

## 🗂️ Structure

The repository is organized into namespaces, each representing a specific exercise or topic:
- Each exercise is implemented in `cpp_console_app_zero.cpp`
- Function declarations are provided in `cpp_console_app_zero.h`

## 🧩 Exercises

### String Operations

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **reverse_string** | Reverse a string | Reverse a string |
| **log_line** | Parse log messages | Parse message, level, and reformat logs |
| **acronym** | Create acronyms | acronym |
| **atbash_cipher** | Simple substitution cipher | Encode, decode |
| **rotational_cipher** | Caesar cipher | Rotate |
| **pangram** | Check if text uses all alphabet letters |Is pangram |
| **isogram** | Check for repeated letters | Is isogram |
| **scrabble_score** | Calculate Scrabble word score | Score  |
| **pig_latin** | Word transformation game | Translate |
| **run_length_encoding** | String compression | Encode and decode |
| **series** | Extract substrings | Slice |

### Number Systems & Math

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **raindrops** | Number to string conversion |Convert |
| **grains** | Chess board calculation | Calculate grains on chessboard squares |
| **binary** | Binary to decimal conversion | Convert to binary |
| **trinary** | Trinary to decimal conversion | Convert to decimal |
| **hexadecimal** | Hex to decimal conversion | Convert to hexadecimal |
| **difference_of_squares** | Mathematical operations | Square of sum vs sum of squares |
| **collatz_conjecture** | Sequence algorithm | Steps |
| **armstrong_numbers** | Number property checker | Is armstrong number |
| **perfect_numbers** | Classify numbers | Perfect, abundant, or deficient |
| **numbers_1** | Freelancer rates | Calculate daily/monthly rates |
| **loops_1** | Interest calculations | Calculate compound interest |

### Algorithms

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **hamming** | DNA distance calculation | Compute |
| **binary_search** | Efficient search algorithm | Find |
| **rail_fence_cipher** | Transposition cipher | Encoding and decoding with rails |
| **spiral_matrix** | Matrix generation | Spiral matrix |
| **sum_of_multiples** | Sum calculation | To |
| **sieve** | Prime number generation | primes |
| **nth_prime** | Prime number finder | Find Nth Prime |
| **prime_factors** | Prime factorization | Find prime of N |
| **largest_series_product** | Product in digits | Find largest product` |
| **two_bucket** | Water jug problem | Solution for classic algorithm problem |
| **Knapsack** | Combinatorial Optimization |Maximum Value calculation |

### Data Structures

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **grade_school** | Student database | Class for managing student roster |
| **simple_linked_list** | Linked list implementation | Basic data structure |
| **binary_search_tree** | Tree data structure | Binary tree implementation |
| **list_ops** | List operations | Filter, map, fold, and other operations |

### Object-Oriented Programming

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **space_age** | Age calculation | Calculate age on different planets |
| **robot_name** | Random name generation | Class for generating robot names |
| **date_independent** | Time handling | Clock implementation |
| **complex_numbers** | Complex number math | Class for complex number operations |
| **robot_simulator** | Robot movement | Robot position and direction simulation |
| **dnd_character** | Game character generation | Character stats for D&D |
| **anagram** | Word relationship finder | Class for detecting anagrams |
| **targets** | Object system | Class Alien implementation |

### Biological Computing

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **rna_transcription** | DNA to RNA conversion | Convert DNA to RNA sequences |
| **nucleotide_count** | DNA analysis | Count nucleotides in DNA sequence |
| **protein_translation** | RNA to protein | RNA codon to protein translation |

### Game Logic

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **darts** | Dart game scoring | Score dice combinations |
| **yacht** | Dice game scoring | Score dice combinations |
| **minesweeper** | Grid annotation | Add numbers to minesweeper grid |
| **triangle** | Shape classification | Determine triangle types |
| **food_chain** | Song generation | Generate lyrics programmatically |
| **beer_song** | Song generator | Create beer song verses |
| **kindergarten_garden** | Plant ownership | Link students to their plants |
| **secret_handshake** | Binary sequences | Convert numbers to action sequences |

### Electronics

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **resistor_color** | Color coding | Convert colors to resistor values |
| **resistor_color_duo** | Resistor value calculation | Two-color resistor calculation |
| **speedywagon** | Sensor system | Sensor data processing |

### Miscellaneous

| Exercise | Description | Functions |
|----------|-------------|-----------|
| **phone_number** | Number validation | Phone number parsing and formatting |
| **isbn_verifier** | Book number validation | Validate ISBN numbers |
| **luhn** | Validation algorithm | Credit card number validation |
| **bob** | Conversation responses | Generate responses to inputs |
| **say** | Number to text | Convert numbers to English text |
| **gigasecond** | Date calculation | Add one billion seconds to time |
| **pascals_triangle** | Mathematical pattern | Generate Pascal's triangle rows |
| **diamond** | ASCII art | Generate letter diamond pattern |
| **etl** | Data transformation | Transform legacy data formats |
| **vehicle_purchase** | Decision logic | Vehicle purchase helper functions |
| **marking_grades** | Grade calculation | Student grading system |
| **election** | Vote counting | Election result determination |
| **hellmath** | Permission system | User permission checking system |
| **star_map** | Enum usage | Space system classification |
| **heaven** | Vessel tracking | Vessel location and age checking |
| **lasagna_master** | Recipe handling | Scale and modify recipes |
| **arcade** | Score tracking | High score management system |
| **two_fer** | Simple substitution | String substitution function |
| **sublist** | List comparison | Compare relationship between lists |
| **troy** | Artifact management | Manage and power artifacts |
| **chicken_coop** | Quantity calculation | Convert positions to quantities |
| **parallel_letter_frequency** | Parallel computation | Calculate frequencies |
## 🛠️ Prerequisites

To build and run this project, you need:

1. **C++ Compiler**: A modern C++ compiler that supports C++17 or later
2. **Build System**: CMake 3.12 or later
3. **Visual Studio**: Visual Studio with the C++ development workload (Windows users)
4. **vcpkg**: For dependency management

## 🚀 Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/cpp_console_app_zero.git
   cd cpp_console_app_zero
   ```

2. Configure with CMake:
   ```bash
   mkdir build && cd build
   cmake ..
   ```

3. Build the project:
   ```bash
   cmake --build .
   ```

4. Run tests:
   ```bash
   ctest
   ```

## 📚 Learning Resources

- [Exercism C++ Track](https://exercism.org/tracks/cpp)
- [C++ Reference](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)

## 📝 License

This repository is licensed under the MIT License - see the LICENSE file for details.

## 🤝 Contributing

While this is primarily a personal learning repository, suggestions for improvement are welcome:

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Submit a pull request

---

<p align="center">Created with ❤️ for C++ and continuous learning</p>
