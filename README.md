# Exercism C++ Solutions

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![License](https://img.shields.io/badge/license-MIT-green)
![Exercises](https://img.shields.io/badge/exercises-100%2B-orange)
![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Tests](https://img.shields.io/badge/tests-passing-brightgreen)

This repository contains my solutions to C++ exercises from [Exercism](https://exercism.org/), a platform for practicing and improving coding skills through interactive exercises.

## 📋 Overview

These solutions demonstrate various C++ concepts including:
- Object-oriented programming
- Algorithm implementation
- Template programming
- Standard Library usage
- Problem-solving techniques

## 🗂️ Repository Structure

The repository follows a clean, organized structure:

```
cpp_console_app_zero/
├── include/                        # Header files (.h)
│   └── [namespace].h               # Exercise declarations
├── src/                            # Implementation files (.cpp)
│   ├── [namespace].cpp             # Exercise implementations
│   └── cpp_console_app_zero.cpp    # Main entry point
├── tests/                          # Test files
│   └── [namespace]_test.cpp        # Unit tests for exercises
├── CMakeLists.txt                  # CMake build configuration
├── .gitignore                      # Git ignore file
├── LICENSE                         # MIT license file
└── README.md                       # This documentation
```

Each exercise is implemented in its own namespace to prevent symbol collisions and promote code organization.

## 🧩 Exercises by Category

### String Operations

| Namespace | Description | Functions | Complexity |
|-----------|-------------|-----------|------------|
| **reverse_string** | Reverse a string | `Reverse` | O(n) |
| **log_line** | Parse log messages | `Parse`, `Reformat` | O(n) |
| **acronym** | Create acronyms from phrases | `Acronym` | O(n) |
| **atbash_cipher** | Substitution cipher implementation | `Encode`, `Decode` | O(n) |
| **rotational_cipher** | Caesar cipher with variable rotation | `Rotate` | O(n) |
| **pangram** | Check if text uses all alphabet letters | `IsPangram` | O(n) |
| **isogram** | Check for repeated letters | `IsIsogram` | O(n) |
| **scrabble_score** | Calculate Scrabble word score | `Score` | O(n) |
| **pig_latin** | Word transformation game | `Translate` | O(n) |
| **run_length_encoding** | String compression algorithm | `Encode`, `Decode` | O(n) |
| **series** | Extract consecutive substrings | `Slice` | O(n·m) |

### Number Systems & Mathematical Operations

| Namespace | Description | Functions | Complexity |
|-----------|-------------|-----------|------------|
| **raindrops** | Convert numbers to strings based on factors | `Convert` | O(1) |
| **grains** | Calculate exponential growth on chessboard | `Square`, `Total` | O(1) |
| **binary** | Binary to decimal conversion | `Convert` | O(n) |
| **trinary** | Trinary (base-3) to decimal conversion | `ToDecimal` | O(n) |
| **hexadecimal** | Hexadecimal to decimal conversion | `ToDecimal` | O(n) |
| **difference_of_squares** | Mathematical operations | `SquareOfSum`, `SumOfSquares` | O(n) |
| **collatz_conjecture** | Implementation of the Collatz sequence | `Steps` | O(log n) |
| **armstrong_numbers** | Check if number equals sum of its digits raised to power | `IsArmstrongNumber` | O(log n) |
| **perfect_numbers** | Classify numbers as perfect, abundant, or deficient | `Classify` | O(√n) |
| **numbers_1** | Freelancer rates calculator | `DailyRate`, `MonthlyRate`, `DaysInBudget` | O(1) |
| **loops_1** | Compound interest calculations | `InterestRate`, `AnnualBalanceUpdate`, `YearsBeforeDesiredBalance` | O(log n) |
| **all_your_base** | Convert between arbitrary number bases | `Convert` | O(n) |
| **zebra_puzzle** | Constraint satisfaction problems (CSPs) | `Solve` | O(n) |

### Algorithms & Problem Solving

| Namespace | Description | Functions | Complexity |
|-----------|-------------|-----------|------------|
| **hamming** | DNA distance calculation | `ComputeDistance` | O(n) |
| **binary_search** | Efficient search in sorted array | `Find`, `FindRecursive` | O(log n) |
| **rail_fence_cipher** | Transposition cipher algorithm | `Encode`, `Decode` | O(n) |
| **spiral_matrix** | Generate matrix with spiral pattern | `GenerateMatrix` | O(n²) |
| **sum_of_multiples** | Sum calculation with filtering | `To` | O(n) |
| **sieve** | Sieve of Eratosthenes implementation | `Primes` | O(n log log n) |
| **nth_prime** | Prime number finder | `FindNthPrime` | O(n log log n) |
| **prime_factors** | Prime factorization algorithm | `FindPrimeFactors` | O(√n) |
| **largest_series_product** | Maximize product in digit sequences | `FindLargestProduct` | O(n) |
| **two_bucket** | Water jug problem solution | `Solve` | O(m·n) |
| **knapsack** | Combinatorial optimization algorithm | `MaximumValue` | O(n·W) |
| **matching_brackets** | Validate nested brackets and braces | `CheckBalanced` | O(n) |
| **queen_attack** | Backtracking problem | `ChessBoard` class | O(n!) |

### Data Structures

| Namespace | Description | Functions | Complexity |
|-----------|-------------|-----------|------------|
| **grade_school** | Student database management | `Add`, `Roster`, `Grade` | O(log n) |
| **simple_linked_list** | Linked list implementation | `Push`, `Pop`, `Reverse`, `ToArray` | O(n) |
| **linked_list** | Linked list implementation | `LinkedList` class | O(n) |
| **binary_search_tree** | Tree data structure | `Insert`, `Search`, `InOrder`, `PreOrder`, `PostOrder` | O(log n) avg, O(n) worst |
| **list_ops** | Functional list operations | `Append`, `Concat`, `Filter`, `Length`, `Map`, `Foldl`, `Foldr`, `Reverse` | O(n) |
| **circular_buffer** | Circular Buffer Data Type | Template `circular_buffer` class  | O(n) |

### Object-Oriented Programming

| Namespace | Description | Classes/Functions | Features |
|-----------|-------------|-------------------|----------|
| **space_age** | Calculate age on different planets | `SpaceAge` class | Encapsulation, conversion methods |
| **robot_name** | Random name generator with constraints | `Robot` class | Static member management, PRNG |
| **date_independent** | Time handling without date libraries | `Clock` class | Operator overloading, equality comparison |
| **complex_numbers** | Complex number mathematics | `ComplexNumber` class | Comprehensive math operations, operator overloading |
| **robot_simulator** | Robot movement simulation | `Robot`, `Direction` classes | State management, command interpretation |
| **dnd_character** | Game character generation | `Character` class | Random stat generation, derived attributes |
| **anagram** | Word relationship detection | `Anagram` class | Matching algorithms, filtering |
| **targets** | Object system demonstration | `Alien` class hierarchy | Inheritance, polymorphism |

### Biological Computing

| Namespace | Description | Functions | Features |
|-----------|-------------|-----------|----------|
| **rna_transcription** | DNA to RNA conversion | `ToRNA` | Nucleotide mapping, error handling |
| **nucleotide_count** | DNA analysis | `Count`, `NucleotideCounts` | Frequency analysis, validation |
| **protein_translation** | RNA codon to protein translation | `Proteins` | Codon lookup, sequence processing |

### Game Logic & Simulation

| Namespace | Description | Functions | Features |
|-----------|-------------|-----------|----------|
| **darts** | Dart game scoring | `Score` | Distance calculation, tiered scoring |
| **yacht** | Dice game scoring (like Yahtzee) | `Score` | Category evaluation, pattern matching |
| **minesweeper** | Grid annotation algorithm | `Annotate` | 2D grid processing, neighbor counting |
| **triangle** | Geometric shape classification | `Kind`, `IsTriangle` | Validation, type determination |
| **food_chain** | Song generation | `Verse`, `Verses` | Recursive pattern generation |
| **beer_song** | Song generator | `Verse`, `Sing` | Template-based text generation |
| **kindergarten_garden** | Plant ownership tracking | `Plants` | Data mapping, lookup |
| **secret_handshake** | Binary sequence interpreter | `Commands` | Bitwise operations |

### Electronics & Systems

| Namespace | Description | Functions | Features |
|-----------|-------------|-----------|----------|
| **resistor_color** | Resistor color code translator | `ColorCode`, `Colors` | Lookup tables, enum usage |
| **resistor_color_duo** | Two-band resistor calculation | `Value` | Color combination interpretation |
| **speedywagon** | Sensor system simulation | `Position`, `Speed`, `DistanceTravelled` | Data integration, time-series analysis |

### Miscellaneous Utilities

| Namespace | Description | Functions | Features |
|-----------|-------------|-----------|----------|
| **phone_number** | Phone number validation and formatting | `Clean`, `Format` | Regular expressions, validation rules |
| **leap** | Leap year validation | `IsLeapYear` | Conditional logic, calendrical calculations |
| **isbn_verifier** | Book number validation | `IsValid` | Checksum algorithm, format validation |
| **luhn** | Credit card validation algorithm | `Valid` | Checksum calculation, input sanitization |
| **bob** | Conversation response simulation | `Hey` | Text analysis, state-based responses |
| **say** | Number to text converter | `Say` | Number decomposition, text composition |
| **gigasecond** | Date calculation | `AdvanceTime` | Time manipulation, large integer handling |
| **pascals_triangle** | Mathematical pattern generator | `Rows`, `Row` | Combinatorial calculations |
| **diamond** | ASCII art generator | `MakeDiamond` | Pattern generation, string manipulation |
| **etl** | Data transformation utility | `Transform` | Data structure conversion |
| **vehicle_purchase** | Decision logic simulator | `NeedsLicense`, `ChooseVehicle`, `CalculateResellPrice` | Conditional branching, depreciation calculation |
| **marking_grades** | Student grading system | `Round`, `LetterGrade`, `PassFail` | Grade computation, threshold application |
| **election** | Vote counting and analysis | `VoteCount`, `FindWinner` | Map reduction, plurality determination |
| **hellmath** | Permission system | `CheckPermission`, `GrantPermission` | Bitwise operations, permission modeling |
| **star_map** | Space classification | `StarType`, `SpaceRegion` classes | Enum implementation, object classification |
| **heaven** | Vessel tracking system | `TrackLocation`, `CheckAge` | Geospatial analysis, age verification |
| **lasagna_master** | Recipe management | `PreparationTime`, `Quantities`, `AddSecretIngredient` | Recipe scaling, ingredient substitution |
| **arcade** | Score tracking system | `GetHighScores`, `AddPlayerScore` | Leaderboard management, score ordering |
| **two_fer** | String substitution | `TwoFer` | Default parameters, string formatting |
| **sublist** | List relationship comparison | `Relation` | List analysis, pattern matching |
| **troy** | Artifact management system | `RegisterArtifact`, `PowerLevel` | Resource tracking, power calculation |
| **chicken_coop** | Quantity calculator | `PositionToQuantity` | Mapping algorithms, lookup optimization |
| **parallel_letter_frequency** | Concurrent text analysis | `FrequencyMap` | Multithreading, synchronization, frequency analysis |
| **crypto_square** | Classical cryptography | `Normalize`, `GetSquareDimensions`, `Cipher` | Text normalization, matrix operations |
| **word_count** | Classic toy problem | `Words` | Cound frequencies of simple words, contractions, numbers, etc. |
| **roman_numerals** | Utility | `Convert` | Convert int into roman umerals |
| **roman_numerals** | Utility | `scheduler` class | Create meetup utility |

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

### Using the Solutions

Each solution is implemented as a separate namespace, making it easy to include and use in your own projects:

```cpp
#include "reverse_string.h"

int main() {
    std::string original = "Hello, World!";
    std::string reversed = reverse_string::Reverse(original);
    std::cout << reversed << std::endl;  // Outputs: "!dlroW ,olleH"
    return 0;
}
```

## 📚 Learning Resources

- [Exercism C++ Track](https://exercism.org/tracks/cpp)
- [C++ Reference](https://en.cppreference.com/)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [Effective Modern C++](https://www.oreilly.com/library/view/effective-modern-c/9781491908419/) by Scott Meyers
- [A Tour of C++](https://www.stroustrup.com/tour2.html) by Bjarne Stroustrup

## 📋 Coding Standards

This project follows these coding standards:

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- Variable names use camelCase
- Function names use PascalCase
- Constants use UPPER_SNAKE_CASE
- Class members prefixed with m_
- Comprehensive comments in a Doxygen-compatible format

---

<p align="center">
	<img src="https://img.shields.io/badge/Made%20with-Modern%20C%2B%2B-blue" alt="Made with Modern C++">
</p>
